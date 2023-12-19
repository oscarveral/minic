%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lex.h"
#include "syn.h"
#include "sem.h"
#include "master.h"
#include "codegen.h"

extern int yylex(void); 
extern char *yytext;
extern int yylineno;

int syntax_errors = 0;

FILE *syntax_file = NULL;

void semantic_inform(char *lexema, semantic_action_t action);
void semantic_debug(void);

ListaC codegen_num(char *lexema);
ListaC codegen_id(char *lexema);
ListaC codegen_expr(ListaC llist, operation_t operacion, ListaC rlist);
ListaC codegen_unary(operation_t operacion, ListaC list);
ListaC codegen_read(char *lexema);
ListaC codegen_multiread(ListaC list, char *lexema);
ListaC codegen_print_str(char *lexema);
ListaC codegen_print_num(ListaC list);
ListaC codegen_assign(char *lexema, ListaC list);
ListaC codegen_if(ListaC condition, ListaC statement);
ListaC codegen_if_else(ListaC condition, ListaC first_statements, ListaC second_statements);
ListaC codegen_while(ListaC condition, ListaC statement);
ListaC codegen_do_while(ListaC statements, ListaC condition);
ListaC codegen_for(char *lexema, ListaC expresion, ListaC condition, ListaC statements);
ListaC codegen_for_extended(char *lexema, ListaC expresion, ListaC condition, ListaC increment, ListaC statements);
ListaC codegen_program(ListaC declarations, ListaC statements);
ListaC codegen_data(void);

void syntax_inform(syntax_reduction_t red);
void syntax_debug(syntax_reduction_t red);
void yyerror(char const *s);

%}

%code requires 
{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>

	#include "lex.h"
	#include "syn.h"
	#include "sem.h"
	#include "master.h"
	#include "codegen.h"
}

%union 
{
	char *lexema;
	ListaC codigo;
}

%token WHITESPACE LINE_COMMENT MULTILINE_COMMENT

%token VOID VAR CONST IF ELSE WHILE PRINT READ DO FOR

%token SEMICOLON COMMA ASSIGN LPARENTHESIS RPARENTHESIS LBRACE RBRACE

%token BAD_NUM BAD_ID BAD_STRING PARTIAL_STRING PARTIAL_COMMENT UNRECOGNIZED

%token <lexema> NUM STRING ID

%left LTE GTE LT GT EQ NEQ
%left PLUS MINUS
%left MULT DIVIDE
%nonassoc UMINUS LOGICAL_NEG 

%expect 1

%start programa

%type <codigo> expression read_list print_item print_list statement statement_list asig identifier_list declarations

%%

programa        :   { tablaSimbolos = creaLS(); registros=crea_registros(); } VOID ID { free($3); } LPARENTHESIS RPARENTHESIS LBRACE declarations statement_list RBRACE { syntax_inform(PROGRAMA); semantic_debug(); codigo_generado = codegen_program($8, $9); libera_registros(registros); }
				;
declarations    :   { syntax_inform(EMPTY_DECL); $$ = creaLC(); }
				|	declarations VAR { tipoSemantico = VARIABLE; } identifier_list SEMICOLON { syntax_inform(VAR_DECL); $$ = concatenaSeguraLC($1, $4); }
				|	declarations CONST { tipoSemantico = CONSTANTE; } identifier_list SEMICOLON { syntax_inform(CONST_DECL); $$ = concatenaSeguraLC($1, $4);  }
				;
identifier_list	:	asig { syntax_inform(DECLARATION_RED); $$ = $1; }
				|	identifier_list COMMA asig { syntax_inform(MULTIPLE_DECLARATION); $$ = concatenaSeguraLC($1, $3);  }
				|	identifier_list COMMA error { syntax_inform(MULTIPLE_DECLARATION_ERROR); $$ = $1; yyerrok; }
				|	error { syntax_inform(DECLARATION_ERROR); $$ = creaLC(); yyerrok; yyclearin; }
				;
asig			:	ID { syntax_inform(ASIG_DECL); semantic_inform($1, DECLARATION); free($1); $$  = creaLC(); }
				|	ID { semantic_inform($1, INITIALIZATION); } ASSIGN expression { syntax_inform(ASIG_INIT); $$ = codegen_assign($1, $4); }
				;
