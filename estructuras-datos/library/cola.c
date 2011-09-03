#include <stdlib.h>
#include "cola.h"

void inicializaCola(Cola* c) {
	c->pInicio = NULL;
	c->pFinal = NULL;
}

int agregar(Cola* c, ElementoCola e) {
	NodoCola* nodo = crearNodoCola(e);
	if (nodo == NULL)
		return 0;
	if (estaVaciaCola(*c)) {
		c->pInicio = c->pFinal = nodo;
	} else {
		(c->pFinal)->pSiguiente = nodo;
		c->pFinal = nodo;
	}
	return 1;
}

ElementoCola sacar(Cola* c, int* bandera) {
	NodoCola* nodo;
	ElementoCola e;
	if (estaVaciaCola(*c)) {
		*bandera = 0;
	} else {
		nodo = c->pInicio;
		e = nodo->valor;
		c->pInicio = nodo->pSiguiente;
		free(nodo);
		*bandera = 1;
	}
	return e;
}

ElementoCola verFinal(Cola c, int* bandera) {
	ElementoCola e;
	*bandera = 0;
	if (!estaVaciaCola(c)) {
		*bandera = 1;
		e = (c.pFinal)->valor;
	}
	return e;
}

int estaVaciaCola(Cola c) {
	return c.pInicio == NULL ? 1 : 0;
}

int dimensionCola(Cola c) {
	int dimension = 0;
	NodoCola* nodo = c.pInicio;
	while (nodo != NULL) {
		nodo = nodo->pSiguiente;
		dimension++;
	}
	return dimension;
}

NodoCola* crearNodoCola(ElementoCola e) {
	NodoCola* nodo = (NodoCola*) malloc(sizeof(NodoCola));
	if (nodo != NULL) {
		nodo->valor = e;
		nodo->pSiguiente = NULL;
	}
	return nodo;
}
