#ifndef FIGURA_H
#define FIGURA_H

#include "punto.h"

class Figura {
private:
	int numPuntos;
	Punto** mPuntos;
protected:
	// Metodos
	void setPunto(int, Punto*);
public:
	// Constructor
	Figura(int);
	// Destructor
	~Figura();
	// Metodos
	int getNumPuntos() const;
};

#endif

