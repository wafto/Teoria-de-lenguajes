/**
 * herencia_1.cpp
 * Programa que ejemplifica el uso de herencia con una subclase cuadrado.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_herencia_1
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

class Cuadrado : public Figura {
public:
	Cuadrado() : Figura(4) {}
};

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Herencia con la clase Figura con un Cuadrado       *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "Se crea una nueva clase Cuadrado y la instanciamos" << std::endl;
	Cuadrado *cuadrado = new Cuadrado();
	
	std::cout << "El objeto cuadrado de la clase Cuadrado tiene " << cuadrado->getNumPuntos() << " puntos" << std::endl;
	
	return 0;
}