statement_list	:	{ syntax_inform(EMPTY_STMT_LIST); $$ = creaLC(); }
				|	statement_list statement { syntax_inform(STMT_LIST); $$ = concatenaSeguraLC($1, $2); }
				;
statement		: 	ID { semantic_inform($1, ASSIGNATION); } ASSIGN expression SEMICOLON { syntax_inform(ASSIGN_STMT); $$ = codegen_assign($1, $4); }
				|	LBRACE statement_list RBRACE { syntax_inform(BRACES_STMT); $$ = $2; }
				|	IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement { syntax_inform(IF_ELSE_STMT); $$ = codegen_if_else($3, $5, $7); }
				|	IF LPARENTHESIS expression RPARENTHESIS statement { syntax_inform(IF_STMT); $$ = codegen_if($3, $5); }
				|	WHILE LPARENTHESIS expression RPARENTHESIS statement { syntax_inform(WHILE_STMT); $$ = codegen_while($3, $5); }
				|	DO statement WHILE LPARENTHESIS expression RPARENTHESIS { syntax_inform(DO_WHILE_STMT); $$ = codegen_do_while($2, $5); }
				|	FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression SEMICOLON expression RPARENTHESIS statement { syntax_inform(FOR_EXT_STMT); semantic_inform($3, ASSIGNATION); $$ = codegen_for_extended($3, $5, $7, $9, $11); }
				|	FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression RPARENTHESIS statement { syntax_inform(FOR_STMT); semantic_inform($3, ASSIGNATION); $$ = codegen_for($3, $5, $7 ,$9); }
				|	PRINT print_list SEMICOLON { syntax_inform(PRINT_STMT); $$ = $2; }
				|	READ read_list SEMICOLON { syntax_inform(READ_STMT); $$ = $2; }
				;
print_list		:	print_item { syntax_inform(PRINT_ITEM_RED); $$ = $1; }
				|	print_list COMMA print_item { syntax_inform(MULTIPLE_PRINT); $$ = concatenaSeguraLC($1, $3); }
				|	print_list COMMA error { syntax_inform(MULTIPLE_PRINT_FORMAT_ERROR); $$ = $1; yyerrok; }
				|	error { syntax_inform(PRINT_FORMAT_ERROR); $$ = creaLC() ; yyerrok; }
				;
print_item		:	expression { syntax_inform(PRINT_EXPR); $$ = codegen_print_num($1); }
				|	STRING { syntax_inform(PRINT_ITEM); semantic_inform($1, STRING_SYMBOL); $$ = codegen_print_str($1); }
				;
read_list		:	ID { syntax_inform(SINGLE_READ); semantic_inform($1, ASSIGNATION); $$ = codegen_read($1); }
				|	read_list COMMA ID { syntax_inform(MULTIPLE_READ); semantic_inform($3, ASSIGNATION); $$ = codegen_multiread($1, $3); }
				|	read_list COMMA error { syntax_inform(MULTIPLE_READ_FORMAT_ERROR); $$ = $1 ; yyerrok; }
				|	error { syntax_inform(READ_FORMAT_ERROR); $$ = creaLC(); yyerrok; }
				;
