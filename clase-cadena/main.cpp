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
	std::cout << "-> Creamos una cadena" << std::endl;
	Cadena micadena("   Anita lava la Tina, pero anita no lo lavo bien, ya que pakita hermana de anita no le presto el trapo. ");
	micadena.imprimir();

	std::cout << std::endl << "-> Este metodo nos regresa la longitud de la cadena" << std::endl;
	std::cout << micadena.longitud() << std::endl;

	std::cout << std::endl << "-> Metodo para imprimir el contenido de la cadena" << std::endl;
	micadena.imprimir();

	std::cout << std::endl << "-> Elimina los espacios al inicio y al final de la cadena" << std::endl;
	micadena.recortar();
	micadena.imprimir();

	std::cout << std::endl << "-> Cambia a Mayusculas toda la cadena y se imprime posteriormente" << std::endl;
	micadena.mayusculas();
	micadena.imprimir();

	std::cout << std::endl << "-> Cambia a Minusculas toda la cadena y se imprime posteriormente" << std::endl;
	micadena.minusculas();
	micadena.imprimir();

	std::cout << std::endl << "-> Invierte el orden de la cadena" << std::endl;
	micadena.invierte();
	micadena.imprimir();
	micadena.invierte();

	std::cout << std::endl << "-> Extrae un pedazo de cadena dependiendo de la posicion y longitud (posicion 55, longitud 23)" << std::endl;
	char* subcadena = micadena.extraer(55, 23);
	std::cout << subcadena << std::endl;
	delete subcadena;

	std::cout << std::endl << "-> Remplaza el origen por el destino en la cadena (anita -> chachita)" << std::endl;
	char origen[] = "anita";
	char destino[] = "chachita";
	micadena.remplazar(origen, destino);
	micadena.imprimir();
	
	return 0;
}
