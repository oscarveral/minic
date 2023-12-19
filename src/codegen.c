#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "codegen.h"
#include "master.h"

struct register_manager
{
	register_ocupation_t regs[MAX_REGISTROS];
};

register_set registros = NULL;

int codegen_errors = 0;

register_set crea_registros(void) {
	register_set nuevo = malloc(sizeof(struct register_manager));
	for (int i = 0; i < MAX_REGISTROS; i++)
	{
		nuevo->regs[i] = EMPTY;
	}
	return nuevo;
}

void libera_registros(register_set registros) {
	assert(registros != NULL);
	free(registros);
}

int reserva_registro(register_set registros) 
{
	int indice = ERROR;
	for (int i = 0; i < MAX_REGISTROS; i++)
		if (registros->regs[i] == EMPTY) 
		{
			indice = i;
			registros->regs[i] = RESERVED;
			break;
		}
	return indice;
}

void libera_registro(register_set registros, int numero_registro)
{
	assert(registros->regs[numero_registro] == RESERVED);
	registros->regs[numero_registro] = EMPTY;
}

char *genera_id(char *lexema)
{
	char *nuevo = malloc(strlen(lexema) + 2);
	sprintf(nuevo, "_%s", lexema);
	return nuevo;	
}

char *genera_str(int str_number)
{
	int digits = 0;
	int n = str_number;
	do
	{
		n /= 10;
		++digits;
	} while (n != 0);

	char *nueva = malloc(digits + 5);
	sprintf(nueva, "$str%d", str_number);
	return nueva;
}

char *genera_etiqueta(void)
{
	static int contador_etiquetas = 0;

	int digits = 0;
	int n = contador_etiquetas;
	do
	{
		n /= 10;
		++digits;
	} while (n != 0);
	
	char *nueva = malloc(digits + 4);
	sprintf(nueva, "$et%d", contador_etiquetas);
	contador_etiquetas++;
	return nueva;
}

char *genera_etiqueta_id(char *lexema)
{
	char *nuevo = malloc(strlen(lexema) + 3);
	sprintf(nuevo, "_%s:", lexema);
	return nuevo;	
}

char *genera_etiqueta_str(int str_number)
{
	int digits = 0;
	int n = str_number;
	do
	{
		n /= 10;
		++digits;
	} while (n != 0);

	char *nueva = malloc(digits + 6);
	sprintf(nueva, "$str%d:", str_number);
	return nueva;
}

char *genera_etiqueta_et(void)
{
	static int contador_etiquetas = 0;

	int digits = 0;
	int n = contador_etiquetas;
	do
	{
		n /= 10;
		++digits;
	} while (n != 0);
	
	char *nueva = malloc(digits + 5);
	sprintf(nueva, "$et%d:", contador_etiquetas);
	contador_etiquetas++;
	return nueva;
}

struct PosicionListaCRep {
	Operacion dato;
	struct PosicionListaCRep *sig;
};

struct ListaCRep {
	PosicionListaC cabecera;
	PosicionListaC ultimo;
	int n;
	int res;
};

typedef struct PosicionListaCRep *NodoPtr;

ListaC codigo_generado = NULL;

ListaC creaLC() {
	ListaC nueva = malloc(sizeof(struct ListaCRep));
	nueva->cabecera = malloc(sizeof(struct PosicionListaCRep));
	nueva->cabecera->sig = NULL;
	nueva->ultimo = nueva->cabecera;
	nueva->n = 0;
	nueva->res = -1;
	return nueva;
}

void liberaLC(ListaC codigo) {
	while (codigo->cabecera != NULL) {
		NodoPtr borrar = codigo->cabecera;
		codigo->cabecera = borrar->sig; 
		free(borrar);
	}
	free(codigo);
}