expression		:	expression LTE expression { syntax_inform(LTE_EXPR); $$ = codegen_expr($1, SLE, $3); }
				|	expression GTE expression { syntax_inform(GTE_EXPR); $$ = codegen_expr($1, SGE, $3); }
				|	expression LT expression { syntax_inform(LT_EXPR); $$ = codegen_expr($1, SLT, $3); }
				|	expression GT expression { syntax_inform(GT_EXPR); $$ = codegen_expr($1, SGT, $3); }
				|	expression EQ expression { syntax_inform(EQ_EXPR); $$ = codegen_expr($1, SEQ, $3); }
				|	expression NEQ expression { syntax_inform(NEQ_EXPR); $$ = codegen_expr($1, SNE, $3); }
				|	expression PLUS expression { syntax_inform(PLUS_EXPR); $$ = codegen_expr($1, ADD, $3); }
				|	expression MINUS expression { syntax_inform(MINUS_EXPR); $$ = codegen_expr($1, SUB, $3); }
				|	expression MULT expression { syntax_inform(MULT_EXPR); $$ = codegen_expr($1, MUL, $3); }
				|	expression DIVIDE expression { syntax_inform(DIV_EXPR); $$ = codegen_expr($1, DIV, $3); }
				|	MINUS expression %prec UMINUS { syntax_inform(UMINUS_EXPR); $$ = codegen_unary(NEG, $2); }
				|	LOGICAL_NEG expression { syntax_inform(NEG_EXPR); $$ = codegen_unary(NOT, $2); }
				|	LPARENTHESIS expression RPARENTHESIS { syntax_inform(PAREN_EXPR); $$ = $2; } 
				|	NUM { syntax_inform(NUM_EXPR); $$ = codegen_num($1); }
				|	ID { syntax_inform(ID_EXPR); semantic_inform($1, USE); $$ = codegen_id($1); }
				;
%%

void semantic_inform(char *lexema, semantic_action_t action)
{
	switch(action)
	{
		case DECLARATION:
			if (perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[DOUBLE_DECLARATION], yylineno, lexema);
			}
			else
			{
				añadeEntrada(tablaSimbolos, lexema, tipoSemantico, false);
				if (debug_level & WARNINGS)
					fprintf(error_file, semantic_error_msg[WARN_NO_INITIALIZED], yylineno, lexema);
			}
			break;

		case INITIALIZATION:
			if (perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[DOUBLE_DECLARATION], yylineno, lexema);
			}
			else
				añadeEntrada(tablaSimbolos, lexema, tipoSemantico, true);
			
			break;

		case ASSIGNATION:
			if (!perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[UNDECLARED], yylineno, lexema);
			}
			else if (esConstante(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[CONST_ASSIGN], yylineno, lexema);
			}
			break;

		case USE:
			if (!perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[UNDECLARED], yylineno, lexema);
			}
			break;

		case STRING_SYMBOL:
			if (!perteneceTablaS(tablaSimbolos, lexema))
				añadeEntrada(tablaSimbolos, lexema, CADENA, true);
			
			break;

		default:
			abort();
			break;
	}
}

void semantic_debug(void)
{
	if (debug_level & DBG_SEMANTIC) 
		imprimirTablaS(tablaSimbolos, semantic_file);
}

ListaC codegen_num(char *lexema)
{
	int res = reserva_registro(registros);
	if (res == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion operation = { 
		.op = operation_str[LOAD_INMEDIATE], 
		.res = registros_str[res],
		.arg1 = lexema,
		.arg2 = NULL
	};
	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, res);

	return codigo;
}

ListaC codegen_id(char *lexema)
{
	int res = reserva_registro(registros);
	if (res == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion operation = { 
		.op = operation_str[LOAD_WORD], 
		.res = registros_str[res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL
	};
	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, res);

	free(lexema);
	return codigo;
}

ListaC codegen_expr(ListaC llist, operation_t operacion, ListaC rlist)
{
	if (codegen_errors != 0)
	{
		if (llist != NULL) liberaCompletaLC(llist);
		if (rlist != NULL) liberaCompletaLC(rlist);
		return NULL;
	}

	ListaC codigo = creaLC();

	int llist_res = recuperaResLC(llist);
	int rlist_res = recuperaResLC(rlist);
	 
	concatenaLC(codigo, llist);
	concatenaLC(codigo, rlist);

	Operacion operation;
	operation.res = registros_str[llist_res];
	operation.arg1 = registros_str[llist_res];
	operation.arg2 = registros_str[rlist_res];

	switch(operacion)
	{
		case ADD:
		case SUB:
		case MUL:
		case DIV:
		case SEQ:
		case SGE:
		case SGT:
		case SLE:
		case SLT:
		case SNE:
			operation.op = operation_str[operacion];
			break;

		default:
			abort();
			break;
	}

	insertaLC(codigo, finalLC(codigo), operation);

	guardaResLC(codigo, llist_res);
	libera_registro(registros, rlist_res);

	liberaLC(llist);
	liberaLC(rlist);

	return codigo;	
}

ListaC codegen_unary(operation_t operacion, ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		return NULL;
	}

	ListaC codigo = creaLC();

	int list_res = recuperaResLC(list);

	concatenaLC(codigo, list);

	Operacion operation;
	operation.res = registros_str[list_res];
	operation.arg1 = registros_str[list_res];
	operation.arg2 = NULL;

	switch(operacion)
	{
		case NEG:
			operation.op=operation_str[NEG];
			break;

		case NOT:
			operation.op=operation_str[NOT];
			operation.arg2=ZERO_REGISTER;
			break;

		default:
			abort();
			break;
	}

	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, list_res);

	liberaLC(list);

	return codigo;
}

