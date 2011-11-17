/**
 * main.cpp
 * Programa que hace uso de una clase pila y clase cola utilizando templates
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 16 de Noviembre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: g++ -o app main.cpp
 * Ejecucion: ./app
 */
#include <iostream>
#include "classes/pila.h"
#include "classes/cola.h"
using namespace std;

int main() {
	Pila<float> pila;
	Cola<float> cola;

	cout << " -> Pila" << endl;
	for (int i = 0; i < 10; i++)
		pila.insertar(i + 0.01);

	while (!pila.estaVacia())
		cout << "\t" << pila.sacar() << endl;

	cout << endl << " -> Cola " << endl;
	for (int i = 0; i < 10; i++)
		cola.insertar(i + 0.03);

	while (!cola.estaVacia())
		cout << "\t" << cola.sacar() << endl;

	return 0;
}