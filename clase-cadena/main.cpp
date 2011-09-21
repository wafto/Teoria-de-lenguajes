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
using namespace std;

int main() {
	// Creamos una cadena con el famosisimo "Hola Mundo"
	Cadena micadena("Hola Mundo");

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
	
	return 0;
}