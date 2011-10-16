#include "punto.h"

// Constructor
Punto::Punto() {
	mX = 0.0;
	mY = 0.0;
}

Punto::Punto(double x, double y) {
	mX = x;
	mY = y;
}

// Destructor
Punto::~Punto() {
	
}

// Metodos
void Punto::setX(double x) {
	mX = x;
}

void Punto::setY(double y) {
	mY = y;
}

double Punto::getX() const {
	return mX;
}

double Punto::getY() const {
	return mY;
}
