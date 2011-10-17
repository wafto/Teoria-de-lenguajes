/**
 * privados_2.cpp
 * Programa que ejemplifica el uso de acceso privado.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_privados_2
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Privado 2                                   *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador private nos ayuda a evitar que metodos o atributos" << std::endl;
	std::cout << "de una clase sean unica y exclusivamente usados y vistos por las " << std::endl;
	std::cout << "instancias de la clase." << std::endl;
	std::cout << "En nuestro ejemplo de figura no podemos acceder a nuestro arreglo" << std::endl;
	std::cout << "de puntos (Figura::mPuntos) o al tamaño del arreglo de puntos" << std::endl;
	std::cout << "(Figura::numPuntos)" << std::endl;
	
	Figura figura(7);
	std::cout << "Figura(" << figura.getNumPuntos() << ")" << std::endl << std::endl;
	
	return 0;
}
