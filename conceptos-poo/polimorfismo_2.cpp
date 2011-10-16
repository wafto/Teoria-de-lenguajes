/**
 * polimorfismo_2.cpp
 * Programa que ejemplifica el uso de polimorfismo.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_polimorfismo_2
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
	std::cout << "* Ejemplos de Polimorfismo con la clase Figura con un Triangulo  *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "Se crea una nueva clase Triangulo con referencia Figura(Polimorfismo) y la instanciamos" << std::endl;
	Figura *triangulo = new Triangulo();
	
	std::cout << "El objeto trinagulo de la clase Cuadrado tiene " << (*triangulo).getNumPuntos() << " puntos" << std::endl;
	
	return 0;
}