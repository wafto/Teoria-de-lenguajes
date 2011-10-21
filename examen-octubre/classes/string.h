#ifndef STRING_H
#define STRING_H

#include <sstream>
#include <iostream>
using namespace std;

class String {
private:
	char* str;
	long len;
public:
	// (1/4 punto) Inicializa una cadena como nula
	String();
	// (1/4 punto) Inicializa una cadena con la cadena s
	String(const char*);
	// (1/4 punto) Constructor de copia
	String(const String&);
	// Constructor con long
	String(const long);
	// (1/4 punto) Destructor
	~String();
	// (1/2 punto) Sobrecarga del operador igual
	void operator = (const String&);
	// (1/2 punto) Asigna un numero entero a una cadena
	void operator = (long);
	// (1/2 punto) Concatena la cadena 
	String operator + (const String&);
	// (1 punto) compara 2 cadenas
	bool operator == (const String&);
	// (3 puntos) Regresa en un arreglo de enteros las posiciones donde
	// se encuentra la cadena
	long* search(const String&);
	// Metodos Auxiliares
	// Regresa la longitud del string
	long lenght() const;
	// Sobrecargamos el corchete para hacer mas mono el codigo
	char operator [] (const long i) const;
	// Regresa el numero de coincidencias de una cadena
	long matches(const String&) const;
	// Para asignar arreglo de caracteres directamente
	void operator = (const char*);
	// Sobrecarga para imprimir directamente con cout
	friend ostream& operator<<(ostream&, const String&);
};

#endif