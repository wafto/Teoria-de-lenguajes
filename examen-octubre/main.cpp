/**
 * main.cpp
 * Programa que ejemplifica el uso de una cadena con sobrecarga de operadores.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 20 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: g++ classes/string.cpp main_string.cpp -o app_string
 * Ejecucion: ./app_string
 */
#include <iostream>
#include "classes/string.h"
#include "classes/hashmap.h"

void pstring(const String &str) {
	for (int i = 0; i < str.lenght(); i++)
		std::cout << str[i];
	std::cout << std::endl;
}

int main() {
	
	HashMap hash;
	
	String yo = "aftab"; 
	
	pstring(hash["house"]);
	pstring(hash["computer"]);
	pstring(hash["apple"]);
	pstring(hash["school"]);
	pstring(hash[yo]);
	
	return 0;
}




