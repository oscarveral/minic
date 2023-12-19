#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "codegen.h"
#include "master.h"
#include "lex.h"
#include "syn.h"
#include "sem.h"

extern int 	optopt;
extern int 	optind;
extern char *optarg;

extern FILE *yyin;
extern yytoken_kind_t yylex();

debug_t debug_level = ONLY_ERROR;

FILE *input_file 	= NULL;
FILE *output_file 	= NULL;
FILE *error_file 	= NULL;

int main(int argc, char **argv)
{
	char arg 				= ARG_INVALID;
	char *output_filename 	= NULL;
	char *input_filename 	= NULL;
	char *error_filename 	= NULL;
	char *lexer_filename 	= NULL;
	char *syntax_filname	= NULL;
	char *semantic_filename = NULL;

	int total_errors = 0;

	while ((arg = getopt(argc, argv, COMPILER_ARGS)) != ERROR)
	{
		switch (arg)
		{
		case ARG_LEX:
			debug_level |= DBG_LEXER;
			lexer_filename = optarg;
			break;
		case ARG_SYN:
			debug_level |= DBG_SYNTAX;
			syntax_filname = optarg;
			break;
		case ARG_SEM:
			debug_level |= DBG_SEMANTIC;
			semantic_filename = optarg;
		case ARG_OUT:
			output_filename = optarg;
			break;
		case ARG_ERR:
			error_filename = optarg;
			break;
		case ARG_WARN:
			debug_level |= WARNINGS;
			break;
		case ARG_INVALID:
			fprintf(stderr, OPT_ERR, optopt);
			fprintf(stderr, HELP, argv[0]);
			return EXIT_FAILURE;
		default:
			abort();
		}
	}

	if (optind >= argc)
	{
		fprintf(stderr, NO_FILE_ERR);
		fprintf(stderr, HELP, argv[0]);
		return EXIT_FAILURE;
	}

	input_filename = argv[optind];
	if ((input_file = fopen(input_filename, "r")) == NULL)
	{
		fprintf(stderr, OPEN_FILE_ERR, input_filename);
		perror(GENERIC_ERR);
		return EXIT_FAILURE;
	}

	fseek(input_file, 0, SEEK_END);
	long size = ftell(input_file);

	if (size == 0)
	{
		fprintf(stderr, EMPTY_FILE_ERR, input_filename);
		return EXIT_FAILURE;
	}

	fseek(input_file, 0, SEEK_SET);

	if (error_filename != NULL)
	{
		if ((error_file = fopen(error_filename, "w")) == NULL)
		{
			fprintf(stderr, OPEN_FILE_ERR, error_filename);
			perror(GENERIC_ERR);
			return EXIT_FAILURE;
		}
	}
	else error_file = stderr;
	
	if (debug_level & DBG_LEXER && (lexer_file = fopen(lexer_filename, "w")) == NULL)
	{
		fprintf(stderr, OPEN_FILE_ERR, lexer_filename);
		perror(GENERIC_ERR);
		return EXIT_FAILURE;
	}

	if (debug_level & DBG_SYNTAX && (syntax_file = fopen(syntax_filname, "w")) == NULL)
	{
		fprintf(stderr, OPEN_FILE_ERR, syntax_filname);
		perror(GENERIC_ERR);
		return EXIT_FAILURE;
	}
	
	if (debug_level & DBG_SEMANTIC && (semantic_file = fopen(semantic_filename, "w")) == NULL)
	{
		fprintf(stderr, OPEN_FILE_ERR, semantic_filename);
		perror(GENERIC_ERR);
		return EXIT_FAILURE;
	}

	yyin = input_file;

	if (debug_level == DBG_LEXER) while (yylex());
	else yyparse();

	yyin = NULL;

	if (lexer_errors != 0)
		fprintf(error_file, ERR_SUMMARY_LEX, lexer_errors);
	if (syntax_errors != 0)
		fprintf(error_file, ERR_SUMMARY_SYN, syntax_errors);
	if (semantic_errors != 0)
		fprintf(error_file, ERR_SUMMARY_SEM, semantic_errors);
	if (codegen_errors != 0)
		fprintf(error_file, ERR_SUMMARY_GEN, codegen_errors);

	total_errors = lexer_errors + syntax_errors + semantic_errors + codegen_errors;

	if (total_errors != 0)
		fprintf(error_file, ERR_SUMMARY_TOTAL, total_errors);
	
	if (total_errors == 0 && debug_level != DBG_LEXER) 
	{
		if (output_filename == NULL)
			output_filename = DEFAULT_OUTPUT_FILENAME;
		if ((output_file = fopen(output_filename, "w")) == NULL)
		{
			fprintf(stderr, OPEN_FILE_ERR, output_filename);
			perror(GENERIC_ERR);
			return EXIT_FAILURE;
		}

		imprimirCodigo(codigo_generado, output_file);
	}

	if (codigo_generado != NULL)
		liberaCompletaLC(codigo_generado);

	if (tablaSimbolos != NULL)
		liberaLS(tablaSimbolos);

	if (fclose(input_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, input_filename);
		return EXIT_FAILURE;
	}
	if (total_errors == 0 && output_file != NULL && fclose(output_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, output_filename);
		return EXIT_FAILURE;
	}
	if (error_filename != NULL && fclose(error_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, error_filename);
		return EXIT_FAILURE;
	}
	if (debug_level & DBG_LEXER && fclose(lexer_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, lexer_filename);
		return EXIT_FAILURE;
	}
	if (debug_level & DBG_SYNTAX && fclose(syntax_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, syntax_filname);
		return EXIT_FAILURE;
	}
	if (debug_level & DBG_SEMANTIC && fclose(semantic_file) == EOF)
	{
		fprintf(stderr, CLOSE_FILE_ERR, semantic_filename);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}