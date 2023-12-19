#ifndef __LEX__
#define __LEX__

#include "tokens.h"

/* Definiciones para el analizador léxico. */
#define LEXER_OK 1
#define MAX_NUM_LITERAL 0x80000000
#define DEFAULT_NUM "0"
#define MAX_ID_LENGHT 16
#define STRING_PLACEHOLDER "\"If you see this, it means there was a badly formatted string on the input.\""

extern int lexer_errors;
extern FILE *lexer_file;

/* Array para mapear tokens con sus nombres. */
static const char * const token_name[] = {
	
	[WHITESPACE] = "WHITESPACE",
	[LINE_COMMENT] = "LINE_COMMENT",
	[MULTILINE_COMMENT] = "MULTILINE_COMMENT",

	[VOID] = "VOID",
	[VAR] = "VAR",
	[CONST] = "CONST",
	[IF] = "IF",
	[ELSE] = "ELSE",
	[WHILE] = "WHILE",
	[PRINT] = "PRINT",
	[READ] = "READ",
	[DO] = "DO",
	[FOR] = "FOR",

	[LTE] = "LTE",
	[GTE] = "GTE",
	[LT] = "LT",
	[GT] = "GT",
	[EQ] = "EQ",
	[NEQ] = "NEQ",
	
	[LOGICAL_NEG] = "LOGICAL_NEG",

	[SEMICOLON] = "SEMICOLON",
	[COMMA] = "COMMA",
	[PLUS] = "PLUS",
	[MINUS] = "MINUS",
	[MULT] = "MULT",
	[DIVIDE] = "DIVIDE",
	[ASSIGN] = "ASSIGN",
	[LPARENTHESIS] = "LPARENTHESIS",
	[RPARENTHESIS] = "RPARENTHESIS",
	[LBRACE] = "LBRACE",
	[RBRACE] = "RBRACE",

	[NUM] = "NUM",
	[ID] = "ID",
	[STRING] = "STRING",

	[BAD_NUM] = "BAD_NUM",
	[BAD_ID] = "BAD_ID",
	[BAD_STRING] = "BAD_STRING",
	[PARTIAL_STRING] = "PARTIAL_STRING",
	[PARTIAL_COMMENT] = "PARTIAL_COMMENT",
	[UNRECOGNIZED] = "UNRECOGNIZED",
};

static const char * const lexer_error_msg[] = {

	[BAD_NUM] = "Lexer error! On line %d, the numeric literal %s is out of range (-2^31, 2^31-1).\n",
	[BAD_ID] = "Lexer error! On line %d, the identifier %s exceeds the maximum allowed length of 16 characters.\n",
	[BAD_STRING] = "Lexer error! On line %d, there is a string badly formatted.\n",
	[PARTIAL_STRING] = "Lexer error! On line %d the string is not closed.\n",
	[PARTIAL_COMMENT] = "Lexer error! On line %d, the comment is not closed.\n",
	[UNRECOGNIZED] = "Lexer error! On line %d, the string %s could not be recognized.\n",
};

#endif