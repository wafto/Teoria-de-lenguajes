/**
 * protegidos_2.cpp
 * Programa que ejemplifica el uso de acceso protegido.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto/Teoria-de-lenguajes
 * Compilacion: make
 * Eliminar Compilados: make clean
 * Ejecucion: ./app_protegidos_2
 */
#include <iostream>
#include "biblioteca/punto.h"
#include "biblioteca/figura.h"

class CuadradoUnitario : public Figura {
public:
	CuadradoUnitario() : Figura(4) {
		setPunto(0, new Punto(0.0, 0.0));
		setPunto(1, new Punto(0.0, 1.0));
		setPunto(2, new Punto(1.0, 0.0));
		setPunto(3, new Punto(1.0, 1.0));
	}
	Punto* punto(int i) {
		return getPunto(i);
	}
};

int main() {
	
	std::cout << "******************************************************************" << std::endl;
	std::cout << "* Ejemplos de Acceso Protegido 2                                 *" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	
	std::cout << "El modificador protegido nos ayuda a evitar que metodos o atributos" << std::endl;
	std::cout << "de una clase sean unica y exclusivamente usados y vistos por las " << std::endl;
	std::cout << "instancias de la clase y de las subclases." << std::endl;
	std::cout << "En nuestro ejemplo de Figura existe un metodo protegido setPunto este" << std::endl;
	std::cout << "solo puede ser usado en la clase y en las subclases, para este caso se" << std::endl;
	std::cout << "utilizara una subclase y acceder al metodo protegido." << std::endl;
	
	CuadradoUnitario* cu = new CuadradoUnitario();
	int puntos = (*cu).getNumPuntos();
	std::cout << "CuadradoUnitario(" << puntos << ")" << std::endl << std::endl;
	for (int i = 0; i < puntos; i++)
		std::cout << "Punto[" << i << "] = (" << cu->punto(i)->getX() << " ," << cu->punto(i)->getY() << ")" << std::endl;
	
	return 0;
}
