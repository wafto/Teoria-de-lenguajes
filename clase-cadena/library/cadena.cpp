#include <iostream>
#include <locale>
#include "cadena.h"

//Constructores
Cadena::Cadena() {
	mInfo = NULL;
	mLongitud = 0;
}

Cadena::Cadena(const char* c) {
	for (mLongitud = 0; c[mLongitud] != '\0'; mLongitud++);
	mInfo = new char[mLongitud];
	strcpy(mInfo, c);
}

Cadena::~Cadena() { 
	if (mInfo != NULL) delete mInfo; 
}

void Cadena::imprimir() {
	std::cout << mInfo << std::endl; 
}

int Cadena::longitud() {
	return mLongitud;
}

void Cadena::mayusculas() {
	for(int i = 0; i < mLongitud; i++) mInfo[i] = toupper(mInfo[i]);
}

void Cadena::minusculas() {
	for(int i = 0; i < mLongitud; i++) mInfo[i] = tolower(mInfo[i]);
}

void Cadena::recortar() {
	
}

char* Cadena::extraer(int pos, int tam) {
	
}

char* Cadena::remplazar(char* v, char* n) {
	
}