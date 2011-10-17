/**
 * publicos_2.cpp
 * Programa que ejemplifica el uso de acceso publico.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_publicos_2
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

class Hexagono : public Figura {
public:
	Hexagono() : Figura(6) {
		setPunto(0, new Punto(0.0, 1.0));
		setPunto(1, new Punto(1.0, 0.0));
		setPunto(2, new Punto(2.0, 0.0));
		setPunto(3, new Punto(3.0, 1.0));
		setPunto(4, new Punto(2.0, 2.0));
		setPunto(5, new Punto(2.0, 1.0));
	}
	Punto* punto(int i) {
		return getPunto(i);
	}
};

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Publico 2                                   *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador publico es usado para atributos o metodos que pueden" << std::endl;
	std::cout << "ser usados en la misma clase, subclases y fuera de ellas." << std::endl;
	
	Hexagono* hexagono = new Hexagono();
	for (int i = 0; i < hexagono->getNumPuntos(); i++)
		std::cout << "Hexagono.punto[" << i << "] = (" << hexagono->punto(i)->getX() << " ," << hexagono->punto(i)->getY() << ")" << std::endl;
	
	return 0;
}