ListaC codegen_read(char *lexema)
{
	if (codegen_errors != 0)
	{
		free(lexema);
		return NULL;
	}
	ListaC codigo = creaLC();

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(READ_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = SYSCALL_REGISTER,
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	free(lexema);
	return codigo;
}

ListaC codegen_multiread(ListaC list, char *lexema)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		free(lexema);
		return NULL;
	}

	ListaC codigo = list;

	ListaC lectura = codegen_read(lexema);

	concatenaLC(codigo, lectura);

	liberaLC(lectura);

	return codigo;
}

ListaC codegen_print_str(char *lexema)
{
	if (codegen_errors != 0)
	{
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(PRINT_STR_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	Operacion syscall_arg = {
		.op = operation_str[LOAD_ADDRESS],
		.res = SYSCALL_ARG_REGISTER,
		.arg1 = genera_str(recupera_valor(tablaSimbolos, lexema)),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_arg);
	
	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	free(lexema);

	return codigo;
}

ListaC codegen_print_num(ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		return NULL;
	}

	ListaC codigo = list;

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(PRINT_NUM_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	int list_res = recuperaResLC(list);

	Operacion syscall_arg = {
		.op = operation_str[MOVE],
		.res = SYSCALL_ARG_REGISTER,
		.arg1 = registros_str[list_res],
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_arg);
	
	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	libera_registro(registros, list_res);
	
	return codigo;
}

ListaC codegen_assign(char *lexema, ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		free(lexema);
		return NULL;
	}

	ListaC codigo = list;

	int list_res = recuperaResLC(list);

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[list_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	libera_registro(registros, list_res);

	free(lexema);
	return codigo;
}

ListaC codegen_if(ListaC condition, ListaC statement)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statement != NULL) liberaCompletaLC(statement);
		return NULL;
	}

	ListaC codigo = condition;

	int list_res = recuperaResLC(condition);

	char *etiqueta_salto = genera_etiqueta();
	char *etiqueta_et_salto = genera_etiqueta_et();

	Operacion comparar = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_salto,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), comparar);
	concatenaLC(codigo, statement);

	Operacion etiqueta = {
		.op = etiqueta_et_salto,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), etiqueta);

	liberaLC(statement);

	libera_registro(registros, list_res);

	return codigo;
}

ListaC codegen_if_else(ListaC condition, ListaC first_statements, ListaC second_statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (first_statements!= NULL) liberaCompletaLC(first_statements);
		if (second_statements != NULL) liberaCompletaLC(second_statements);
		return NULL;
	}

	ListaC codigo = condition;

	int list_res = recuperaResLC(condition);

	char *etiqueta_else = genera_etiqueta();
	char *etiqueta_et_else = genera_etiqueta_et();
	char *etiqueta_fin = genera_etiqueta();
	char *etiqueta_et_fin = genera_etiqueta_et();

	Operacion comparar = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_else,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), comparar);

	concatenaLC(codigo, first_statements);

	Operacion salto = {
		.op = operation_str[BRANCH],
		.res = etiqueta_fin,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	Operacion et_else = {
		.op = etiqueta_et_else,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_else);

	concatenaLC(codigo, second_statements);

	Operacion et_fin = {
		.op = etiqueta_et_fin,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_fin);

	libera_registro(registros, list_res);

	liberaLC(first_statements);
	liberaLC(second_statements);
	
	return codigo;
}

