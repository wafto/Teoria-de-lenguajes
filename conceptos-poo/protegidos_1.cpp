/**
 * protegidos_1.cpp
 * Programa que ejemplifica el uso de acceso protegido.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_protegidos_1
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Protegido 1                                 *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador protegido nos ayuda a evitar que metodos o atributos" << std::endl;
	std::cout << "de una clase sean unica y exclusivamente usados y vistos por las " << std::endl;
	std::cout << "instancias de la clase y de las subclases." << std::endl;
	std::cout << "En nuestro ejemplo de Figura existe un metodo protegido setPunto este" << std::endl;
	std::cout << "solo puede ser usado en la clase y en las subclases." << std::endl;
	
	Figura figura(7);
	std::cout << "Figura(" << figura.getNumPuntos() << ")" << std::endl << std::endl;
	
	return 0;
}
