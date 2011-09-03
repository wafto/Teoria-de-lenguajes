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

int main() {
	ElementoPila elemento;
	Pila pila;
	int bandera, dimension, i;

	inicializaPila(&pila);

	for (i = 0; i < 100; i++)
		push(&pila, i);

	while (!estaVacia(pila)) {
		elemento = pop(&pila, &bandera);
		dimension = dimensionPila(pila);
		if (bandera)
			printf("Se saco de la pila el elemento %d y la dimesion de la pila ahora es %d\n", elemento, dimension);
	}

	return 0;
}
