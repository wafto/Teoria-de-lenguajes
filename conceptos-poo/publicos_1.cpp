/**
 * publicos_1.cpp
 * Programa que ejemplifica el uso de acceso publico.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_publicos_1
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Publico 1                                   *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador publico es usado para atributos o metodos que pueden" << std::endl;
	std::cout << "ser usados en la misma clase, subclases y fuera de ellas." << std::endl;
	
	Punto punto(100.0, 150.0);
	std::cout << "Punto(" << punto.getX() << ", " << punto.getY() << ")" << std::endl << std::endl;
	
	std::cout << "Ahora modificamos el valor de los puntos." << std::endl;
	
	punto.setX(70.5);
	punto.setY(40.5);
	std::cout << "Punto(" << punto.getX() << ", " << punto.getY() << ")" << std::endl << std::endl;
	
	return 0;
}
