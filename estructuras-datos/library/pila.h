#ifndef PILA_H
#define PILA_H

typedef int ElementoPila;

typedef struct NodoP {
	ElementoPila valor;
	struct NodoP* pSiguiente; 
} NodoPila;

typedef NodoPila* Pila;

void inicializaPila(Pila* p);
int push(Pila* p, ElementoPila e);
ElementoPila pop(Pila* p, int* bandera);
ElementoPila verTope(Pila p, int* bandera);
int estaVacia(Pila p);
int dimensionPila(Pila p);
NodoPila* crearNodoPila(ElementoPila e);

#endif