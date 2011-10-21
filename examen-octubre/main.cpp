/**
 * main.cpp
 * Resolucion del examen de octubre 
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 20 de Octubre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: g++ classes/string.cpp classes/hashmap.cpp main_string.cpp -o app
 * Ejecucion: ./app
 */
#include <iostream>
#include "classes/string.h"
#include "classes/hashmap.h"
using namespace std;


int main() {
	
	cout << endl;
	String original = "Anita lava la tina";
	cout << " -> Creamos una instancia String." << endl << "\t" << original << endl << endl;
	
	String copia(original);
	cout << " -> Hacemos una copia del original." << endl << "\t" << copia << endl << endl;
	
	String concat(", Pero no lo lavo bien.");
	copia = copia + concat;
	cout << " -> Concatenamos a la copia un nuevo String." << endl << "\t" << copia << endl << endl;
	
	String numero = 1234509876;
	cout << " -> Sobrecarga con un numero a String." << endl << "\t" << numero << endl << endl;
	
	String segunda(copia);
	cout << " -> Comparamos la igualdad entre Strings copia con segunda (copia de copia)." << endl;
	cout << "\t" << (copia == segunda ? "Son iguales." : "Son diferentes.") << endl << endl;
	
	String tigres = "Tres tristes tigres, tragaban trigo en un trigal, trababan en un trigal tres tristes tigres.";
	String coincidencias = "tri";
	cout << " -> Encontramos las coincidencias en la cadena de trigres." << endl;
	cout << "\tTigres: " << tigres << endl;
	cout << "\tCoincidencia: " << coincidencias << endl;
	cout << "\tNumero de coincidencias: " << tigres.matches(coincidencias) << endl;
	cout << "\tPosiciones de las coincidencias: ";
	int c = tigres.matches(coincidencias);
	long* pos = tigres.search(coincidencias);
	for (int i = 0; i < c; i++)
		cout << pos[i] << (c != i + 1 ? ", " : "") ;
	cout << endl << endl;
	delete [] pos;
	
	HashMap diccionario;
	String school   = "school";
	String house    = "house";
	String notebook = "notebook";
	String aftab    = "aftab";
	cout << " -> Creamos una instancia HashMap (diccionario) y la utilizamos." << endl;
	cout << "\t" << "diccionario[" << school   << "]\t: " << diccionario[school]   << endl;
	cout << "\t" << "diccionario[" << house    << "]\t: " << diccionario[house]    << endl;
	cout << "\t" << "diccionario[" << "apple"  << "]\t: " << diccionario["apple"]  << endl; 
	cout << "\t" << "diccionario[" << notebook << "]\t: " << diccionario[notebook] << endl; 
	cout << "\t" << "diccionario[" << "bed"    << "]\t: " << diccionario["bed"]    << endl; 
	cout << "\t" << "diccionario[" << aftab    << "]\t: " << diccionario[aftab]    << endl;  
	cout << endl;
	
	return 0;
}




