/**
 * privados_1.cpp
 * Programa que ejemplifica el uso de acceso privado.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_privados_1
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Privado 1                                   *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador private nos ayuda a evitar que metodos o atributos" << std::endl;
	std::cout << "de una clase sean unica y exclusivamente usados y vistos por las " << std::endl;
	std::cout << "instancias de la clase. En nuestro ejemplo de punto mX y mY son  " << std::endl;
	std::cout << "privados por lo tanto ni con herencias podemos acceder directamente." << std::endl;
	std::cout << "Esto es acceder de la forma punto.mX o bien punto.mY" << std::endl;
	
	Punto punto(1.0, 2.0);
	std::cout << "Punto(" << punto.getX() << ", " << punto.getY() << ")" << std::endl << std::endl;
	
	return 0;
}
