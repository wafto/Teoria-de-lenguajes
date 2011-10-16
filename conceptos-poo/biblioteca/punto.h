#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
	double mX;
	double mY;
public:
	// Constructor
	Punto();
	Punto(double, double);
	// Destructor
	~Punto();
	// Metodos
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;
};

#endif

