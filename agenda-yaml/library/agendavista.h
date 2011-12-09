#ifndef AGENDAVISTA_H
#define AGENDAVISTA_H

#include "agenda.h"

class AgendaVista {
private:
	Agenda* agenda;
public:
	// Constructor
	AgendaVista();
	// Destructor
	~AgendaVista();
	// Inicia la aplicacion
	void inicia();
	// Menu de la aplicacion
	char menu();
	// Cargar archivo
	void cargar();
	// Guarda archivo
	void guardar();
	// Listado de los contactos de la Agenda
	void indice();
	// Alta
	void alta();
	// Baja
	void baja();
	// Cambio
	//void cambio();
	// Consulta
	void consulta();
	// Vacia
	void vaciar();
protected:
	// Linea separador 
	void separador();
	// Nos permite hacer algo similar al system pause pero multiplataforma 
	void pausar();
	// Limpia la pantalla de la consola
	void limpiar();
	// Limpia el buffer
	void buffoff();
};

#endif