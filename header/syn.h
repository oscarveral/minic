#ifndef __SYN__
#define __SYN__

extern int syntax_errors;

extern FILE *syntax_file;

typedef enum
{
	PROGRAMA = 0,

	EMPTY_DECL = 1,
	VAR_DECL = 2,
	CONST_DECL = 3,

	DECLARATION_RED = 4,
	MULTIPLE_DECLARATION = 5,
	MULTIPLE_DECLARATION_ERROR = 6,
	DECLARATION_ERROR = 7,

	ASIG_DECL = 8,
	ASIG_INIT = 9,

	EMPTY_STMT_LIST = 10,
	STMT_LIST = 11,

	ASSIGN_STMT = 12,
	BRACES_STMT = 13,
	IF_ELSE_STMT = 14,
	IF_STMT = 15,
	WHILE_STMT = 16,
	DO_WHILE_STMT = 17,
	FOR_EXT_STMT = 18,
	FOR_STMT = 19,
	PRINT_STMT = 20,
	READ_STMT = 21,

	PRINT_ITEM_RED = 22,
	MULTIPLE_PRINT = 23,
	MULTIPLE_PRINT_FORMAT_ERROR = 24,
	PRINT_FORMAT_ERROR = 25,

	PRINT_EXPR = 26,
	PRINT_ITEM = 27,

	SINGLE_READ = 28,
	MULTIPLE_READ = 29,
	MULTIPLE_READ_FORMAT_ERROR = 30,
	READ_FORMAT_ERROR = 31,

	LTE_EXPR = 32,
	GTE_EXPR = 33,
	LT_EXPR = 34,
	GT_EXPR = 35,
	EQ_EXPR = 36,
	NEQ_EXPR = 37,
	PLUS_EXPR = 38,
	MINUS_EXPR = 39,
	MULT_EXPR = 40,
	DIV_EXPR = 41,
	UMINUS_EXPR = 42,
	NEG_EXPR = 43,
	PAREN_EXPR = 44,
	NUM_EXPR = 45,
	ID_EXPR = 46,

} syntax_reduction_t;


static const char * const syntax_reduction_msg [] = {
	
	[PROGRAMA] = "VOID ID LPARENTHESIS RPARENTHESIS LBRACE declarations statement_list RBRACE ----> programa\n",

	[EMPTY_DECL] = "λ ----> declarations\n",
	[VAR_DECL] = "declarations VAR identifier_list SEMICOLON ----> declarations\n",
	[CONST_DECL] = "declarations CONST identifier_list SEMICOLON ----> declarations\n",

	[DECLARATION_RED] = "asig ----> identifier_list\n",
	[MULTIPLE_DECLARATION] = "identifier_list COMMA asig ----> identifier_list\n",
	[MULTIPLE_DECLARATION_ERROR] = "identifier_list COMMA error ----> identifier_list\n",
	[DECLARATION_ERROR] = "error ----> identifier_list\n",

	[ASIG_DECL] = "ID ----> asig\n",
	[ASIG_INIT] = "ID ASSIGN expression ----> asig\n",

	[EMPTY_STMT_LIST] = "λ ----> statement_list\n",
	[STMT_LIST] = "statement_list statement ----> statement_list\n",

	[ASSIGN_STMT] = "ID ASSIGN expression SEMICOLON ----> statement\n",
	[BRACES_STMT] = "LBRACE statement_list RBRACE ----> statement\n",
	[IF_ELSE_STMT] = "IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement ----> statement\n",
	[IF_STMT] = "IF LPARENTHESIS expression RPARENTHESIS statement ----> statement\n",
	[WHILE_STMT] = "WHILE LPARENTHESIS expression RPARENTHESIS statement ----> statement\n",
	[DO_WHILE_STMT] = "DO statement WHILE LPARENTHESIS expression RPARENTHESIS ----> statement\n",
	[FOR_EXT_STMT] = "FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression SEMICOLON expression RPARENTHESIS statement ----> statement\n",
	[FOR_STMT] = "FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression RPARENTHESIS statement ----> statement\n",
	[PRINT_STMT] = "PRINT print_list SEMICOLON ----> statement\n",
	[READ_STMT] = "READ read_list SEMICOLON ----> statement\n",

	[PRINT_ITEM_RED] = "print_item ----> print_list\n",
	[MULTIPLE_PRINT] = "print_list COMMA print_item ----> print_list\n",
	[MULTIPLE_PRINT_FORMAT_ERROR] = "print_list COMMA error ----> print_list\n",
	[PRINT_FORMAT_ERROR] = "error ----> print_list\n",

	[PRINT_EXPR] = "expression ----> print_item\n",
	[PRINT_ITEM] = "STRING ----> print_item\n",

	[SINGLE_READ] = "ID ----> read_list\n",
	[MULTIPLE_READ] = "read_list COMMA ID ----> read_list\n",
	[MULTIPLE_READ_FORMAT_ERROR] = "read_list COMMA error ----> read_list\n",
	[READ_FORMAT_ERROR] = "error ----> read_list\n",

	[LTE_EXPR] = "expression LTE expression ----> expression\n",
	[GTE_EXPR] = "expression GTE expression ----> expression\n",
	[LT_EXPR] = "expression LT expression ----> expression\n",
	[GT_EXPR] = "expression GT expression ----> expression\n",
	[EQ_EXPR] = "expression EQ expression ----> expression\n",
	[NEQ_EXPR] = "expression NEQ expression ----> expression\n",
	[PLUS_EXPR] = "expression PLUS expression ----> expression\n",
	[MINUS_EXPR] = "expression MINUS expression ----> expression\n",
	[MULT_EXPR] = "expression MULT expression ----> expression\n",
	[DIV_EXPR] = "expression DIVIDE expression ----> expression\n",
	[UMINUS_EXPR] = "MINUS expression ----> expression\n",
	[NEG_EXPR] = "LOGICAL_NEG expression ----> expression\n",
	[PAREN_EXPR] = "LPARENTHESIS expression RPARENTHESIS ----> expression\n",
	[NUM_EXPR] = "NUM ----> expression\n",
	[ID_EXPR] = "ID ----> expression\n",
};

static const char * const syn_err_msg [] = {

	[MULTIPLE_DECLARATION_ERROR] = "On line %d, the declaration has an error.\n",
	[DECLARATION_ERROR] = "On line %d, the declaration has an error.\n",
	[MULTIPLE_PRINT_FORMAT_ERROR] = "On line %d, the print statement has a bad formated list of variables.\n",
	[PRINT_FORMAT_ERROR] = "On line %d, the print statement has a bad formated list of variables.\n",
	[MULTIPLE_READ_FORMAT_ERROR] = "On line %d, the read statement has a bad formated list of variables.\n",
	[READ_FORMAT_ERROR] = "On line %d, the read statement has a bad formated list of variables.\n",
};

#endif