/**
 * herencia_2.cpp
 * Programa que ejemplifica el uso de herencia con una subclase triangulo.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_herencia_2
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

class Triangulo : public Figura {
public:
	Triangulo() : Figura(3) {}
};

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Herencia con la clase Figura con un Triangulo      *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "Se crea una nueva clase Triangulo y la instanciamos" << std::endl;
	Triangulo *triangulo = new Triangulo();
	
	std::cout << "El objeto triangulo de la clase Triangulo tiene " << triangulo->getNumPuntos() << " puntos" << std::endl;
	
	return 0;
}