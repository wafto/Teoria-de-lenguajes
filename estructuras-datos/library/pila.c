#include <stdlib.h>
#include "pila.h"

void inicializaPila(Pila* p) {
	*p = NULL;
}

int push(Pila* p, ElementoPila e) {
	NodoPila* nodo = crearNodoPila(e);
	if (nodo == NULL)
		return 0;
	nodo->pSiguiente = *p;
	*p = nodo;
	return 1;
}

ElementoPila pop(Pila* p, int* bandera) {
	NodoPila* nodo;
	ElementoPila e;
	if (estaVaciaPila(*p)) {
		*bandera = 0;
		return e;
	}
	nodo = *p;
	*p = nodo->pSiguiente;
	e = nodo->valor;
	*bandera = 1;
	free(nodo);
	return e;
}

ElementoPila verTope(Pila p, int* bandera) {
	ElementoPila e;
	*bandera = 0;
	if (estaVaciaPila(p))
		return e;
	*bandera = 1;
	e = p->valor;
	return e;
}

int estaVaciaPila(Pila p) {
	return p == NULL ? 1 : 0;
}

int dimensionPila(Pila p) {
	int dimension = 0;
	NodoPila* nodo = p;
	while (nodo != NULL) {
		nodo = nodo->pSiguiente;
		dimension++;
	}
	return dimension;
}

NodoPila* crearNodoPila(ElementoPila e) {
	NodoPila* nodo = (NodoPila*) malloc(sizeof(NodoPila));
	if (nodo != NULL) {
		nodo->valor = e;
		nodo->pSiguiente = NULL;
	}
	return nodo;
}

