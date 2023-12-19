#ifndef __MASTER__
#define __MASTER__

#include <stdio.h>

/* Enumerado con los diferentes modos de depuración aceptados por el compilador. */
typedef enum
{
	ONLY_ERROR		= 0,
	DBG_LEXER		= 1 << 0,
	DBG_SYNTAX		= 1 << 1,
	DBG_SEMANTIC 	= 1 << 2,
	WARNINGS		= 1 << 3,

} debug_t;

/* Variable global con la máscara de bits que indica el nivel de depuración. */
extern debug_t debug_level;

/* Variables globales para los ficheros de entrada y salida. */
extern FILE *input_file;
extern FILE *output_file;
extern FILE *error_file;

/* Default output filename. */
#define DEFAULT_OUTPUT_FILENAME "program.s"

/* Definiciones genericas para el compilador. */
#define OK 0
#define ERROR -1

/* Constantes para el manejo de argumentos. */
#define COMPILER_ARGS "l:s:t:o:e:w"
#define ARG_LEX 'l'
#define ARG_SYN 's'
#define ARG_SEM 't'
#define ARG_OUT 'o'
#define ARG_ERR 'e'
#define ARG_WARN 'w'
#define ARG_INVALID '?'

/* Mensajes de error generales del compilador. */
#define OPT_ERR "Invalid argument: %c\n"
#define NO_FILE_ERR "No input file specified.\n"
#define OPEN_FILE_ERR "Could not open file %s.\n"
#define CLOSE_FILE_ERR "Could not close file %s.\n"
#define EMPTY_FILE_ERR "File %s is empty.\n"
#define GENERIC_ERR "Error: "
#define HELP "Usage: %s [-l file] [-s file] [-t file] [-o file] [-e file] [-w] file\n\t -l file\tPrint lexical degug info to file.\n\t -s file\tPrint syntax degug info to file.\n\t -t file\tPrint semantical debug info to file.\n\t -o file\tName of the final binary.\n\t -e file\tPrint compilation errors to file.\n\t -w     \tShow compilation warnings.\n"

/* Mensajes de resumen de errrores. */
#define ERR_SUMMARY_LEX "Errores léxicos: %d\n"
#define ERR_SUMMARY_SYN "Errores sintácticos: %d\n"
#define ERR_SUMMARY_SEM "Errores semánticos: %d\n"
#define ERR_SUMMARY_GEN "Errores de generación: %d\n"
#define ERR_SUMMARY_TOTAL "Total de errores: %d\n"

#endif