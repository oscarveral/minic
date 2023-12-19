#ifndef __SEM__
#define __SEM__

#include <stdio.h>
#include <stdbool.h>

/* Definiciones para el analizador semántico. */
typedef enum
{
	DECLARATION,
	INITIALIZATION,
	ASSIGNATION,
	USE,
	STRING_SYMBOL,

} semantic_action_t;

typedef enum
{
	UNDECLARED,
	CONST_ASSIGN,
	DOUBLE_DECLARATION,
	WARN_NO_INITIALIZED,

} semantic_error_t;

static const char * const semantic_error_msg[] = {
	
	[UNDECLARED] = "Semantic error! On line %d, the symbol %s was not declared before.\n",
	[CONST_ASSIGN] = "Semantic error! On line %d, you are trying to assign a value to the constant symbol: %s.\n",
	[DOUBLE_DECLARATION] = "Semantic error! On line %d, the symbol %s was already declared before.\n",
	[WARN_NO_INITIALIZED] = "Warning! On line %d, the symbol %s is not initialized. Consider initializing it to avoid future bugs!\n",
};

extern int semantic_errors;
extern FILE *semantic_file;

typedef enum
{
	VARIABLE = 1,
	CONSTANTE = 2,
	CADENA = 3,

} Tipo;

typedef struct Nodo
{
	char *nombre;
	Tipo tipo;
	int valor;
	bool inicializado;

} Simbolo;

struct PosicionListaRep
{
	Simbolo dato;
	struct PosicionListaRep *sig;
};

typedef struct ListaRep *ListaS;
typedef struct PosicionListaRep *PosicionLista;

struct ListaRep
{
	PosicionLista cabecera;
	PosicionLista ultimo;
	int n;
	int contadorCadenas;
};

extern Tipo tipoSemantico;
extern ListaS tablaSimbolos;

ListaS creaLS();

void liberaLS(ListaS lista);

void insertaLS(ListaS lista, PosicionLista p, Simbolo s);

Simbolo recuperaLS(ListaS lista, PosicionLista p);

PosicionLista buscaLS(ListaS lista, char *nombre);

void asignaLS(ListaS lista, PosicionLista p, Simbolo s);

int longitudLS(ListaS lista);

PosicionLista inicioLS(ListaS lista);

PosicionLista finalLS(ListaS lista);

PosicionLista siguienteLS(ListaS lista, PosicionLista p);

bool perteneceTablaS(ListaS lista, char *nombre);

void añadeEntrada(ListaS lista, char *lexema, Tipo tipo, bool inicializado);

bool esConstante(ListaS lista, char *nombre);

int recupera_valor(ListaS lista, char *nombre);

void imprimirTablaS(ListaS lista, FILE *file);

#endif