/**
 * main.c
 * Programa que ejemplifica el uso de pilas y colas dinamicas.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 2 de Septiembre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: gcc -o ./structuras_datos_app library/pila.c main.c
 * Ejecucion: ./estructuras_datos_app
 */
#include <stdio.h>
#include "library/pila.h"
#include "library/cola.h"

int main() {
	ElementoPila ep;
	Pila pila;

	ElementoCola ec;
	Cola cola;

	int bandera, dimension, i;

	inicializaPila(&pila);
	inicializaCola(&cola);

	printf("\nAgregamos valores a la Pila\n");

	for (i = 0; i < 10; i++) {
		push(&pila, random() % 1001);
		dimension = dimensionPila(pila);
		ep = verTope(pila, &bandera);
		if (bandera)
			printf("Pila(%d) : valor %d\n", dimension, ep);
	}

	printf("\nSacamos valores a la Pila\n");

	while (!estaVaciaPila(pila)) {
		dimension = dimensionPila(pila);
		ep = pop(&pila, &bandera);
		if (bandera)
			printf("Pila(%d) : valor %d\n", dimension, ep);
	}

	printf("\nAgregamos valores a la Cola\n");

	for (i = 0; i < 10; i++) {
		agregar(&cola, random() % 1001);
		dimension = dimensionCola(cola);
		ec = verFinal(cola, &bandera);
		if (bandera)
			printf("Cola(%d) : valor %d\n", dimension, ec);
	}

	printf("\nSacamos valores a la Cola\n");

	while (!estaVaciaCola(cola)) {
		dimension = dimensionCola(cola);
		ec = sacar(&cola, &bandera);
		if (bandera)
			printf("Cola(%d) : valor %d\n", dimension, ec);
	}

	return 0;
}
