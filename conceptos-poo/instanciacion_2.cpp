/**
 * instanciacion_2.cpp
 * Programa que ejemplifica el uso de instanciacion creados dinamicamente.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_instanciacion_2
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Instanciacion de Objetos creados Dinamicamente     *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "Primer ejemplo de Instanciacion de un objeto de la Clase Punto." << std::endl;
	Punto* punto = new Punto(1.5, 6.836423);
	std::cout << "Punto(" << punto->getX() << ", " << punto->getY() << ")" << std::endl << std::endl;
	
	std::cout << "Segundo ejemplo de Instanciacion de un objeto de la Clase Figura." << std::endl;
	Figura* figura = new Figura(4);
	std::cout << "Figura(" << figura->getNumPuntos() << ")" << std::endl << std::endl;
	return 0;
}
