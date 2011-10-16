/**
 * instanciacion_1.cpp
 * Programa que ejemplifica el uso de instanciacion.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_instanciacion_1
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Instanciacion de Objetos                           *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "Primer ejemplo de Instanciacion de un objeto de la Clase Punto." << std::endl;
	Punto punto(1.5, 6.836423);
	std::cout << "Punto(" << punto.getX() << ", " << punto.getY() << ")" << std::endl << std::endl;
	
	std::cout << "Segundo ejemplo de Instanciacion de un objeto de la Clase Figura." << std::endl;
	Figura figura(4);
	std::cout << "Figura(" << figura.getNumPuntos() << ")" << std::endl << std::endl;
	return 0;
}
