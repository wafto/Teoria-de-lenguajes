#ifndef AGENDA_H
#define AGENDA_H

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

struct Domicilio {
	string tipo;
	string direccion;
};

struct Correo {
	string tipo;
	string email;
};

struct Telefono {
	string tipo;
	string numero; 
};

struct Contacto {
	string nombre;
	string apellidos;
	string rfc;
	list <Telefono> telefonos;
	list <Correo> correos;
	list <Domicilio> domicilios;
};

void operator >> (const YAML::Node&, Domicilio&);
void operator >> (const YAML::Node&, Correo&);
void operator >> (const YAML::Node&, Telefono&);
void operator >> (const YAML::Node&, Contacto&);

YAML::Emitter& operator << (YAML::Emitter&, const Domicilio&);
YAML::Emitter& operator << (YAML::Emitter&, const Correo&);
YAML::Emitter& operator << (YAML::Emitter&, const Telefono&);
YAML::Emitter& operator << (YAML::Emitter&, const Contacto&);

class Agenda {
private:
	struct nodo {
		Contacto* contacto;
		nodo* anterior;
		nodo* siguiente;
	};
	nodo* inicio;
	nodo* final;
	unsigned long tam;
public:
	// Constructor
	Agenda();
	// Destructor
	~Agenda();
	// Metodo cargar la cual permite tomar los valores de la agenda de un archivo yaml
	void cargar(const char*, bool*);
	// Metodo guardar la cual permite guardar la agenda en un archivo yaml especificado
	void guardar(const char*, bool*);
	// Regresa el estado de la agenda verdaderao si esta vacia y falso lo contrario
	bool estaVacia() const;
	// Regresa la cantidad de contactos de la agenda
	unsigned long longitud() const;
	// Metodos CRUD (Create, Read, Update, Delete)
	// Agrega un nuevo contacto a la agenda
	void agregar(Contacto*, bool*);
	// Quita todos los contactos en la agenda
	void vaciar();
	// Obtiene el contacto en el indice especificado
	Contacto* en(const unsigned long);
	// Lo mismo que el metodo en pero con sobrecarga de corchetes
	Contacto* operator [] (const unsigned long);
	// Elimina el contacto en el indice especificado
	void elimina(const unsigned long);
};

#endif
