#include "figura.h"

// Constructor
Figura::Figura(int tam) {
	if (tam < 3) tam = 3;
	numPuntos = tam;
	mPuntos = new Punto*[numPuntos];
	for (int i = 0; i < numPuntos; i++)
		mPuntos[i] = new Punto();
}

// Destructor
Figura::~Figura() {
	for (int i = 0; i < numPuntos; i++)
		delete mPuntos[i];
	delete [] mPuntos;
}

// Metodos
int Figura::getNumPuntos() const {
	return numPuntos;
}

void Figura::setPunto(int posicion, Punto *p) {
	if (posicion >= 0 && posicion < numPuntos) {
		if (mPuntos[posicion] != 0)
			delete mPuntos[posicion];
		mPuntos[posicion] = p;
	}
}