#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "sem.h"

int semantic_errors = 0;
FILE *semantic_file = NULL;

Tipo tipoSemantico = 0;
ListaS tablaSimbolos = NULL;

ListaS creaLS() {
	
	ListaS nueva = malloc(sizeof(struct ListaRep));
	
	Simbolo no_symbol = {NULL, VARIABLE, 0, false};
	nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
	nueva->cabecera->sig = NULL;
	nueva->cabecera->dato = no_symbol;
	
	nueva->ultimo = nueva->cabecera;
	nueva->n = 0;
	nueva->contadorCadenas = 0;
	
	return nueva;
}

void liberaLS(ListaS lista) {

	if (lista->cabecera != NULL) {
		PosicionLista borrar = lista->cabecera;
		lista->cabecera = borrar->sig;
		free(borrar);
	}

	while (lista->cabecera != NULL)
	{
		PosicionLista borrar = lista->cabecera;
		lista->cabecera = borrar->sig;
		free((borrar->dato).nombre);
		free(borrar);
	}

	free(lista);
}

void insertaLS(ListaS lista, PosicionLista p, Simbolo s) {
	PosicionLista nuevo = malloc(sizeof(struct PosicionListaRep));
	nuevo->dato = s;
	nuevo->sig = p->sig;
	p->sig = nuevo;
	if (lista->ultimo == p) {
		lista->ultimo = nuevo;
	}
	(lista->n)++;
	if (s.tipo == CADENA) (lista->contadorCadenas)++;
}

void suprimeLS(ListaS lista, PosicionLista p) {
	assert(p != lista->ultimo);
	PosicionLista borrar = p->sig;
	p->sig = borrar->sig;
	if (lista->ultimo == borrar) {
		lista->ultimo = p;
	}
	if ((borrar->dato).tipo == CADENA) (lista->contadorCadenas)++;
	if (borrar->dato.nombre != NULL) free(borrar->dato.nombre);
	(lista->n)--;
	free(borrar);
}

Simbolo recuperaLS(ListaS lista, PosicionLista p) {
	assert(p != lista->ultimo);
	return p->sig->dato;
}

PosicionLista buscaLS(ListaS lista, char *nombre) {
	PosicionLista aux = lista->cabecera;
	while (aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) != 0) {
		aux = aux->sig;
	}
	return aux;
}

void asignaLS(ListaS lista, PosicionLista p, Simbolo s) {
	assert(p != lista->ultimo);
	Simbolo borrar = p->sig->dato;
	if (borrar.nombre != NULL) free(borrar.nombre);
	p->sig->dato = s;
}

int longitudLS(ListaS lista) {
	return lista->n;
}

PosicionLista inicioLS(ListaS lista) {
	return lista->cabecera;
}

PosicionLista finalLS(ListaS lista) {
	return lista->ultimo;
}

PosicionLista siguienteLS(ListaS lista, PosicionLista p) {
	assert(p != lista->ultimo);
	return p->sig;
}

bool perteneceTablaS(ListaS lista, char *nombre) {
	return (buscaLS(lista, nombre)->sig != NULL);
}

void añadeEntrada(ListaS lista, char *lexema, Tipo tipo, bool inicializado) {
	Simbolo s = {strdup(lexema), tipo, 0, inicializado};
	if (tipo == CADENA) s.valor = (lista->contadorCadenas) + 1;
	insertaLS(lista, finalLS(lista), s);
}

bool esConstante(ListaS lista, char *nombre) {
	Simbolo s = recuperaLS(lista, buscaLS(lista, nombre));
	return s.tipo == CONSTANTE;
}

int recupera_valor(ListaS lista, char *nombre) {
	Simbolo s = recuperaLS(lista, buscaLS(lista, nombre));
	return s.valor;
}

void imprimirTablaS(ListaS lista, FILE *file)
{
	fprintf(file,"-----------------\nTABLA DE SIMBOLOS\nCantidad de símbolos: %d\nCandidad de cadenas: %d\n-----------------\nTipo - Etiqueta - Valor semántico - Inicializado\n", lista->n, lista->contadorCadenas);

	PosicionLista aux = inicioLS(lista)->sig;
	while (aux != NULL) {
		if (aux->dato.tipo == CONSTANTE)
			fprintf(file,"CONSTANTE - _%s - %d - %d\n", aux->dato.nombre, aux->dato.valor, aux->dato.inicializado);
		aux = aux->sig;
	}
	aux = inicioLS(lista)->sig;
	while (aux != NULL) {
		if (aux->dato.tipo == VARIABLE)
			fprintf(file,"VARIABLE - _%s - %d - %d\n", aux->dato.nombre, aux->dato.valor, aux->dato.inicializado);
		aux = aux->sig;
	}
	aux = inicioLS(lista)->sig;
	while (aux != NULL) {
		if (aux->dato.tipo == CADENA)
			fprintf(file,"CADENA - $str%d - %s - %d\n", aux->dato.valor, aux->dato.nombre, aux->dato.inicializado);
		aux = aux->sig;
	}

	fprintf(file, "-------------------\n");
}