ListaC codegen_while(ListaC condition, ListaC statement)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statement!= NULL) liberaCompletaLC(statement);
		return NULL;
	}
	
	ListaC codigo = creaLC();

	int list_res = recuperaResLC(condition);

	char *etiqueta_while = genera_etiqueta();
	char *etiqueta_et_while = genera_etiqueta_et();
	char *etiqueta_fin = genera_etiqueta();
	char *etiqueta_et_fin = genera_etiqueta_et();

	Operacion et_while = {
		.op = etiqueta_et_while,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_while);

	concatenaLC(codigo, condition);

	Operacion salto_fin = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_fin,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_fin);

	concatenaLC(codigo,statement);

	Operacion iterar = {
		.op = operation_str[BRANCH],
		.res = etiqueta_while,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), iterar);

	Operacion et_fin = {
		.op = etiqueta_et_fin,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_fin);

	libera_registro(registros, list_res);

	liberaLC(condition);
	liberaLC(statement);

	return codigo;
}

ListaC codegen_do_while(ListaC statements, ListaC condition)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statements != NULL) liberaCompletaLC(statements);
		return NULL;
	}
	ListaC codigo = creaLC();

	int list_res = recuperaResLC(condition); 

	char *etiqueta_et_while = genera_etiqueta_et();
	char *etiqueta_while = genera_etiqueta();

	Operacion etiqueta = {
		.op = etiqueta_et_while,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), etiqueta);

	concatenaLC(codigo, statements);
	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_while,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, list_res);

	liberaLC(statements);
	liberaLC(condition);

	return codigo;
}

ListaC codegen_for(char *lexema, ListaC expresion, ListaC condition, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (expresion != NULL) liberaCompletaLC(expresion);
		if (statements != NULL) liberaCompletaLC(statements);
		free(lexema);
		return NULL;
	}

	ListaC codigo = expresion;

	int reg_tmp = reserva_registro(registros);
	if (reg_tmp == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		liberaCompletaLC(expresion);
		liberaCompletaLC(condition);
		liberaCompletaLC(statements);
		free(lexema);
		return creaLC();
	}


	int expr_res = recuperaResLC(expresion);
	int cond_res = recuperaResLC(condition); 

	char *etiqueta_condition = genera_etiqueta();
	char *etiqueta_et_condition = genera_etiqueta_et();
	char *etiqueta_statement = genera_etiqueta();
	char *etiqueta_et_statement = genera_etiqueta_et();

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[expr_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	Operacion salto_comienzo = {
		.op = operation_str[BRANCH],
		.res = etiqueta_condition,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_comienzo);

	Operacion et_estatement = {
		.op = etiqueta_et_statement,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_estatement);

	concatenaLC(codigo, statements);

	Operacion carga = {
		.op = operation_str[LOAD_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	Operacion incremento = {
		.op = operation_str[ADDI],
		.res = registros_str[reg_tmp],
		.arg1 = registros_str[reg_tmp],
		.arg2 = "1",
	};
	Operacion guarda = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), carga);
	insertaLC(codigo, finalLC(codigo), incremento);
	insertaLC(codigo, finalLC(codigo), guarda);

	libera_registro(registros, reg_tmp);

	Operacion et_condition = {
		.op = etiqueta_et_condition,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_condition);

	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[cond_res],
		.arg1 = etiqueta_statement,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, expr_res);
	libera_registro(registros, cond_res);

	liberaLC(condition);
	liberaLC(statements);

	free(lexema);

	return codigo;
}

