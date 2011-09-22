/**
 * main.c
 * Programa que ejemplifica el uso de una clase cadena.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 21 de Septiembre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: g++ -o ./cadena_app library/cadena.cpp main.cpp
 * Ejecucion: ./cadena_app
 */
#include <iostream>
#include "library/cadena.h"

int main() {
	// Creamos una cadena
	Cadena micadena("   Anita lava la Tina ");

	// Este metodo nos regresa la longitud de la cadena
	std::cout << micadena.longitud() << std::endl;

	// Metodo para imprimir el contenido de la cadena
	micadena.imprimir();

	// Cambia a Mayusculas toda la cadena y se imprime posteriormente
	micadena.mayusculas();
	micadena.imprimir();

	// Cambia a Minusculas toda la cadena y se imprime posteriormente
	micadena.minusculas();
	micadena.imprimir();

	// Invierte el orden de la cadena
	micadena.invierte();
	micadena.imprimir();
	micadena.invierte();

	// Extrae un pedazo de cadena dependiendo de la posicion y longitud
	char* subcadena = micadena.extraer(6, 4);
	std::cout << subcadena << std::endl;
	delete subcadena;

	// Elimina los espacios al inicio y al final de la cadena
	micadena.recortar();
	micadena.imprimir();
	
	return 0;
}