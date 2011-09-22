#include <iostream>
#include <locale>
#include <list>
#include "cadena.h"

// Constructores
Cadena::Cadena() {
	mInfo = NULL;
	mLongitud = 0;
}

Cadena::Cadena(const char* c) {
	poner(c);
}

// Destructor
Cadena::~Cadena() { 
	if (mInfo != NULL) delete mInfo; 
}

// Metodos
int Cadena::tam(const char* c) {
	int i = 0;
	for (; c[i] != '\0'; i++);
	return i;
}

void Cadena::poner(const char* c) {
	if (mInfo != NULL)
		delete mInfo;
	mLongitud = tam(c);
	mInfo = new char[mLongitud];
	strcpy(mInfo, c);
}

void Cadena::invierte() {
	char aux;
	int limite = mLongitud / 2;
	for(int i = 0; i < limite; i++) {
		aux = mInfo[i];
		mInfo[i] = mInfo[mLongitud - i - 1];
		mInfo[mLongitud - i - 1] = aux;
	}
}

void Cadena::imprimir() {
	std::cout << mInfo << std::endl; 
}

int Cadena::longitud() {
	return mLongitud;
}

void Cadena::mayusculas() {
	for (int i = 0; i < mLongitud; i++) mInfo[i] = toupper(mInfo[i]);
}

void Cadena::minusculas() {
	for (int i = 0; i < mLongitud; i++) mInfo[i] = tolower(mInfo[i]);
}

void Cadena::recortar() {
	int pos, sop;
	for (pos = 0; pos < mLongitud; pos++)
		if (mInfo[pos] != ' ') break;
	for (sop = 0; sop < mLongitud; sop++)
		if (mInfo[mLongitud - 1 - sop] != ' ') break;
	char* nueva = extraer(pos, mLongitud - pos - sop);
	poner(nueva);
	delete nueva;
}

void Cadena::remplazar(char* o, char* r) {
	int so = tam(o);
	int sr = tam(r);
	if (mLongitud < so)
		return;
	std::list<char> cbuffer; 
	int bandera = 0;
	int limite = mLongitud - so;
	int i = 0;
	for (; i < limite; i++) {
		bandera = 1;
		for (int j = 0; j < so; j++) {
			if (mInfo[i + j] != o[j]) {
				bandera = 0;
				break;
			}
		}
		if (bandera == 1) {
			for (int k = 0; k < sr; k++)
				cbuffer.push_back(r[k]);
			i += so - 1;
			continue;
		}
		cbuffer.push_back(mInfo[i]);
	}
	for (; i < mLongitud; i++)
		cbuffer.push_back(mInfo[i]);
	int nTam = cbuffer.size();
	char* nueva = new char[nTam];
	for (i = 0; i < nTam; i++) {
		nueva[i] = cbuffer.front();
		cbuffer.pop_front();
	}
	poner(nueva);
	delete nueva;
}

char* Cadena::extraer(int pos, int tam) {
	char* extraido;
	if (pos >= 0 && pos < mLongitud - 1 && tam > 0) {
		tam = mLongitud - pos < tam ? mLongitud - pos : tam;
		extraido = new char[tam];
		for(int i = 0; i < tam; i++)
			extraido[i] = mInfo[pos + i];
	}
	return extraido;
}