ListaC codegen_for_extended(char *lexema, ListaC expresion, ListaC condition, ListaC increment, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (expresion != NULL) liberaCompletaLC(expresion);
		if (increment != NULL) liberaCompletaLC(increment);
		if (statements != NULL) liberaCompletaLC(statements);
		free(lexema);
		return NULL;
	}

	int reg_tmp = reserva_registro(registros);
	if (reg_tmp == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		liberaCompletaLC(expresion);
		liberaCompletaLC(condition);
		liberaCompletaLC(increment);
		liberaCompletaLC(statements);
		free(lexema);
		return creaLC();
	}

	ListaC codigo = expresion;

	int expr_res = recuperaResLC(expresion);
	int cond_res = recuperaResLC(condition); 
	int incr_res = recuperaResLC(increment);

	char *etiqueta_condition = genera_etiqueta();
	char *etiqueta_et_condition = genera_etiqueta_et();
	char *etiqueta_statement = genera_etiqueta();
	char *etiqueta_et_statement = genera_etiqueta_et();

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[expr_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	Operacion salto_comienzo = {
		.op = operation_str[BRANCH],
		.res = etiqueta_condition,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_comienzo);

	Operacion et_estatement = {
		.op = etiqueta_et_statement,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_estatement);

	concatenaLC(codigo, statements);

	concatenaLC(codigo, increment);

	Operacion carga = {
		.op = operation_str[LOAD_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	Operacion incremento = {
		.op = operation_str[ADD],
		.res = registros_str[reg_tmp],
		.arg1 = registros_str[reg_tmp],
		.arg2 = registros_str[incr_res],
	};
	Operacion guarda = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), carga);
	insertaLC(codigo, finalLC(codigo), incremento);
	insertaLC(codigo, finalLC(codigo), guarda);

	Operacion et_condition = {
		.op = etiqueta_et_condition,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_condition);

	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[cond_res],
		.arg1 = etiqueta_statement,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, expr_res);
	libera_registro(registros, cond_res);
	libera_registro(registros, incr_res);

	liberaLC(condition);
	liberaLC(increment);
	liberaLC(statements);

	free(lexema);

	return codigo;
}

ListaC codegen_program(ListaC declarations, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (declarations != NULL) liberaCompletaLC(declarations);
		if (statements != NULL) liberaCompletaLC(statements);
		return NULL;
	}

	ListaC programa = codegen_data();

	Operacion header = {
		.op = CODE_HEADER,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), header);

	concatenaLC(programa, declarations);
	concatenaLC(programa, statements);

	liberaLC(declarations);
	liberaLC(statements);

	header.op = END_HEADER;
	header.res = NULL;
	header.arg1 = NULL;
	header.arg2 = NULL;
	insertaLC(programa, finalLC(programa), header);

	Operacion fin = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(END_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), fin);

	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), syscall);

	return programa;
}

ListaC codegen_data(void)
{
	ListaC data = creaLC();

	Operacion header = {
		.op = DATA_HEADER,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(data, finalLC(data), header);

	Operacion dato;
	PosicionLista aux = inicioLS(tablaSimbolos)->sig;
	while (aux != NULL)
	{
		if (aux->dato.tipo == CADENA)
		{
			dato.op = genera_etiqueta_str(aux->dato.valor);
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);

			dato.op = STR_INSTR;
			dato.res = aux->dato.nombre;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);
		}

		aux = aux->sig;
	}

	header.op = VARIABLES_SUBHEADER;
	header.res = NULL;
	header.arg1 = NULL;
	header.arg2 = NULL;
	insertaLC(data, finalLC(data), header);

	aux = inicioLS(tablaSimbolos)->sig;
	while (aux != NULL)
	{
		if (aux->dato.tipo != CADENA)
		{
			dato.op = genera_etiqueta_id(aux->dato.nombre);
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);

			dato.op = WORD_INSTR;
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);
		}
		
		aux = aux->sig;
	}

	return data;
}

void syntax_inform(syntax_reduction_t red)
{
	if (debug_level & DBG_SYNTAX)
		syntax_debug(red);

	switch (red)
	{
		case MULTIPLE_DECLARATION_ERROR:
		case DECLARATION_ERROR:
		case MULTIPLE_PRINT_FORMAT_ERROR:
		case PRINT_FORMAT_ERROR:
		case MULTIPLE_READ_FORMAT_ERROR:
		case READ_FORMAT_ERROR:
			fprintf(error_file, syn_err_msg[red], yylineno);
			break;
	}
}

void syntax_debug(syntax_reduction_t red)
{
	fprintf(syntax_file, "%s", syntax_reduction_msg[red]);
}

void yyerror(const char *s)
{
	syntax_errors += 1;
	fprintf(error_file, "%s!\n",s);
}