void liberaCompletaLC(ListaC codigo) {
	if (codigo->cabecera != NULL) {
		NodoPtr borrar = codigo->cabecera;
		codigo->cabecera = borrar->sig; 
		free(borrar);
	}

	while (codigo->cabecera != NULL) {
		
		NodoPtr borrar = codigo->cabecera;
		codigo->cabecera = borrar->sig;
		
		if (strcmp(borrar->dato.op, operation_str[LOAD_INMEDIATE]) == OK)
			free(borrar->dato.arg1);

		else if (strcmp(borrar->dato.op, operation_str[LOAD_ADDRESS]) == OK)
			free(borrar->dato.arg1);

		else if (strcmp(borrar->dato.op, operation_str[LOAD_WORD]) == OK)
			free(borrar->dato.arg1);

		else if (strcmp(borrar->dato.op, operation_str[SAVE_WORD]) == OK)
			free(borrar->dato.arg1);

		else if (strcmp(borrar->dato.op, operation_str[BEQZ]) == OK)
			free(borrar->dato.arg1);
		
		else if (strcmp(borrar->dato.op, operation_str[BNEZ]) == OK)
			free(borrar->dato.arg1);

		else if (strcmp(borrar->dato.op, operation_str[BRANCH]) == OK)
			free(borrar->dato.res);

		else if (strncmp(borrar->dato.op,ET_FIRST,1) == OK)
			free(borrar->dato.op);

		else if (strncmp(borrar->dato.op,ET_ID_FIRST,1) == OK)
			free(borrar->dato.op);

		free(borrar);
	}

	free(codigo);
}


void insertaLC(ListaC codigo, PosicionListaC p, Operacion o) {
	NodoPtr nuevo = malloc(sizeof(struct PosicionListaCRep));
	nuevo->dato = o;
	nuevo->sig = p->sig;
	p->sig = nuevo;
	if (codigo->ultimo == p) {
		codigo->ultimo = nuevo;
	}
	(codigo->n)++;
}

Operacion recuperaLC(ListaC codigo, PosicionListaC p) {
	assert(p != codigo->ultimo);
	return p->sig->dato;
}

PosicionListaC buscaLC(ListaC codigo, PosicionListaC p, char *clave, Campo campo) {
	NodoPtr aux = p;
	char *info;
	while (aux->sig != NULL) {
		switch (campo) {
			case OPERACION: 
				info = aux->sig->dato.op;
				break;
			case ARGUMENTO1:
				info = aux->sig->dato.arg1;
				break;
			case ARGUMENTO2:
				info = aux->sig->dato.arg2;
				break;
			case RESULTADO:
				info = aux->sig->dato.res;
				break;
		}
		if (info != NULL && !strcmp(info,clave)) break;
		aux = aux->sig;
	}
	return aux;
}

void asignaLC(ListaC codigo, PosicionListaC p, Operacion o) {
	assert(p != codigo->ultimo);
	p->sig->dato = o;
}

int longitudLC(ListaC codigo) {
	return codigo->n;
}

PosicionListaC inicioLC(ListaC codigo) {
	return codigo->cabecera;
}

PosicionListaC finalLC(ListaC codigo) {
	return codigo->ultimo;
}

void concatenaLC(ListaC codigo1, ListaC codigo2) {
	NodoPtr aux = codigo2->cabecera;
	while (aux->sig != NULL) {
		insertaLC(codigo1,finalLC(codigo1),aux->sig->dato);
		aux = aux->sig;
	}
}

ListaC concatenaSeguraLC(ListaC codigo1, ListaC codigo2)
{
	if (codegen_errors != 0)
	{
		if (codigo1 != NULL) liberaCompletaLC(codigo1);
		if (codigo2 != NULL) liberaCompletaLC(codigo2);
		return NULL;
	}
	else
	{
		concatenaLC(codigo1, codigo2);
		liberaLC(codigo2);
		return codigo1;
	}
}

PosicionListaC siguienteLC(ListaC codigo, PosicionListaC p) {
	assert(p != codigo->ultimo);
	return p->sig;
}

void guardaResLC(ListaC codigo, int res) {
	codigo->res = res;
}

/* Recupera el registro resultado de una lista de codigo */
int recuperaResLC(ListaC codigo) {
	return codigo->res;
}

void imprimirCodigo(ListaC codigo, FILE *fichero)
{
  PosicionListaC p = inicioLC(codigo);
  while (p != finalLC(codigo))
  {
    Operacion oper = recuperaLC(codigo, p);
    fprintf(fichero,"%s", oper.op);
    if (oper.res)
      fprintf(fichero," %s", oper.res);
    if (oper.arg1)
      fprintf(fichero,",%s", oper.arg1);
    if (oper.arg2)
      fprintf(fichero,",%s", oper.arg2);
    fprintf(fichero,"\n");

    p = siguienteLC(codigo, p);
  }
}