#ifndef __CODEGEN__
#define __CODEGEN__

#include <stdio.h>

/* Definiciones para la generación de código. */
#define MAX_REGISTROS 10

typedef enum
{
	LOAD_INMEDIATE,
	LOAD_ADDRESS,

	LOAD_WORD,
	SAVE_WORD,

	MOVE,
	ADDI,

	BEQZ,
	BNEZ,
	BRANCH,

	ADD,
	SUB,
	MUL,
	DIV,
	SEQ,
	SGE,
	SGT,
	SLE,
	SLT,
	SNE,

	NEG,
	NOT,

	SYSCALL,

} operation_t;

static char * const operation_str[] = {

	[LOAD_INMEDIATE] = "\tli",
	[LOAD_ADDRESS] = "\tla",

	[LOAD_WORD] = "\tlw",
	[SAVE_WORD] = "\tsw",

	[MOVE] = "\tmove",
	[ADDI] = "\taddi",
	
	[BEQZ] = "\tbeqz",
	[BNEZ] = "\tbnez",
	[BRANCH] = "\tb",

	[ADD] = "\tadd",
	[SUB] = "\tsub",
	[MUL] = "\tmul",
	[DIV] = "\tdiv",
	[SEQ] = "\tseq",
	[SGE] = "\tsge",
	[SGT] = "\tsgt",
	[SLE] = "\tsle",
	[SLT] = "\tslt",
	[SNE] = "\tsne",

	[NEG] = "\tneg",
	[NOT] = "\tseq",

	[SYSCALL] = "\tsyscall",
};

static char * const registros_str[MAX_REGISTROS] = {

	[0] = "$t0",
	[1] = "$t1",
	[2] = "$t2",
	[3] = "$t3",
	[4] = "$t4",
	[5] = "$t5",
	[6] = "$t6",
	[7] = "$t7",
	[8] = "$t8",
	[9] = "$t9",
};

#define ZERO_REGISTER "$zero"
#define SYSCALL_REGISTER "$v0"
#define SYSCALL_ARG_REGISTER "$a0"

#define PRINT_NUM_SYSCALL "1"
#define PRINT_STR_SYSCALL "4"
#define READ_SYSCALL "5"
#define END_SYSCALL "10"

#define DATA_HEADER "##################\n# Seccion de datos\n\t.data\n\n# Cadenas del programa"
#define VARIABLES_SUBHEADER "\n# Variables y constantes"
#define CODE_HEADER "\n###################\n# Seccion de codigo\n\t.text\n\t.globl main\nmain:\n"
#define END_HEADER "\n###################\n# Fin"
#define STR_INSTR "\t.asciiz"
#define WORD_INSTR "\t.word 0"

#define ET_FIRST "$"
#define ET_ID_FIRST "_"

typedef enum { EMPTY = 0, RESERVED = 1 } register_ocupation_t;

typedef struct register_manager* register_set;

extern register_set registros;
extern int codegen_errors;

#define REGISTER_EXHAUSTION_ERROR "Codegen error! On line %d, too much nested code to be handled by the compiler. Register exhaustion!\nProbably the code is too much nested. Try refactoring it.\n"

register_set crea_registros(void);

void libera_registros(register_set registros);

int reserva_registro(register_set registros);

void libera_registro(register_set registros, int numero_registro);

char *genera_id(char *lexema);

char *genera_str(int str_number);

char *genera_etiqueta(void);

char *genera_etiqueta_id(char *lexema);

char *genera_etiqueta_str(int str_number);

char *genera_etiqueta_et(void);

typedef enum { OPERACION, ARGUMENTO1, ARGUMENTO2, RESULTADO } Campo;

/* Una operación MIPS tiene, en el caso más complejo:
- op: código de operación, como "add", "mv", etc.
- arg1: argumento 1 de la operación, como "$t0", etc.
- arg2: argumento 2 de la operación, como "$t1", etc.
- res: resultado de la operación, como "$t3", etc.
Si algún campo no se usa, se marca con NULL.
*/
typedef struct {
	char * op;
	char * res;
	char * arg1;
	char * arg2;
} Operacion;

/* ListaC es una lista enlazada de código, que contiene instancias de Operacion */
typedef struct ListaCRep * ListaC;
typedef struct PosicionListaCRep *PosicionListaC;

extern ListaC codigo_generado;

/* Crea una lista de código */
ListaC creaLC();
/* Destruye una lista de código */
void liberaLC(ListaC codigo);
/* Destruye una lista de símbolos atendiendo a liberar los recursos de memoria dinámica que posee. */
void liberaCompletaLC(ListaC codigo);
/* Inserta una nueva operación en la lista de código, en la posición indicada */
void insertaLC(ListaC codigo, PosicionListaC p, Operacion o);
/* Recupera la operación que ocupa la posición indicada */
Operacion recuperaLC(ListaC codigo, PosicionListaC p);
/* Busca una operación en la lista, a partir de cierta posición, con un valor en cierto campo */
PosicionListaC buscaLC(ListaC codigo, PosicionListaC p, char *clave, Campo campo);
/* Asigna una operación a cierta posición de la lista */
void asignaLC(ListaC codigo, PosicionListaC p, Operacion o);
/* Concatena dos listas de código. La primera lista se modifica para formar el resultado */
void concatenaLC(ListaC codigo1, ListaC codigo2);
/* Contaceta dos listas de codigo de forma segura, liberando la concatenada de memoria y tratando posibles errores. */
ListaC concatenaSeguraLC(ListaC codigo1, ListaC codigo2);
/* Longitud de una lista de código */
int longitudLC(ListaC codigo);
/* Posición de comienzo de una lista de código */
PosicionListaC inicioLC(ListaC codigo);
/* Posición de final de una lista de código */
PosicionListaC finalLC(ListaC codigo);
/* Posición siguiente de una dada en una lista de código */
PosicionListaC siguienteLC(ListaC codigo, PosicionListaC p);
/* Almacena el registro resultado de una lista de código */
void guardaResLC(ListaC codigo, int res);
/* Recupera el registro resultado de una lista de código */
int recuperaResLC(ListaC codigo);
/* Función para imprimir el código en un fichero. */
void imprimirCodigo(ListaC codigo, FILE *fichero);


#endif