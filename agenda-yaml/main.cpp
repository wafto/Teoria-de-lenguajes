/**
 * main.cpp
 * Programa que se comporta como una agenda para el proyecto final. En mi caso muy particular
 * se esta utilizando yaml-cpp la cual me permite mantener los datos de contactos guardados en
 * un archivo con extension y formato yaml.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 06 de Diciembre del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: g++ -I/usr/local/include -L/usr/local/lib -lyaml-cpp -o applicacion main.cpp \
 *              library/agenda.cpp library/agendavista.cpp
 * Ejecucion: ./applicacion
 *
 * Notas:
 * Para compilar este programa es necesario tener instalado yaml-cpp. La documentacion para
 * dicho fin esta en la pagina de http://code.google.com/p/yaml-cpp/.
 * YAML es una forma de serializar datos de manera amigable para las personas y para el objetivo
 * de este proyecto se utiliza para guardar los contactos de la agenda. Para encontrar mas 
 * informacion sobre las especificaciones de YAML buscalo en google o bien en http://www.yaml.org/
 */
#include "library/agenda.h"
#include "library/agendavista.h"

int main() {
 	AgendaVista vista;
 	vista.inicia();
	return 0;
}

