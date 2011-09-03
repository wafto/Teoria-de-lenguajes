#ifndef COLA_H
#define COLA_H

typedef int ElementoCola;

typedef struct NodoC {
	ElementoCola valor;
	struct NodoC* pSiguiente; 
} NodoCola;

typedef struct {
	NodoCola* pInicio;
	NodoCola* pFinal;	
} Cola;

void inicializaCola(Cola* c);
int agregar(Cola* c, ElementoCola e);
ElementoCola sacar(Cola* c, int* bandera);
ElementoCola verFinal(Cola c, int* bandera);
int estaVaciaCola(Cola c);
int dimensionCola(Cola c);
NodoCola* crearNodoCola(ElementoCola e);

#endif