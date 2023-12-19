%{

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "lex.h"
#include "master.h"
#include "tokens.h"

enum yytokentype lexer_pass			(enum yytokentype token);
enum yytokentype number_pass		(void);
enum yytokentype string_pass		(void);
enum yytokentype identifier_pass	(void);

void lexer_inform(enum yytokentype token);
void lexer_debug(enum yytokentype token);

int lexer_errors = 0;
FILE *lexer_file 	= NULL;

static char *unmatched_comment = NULL;
void handle_bad_comment(void);

static char *unmatched_string = NULL;
void handle_bad_string(void);

enum yytokentype last_token = YYEOF;
enum yytokentype previous_last_token = YYEOF;

%}

%option yylineno
%option warn

%x COMMENT_MODE
%x STRING_MODE

integer				[0-9]+
identifier			([a-zA-Z]|_)([a-zA-Z0-9]|_)*

comment_init		"/*"
comment_end 		([^*]|[*]+[^*/])*[*]+"/"
comment_any			(.|{whitespace})

string_init			\"
string_end			([^"\\\n]|\\(.|[\n]))*\"
string_any			[^"]

whitespace      	[ \t\n\r\f\v]+
line_comment		"//"(.*)

error				[^a-zA-Z0-9_/*+\-=;,"(){}\t\n\r\f\v<>! ]+

%%
{whitespace}		{ lexer_inform(WHITESPACE);			};
{line_comment}		{ lexer_inform(LINE_COMMENT);		};

{comment_init}					{ BEGIN COMMENT_MODE; yymore();						};
<COMMENT_MODE>{comment_end}		{ BEGIN INITIAL; lexer_inform(MULTILINE_COMMENT);	};
<COMMENT_MODE>{comment_any}		{ handle_bad_comment(); 							};

void				{ return lexer_pass(VOID); 			};
var					{ return lexer_pass(VAR); 			};
const				{ return lexer_pass(CONST); 		};
if					{ return lexer_pass(IF); 			};
else				{ return lexer_pass(ELSE); 			};
while				{ return lexer_pass(WHILE); 		};
print				{ return lexer_pass(PRINT);			};
read				{ return lexer_pass(READ);			};
for					{ return lexer_pass(FOR);			};
do					{ return lexer_pass(DO);			};
"<="				{ return lexer_pass(LTE);			};
">="				{ return lexer_pass(GTE);			};     
"<"					{ return lexer_pass(LT);			};
">"					{ return lexer_pass(GT);			};
"=="				{ return lexer_pass(EQ);			};
"!="				{ return lexer_pass(NEQ);			};
"!"					{ return lexer_pass(LOGICAL_NEG);	};
";"					{ return lexer_pass(SEMICOLON);		};
","					{ return lexer_pass(COMMA);			};
"+"					{ return lexer_pass(PLUS);			};
"-"					{ return lexer_pass(MINUS);			};
"*"					{ return lexer_pass(MULT);			};
"/"					{ return lexer_pass(DIVIDE);		};
"="					{ return lexer_pass(ASSIGN);		};
"("					{ return lexer_pass(LPARENTHESIS);	};
")"					{ return lexer_pass(RPARENTHESIS);	};
"{"					{ return lexer_pass(LBRACE);		};
"}"					{ return lexer_pass(RBRACE);		};
{integer}			{ return number_pass();				};
{identifier}		{ return identifier_pass();			};

{string_init}				{ BEGIN STRING_MODE; yymore(); 			};
<STRING_MODE>{string_end}	{ BEGIN INITIAL; return string_pass(); 	};
<STRING_MODE>{string_any}	{ handle_bad_string(); 					};

{error}				{ lexer_inform(UNRECOGNIZED);		};
%%

enum yytokentype lexer_pass(enum yytokentype token)
{
	lexer_inform(token);
	return token;
};

enum yytokentype number_pass(void)
{

	errno = OK;
	enum yytokentype token = NUM;
	unsigned long num = strtol(yytext, (char**)NULL, 10);

	if (errno != OK || num > MAX_NUM_LITERAL || (last_token !=MINUS && num > MAX_NUM_LITERAL-1) ||
		(
			last_token == MINUS && 
			previous_last_token != ASSIGN &&
			previous_last_token != PLUS &&
			previous_last_token != MINUS &&
			previous_last_token != MULT &&
			previous_last_token != DIVIDE &&
			previous_last_token != RPARENTHESIS &&
			previous_last_token != LTE &&
			previous_last_token != GTE &&
			previous_last_token != LT &&
			previous_last_token != GT &&
			previous_last_token != EQ &&
			previous_last_token != NEQ &&
			previous_last_token != LOGICAL_NEG &&
			num > MAX_NUM_LITERAL-1
		)
	)
	{
		token = BAD_NUM;
		yylval.lexema = strdup(DEFAULT_NUM);
	}
	else
		yylval.lexema = strdup(yytext);
		
	assert(yylval.lexema != NULL);

	lexer_inform(token);
	return NUM;
};

enum yytokentype identifier_pass(void)
{
	enum yytokentype token = ID;

	if (yyleng > MAX_ID_LENGHT)
		token = BAD_ID;
	
	yylval.lexema = strdup(yytext);

	assert(yylval.lexema != NULL);

	lexer_inform(token);
	return ID;
};

enum yytokentype string_pass(void)
{	

	if (unmatched_string != NULL)
	{
		yylval.lexema = strdup(STRING_PLACEHOLDER);
		assert(yylval.lexema != NULL);
		lexer_inform(BAD_STRING);
		return STRING;
	}

	yylval.lexema = (char *) malloc(yyleng + 1);

	assert(yylval.lexema != NULL);

	int index_yylval = 0;
	for (int i = 0; i < yyleng; i++)
	{
		if (yytext[i] == '\\' && yytext[i+1] == '\n')
			i += 1;
		else
		{
			yylval.lexema[index_yylval] = yytext[i];
			index_yylval += 1;
		}
	}
	yylval.lexema[index_yylval] = '\0';

	lexer_inform(STRING);
	return STRING;
};

void lexer_inform(enum yytokentype token)
{
	if (debug_level & DBG_LEXER)
		lexer_debug(token);

	switch (token)
	{	
		case BAD_NUM:
		case BAD_ID:
		case UNRECOGNIZED:
			lexer_errors+=1;
			fprintf(error_file, lexer_error_msg[token], yylineno, yytext);
			break;

		case BAD_STRING:
		case PARTIAL_STRING:
		case PARTIAL_COMMENT:
			lexer_errors+=1;
			fprintf(error_file, lexer_error_msg[token], yylineno);
			break;
	}

	if (unmatched_string != NULL) free(unmatched_string);
	unmatched_string = NULL;
	if (unmatched_comment != NULL) free(unmatched_comment);
	unmatched_comment = NULL;

	if (token != WHITESPACE && token != LINE_COMMENT && token != MULTILINE_COMMENT)
	{
		previous_last_token = last_token;
		last_token = token;
	}
}

void lexer_debug(enum yytokentype token)
{
	switch (token)
	{
		case WHITESPACE:
			fprintf(lexer_file, "%s", yytext);
			break;

		case NUM:
		case BAD_NUM:
		case STRING:
		case BAD_STRING:
		case ID:
		case BAD_ID:	
			fprintf(lexer_file, "%s(%s) ", token_name[token], yylval.lexema);
			if (debug_level == DBG_LEXER)
			{	
				free(yylval.lexema);
				yylval.lexema = NULL;
			}
			break;

		case LINE_COMMENT:
		case MULTILINE_COMMENT:
		case UNRECOGNIZED:
			fprintf(lexer_file, "%s(%s) ", token_name[token], yytext);
			break; 

		case PARTIAL_STRING:
			fprintf(lexer_file, "%s(%s) ", token_name[token], unmatched_string);
			break;
		case PARTIAL_COMMENT:
			fprintf(lexer_file, "%s(%s) ", token_name[token], unmatched_comment);
			break;

		default:
			fprintf(lexer_file, "%s ", token_name[token]);
			break;
	}
};

void handle_bad_comment(void) 
{	
	yymore();
					
	if (unmatched_comment != NULL) 
		free(unmatched_comment); 
	unmatched_comment = strdup(yytext);
	assert(unmatched_comment != NULL);
}

void handle_bad_string(void) 
{	
	yymore();
					
	if (unmatched_string != NULL) 
		free(unmatched_string); 
	unmatched_string = strdup(yytext);
	assert(unmatched_string != NULL);
}

int yywrap(void) {

	if (YYSTATE == COMMENT_MODE)
		lexer_inform(PARTIAL_COMMENT);

	if (YYSTATE == STRING_MODE)
		lexer_inform(PARTIAL_STRING);

	yylex_destroy();
	return LEXER_OK;
}