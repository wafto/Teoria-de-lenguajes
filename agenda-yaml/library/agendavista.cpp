#include "agendavista.h"

AgendaVista::AgendaVista() {
	agenda = new Agenda();
}

AgendaVista::~AgendaVista() {
	delete agenda;
}

void AgendaVista::inicia() {
	while (true) {
		limpiar();
		separador();
		switch (menu()) {
			case 'x': case 'X':
				limpiar();
				separador();
				cout << "-> Adios." << endl;
				separador();
				return;
			case 'v': case 'V':
				limpiar();
				separador();
				indice();
				separador();
				pausar();
				break;
			case 'c': case 'C':
				limpiar();
				separador();
				consulta();
				separador();
				pausar();
				break;
			case 'a': case 'A':
				limpiar();
				separador();
				alta();
				separador();
				pausar();
				break;
			case 'e': case 'E':
				limpiar();
				separador();
				cambio();
				separador();
				pausar();
				break;
			case 'd': case 'D':
				limpiar();
				separador();
				baja();
				separador();
				pausar();
				break;
			case 'w': case 'W':
				limpiar();
				separador();
				vaciar();
				separador();
				pausar();
				break;
			case 'l': case 'L':
				limpiar();
				separador();
				cargar();
				separador();
				pausar();
				break;
			case 'g': case 'G':
				limpiar();
				separador();
				guardar();
				separador();
				pausar();
				break;
		}
	}
}

char AgendaVista::menu() {
	string opcion;
	cout << "-> Menu de opciones" << endl;
	cout << "   [X] - Salir de la aplicacion." << endl;
	cout << "   [V] - Ver listado de contactos." << endl;
	cout << "   [C] - Consultar contacto indicado." << endl;
	cout << "   [A] - Agregar contacto a la agenda." << endl;
	cout << "   [E] - Editar contacto indicado." << endl;
	cout << "   [D] - Eliminar contacto indicado." << endl;
	cout << "   [W] - Vaciar la agenda de contactos." << endl;
	cout << "   [L] - Cargar archivo de contactos." << endl;
	cout << "   [G] - Guardar archivo de contactos." << endl;
	cout << "   Opcion: ";
	cin >> opcion;
	return opcion[0];
}

void AgendaVista::cargar() {
	string archivo;
	bool bandera;
	cout << "-> Indique el archivo a cargar: ";
	cin >> archivo;
	agenda->cargar(archivo.c_str(), &bandera);
	if (!bandera)
		cout << "-> No se pudo cargar el archivo correspondiente." << endl;
	else
		cout << "   Archivo cargado correctamente. Ahora la agenda tiene " << agenda->longitud() << " contactos." << endl;
}

void AgendaVista::guardar() {
	string archivo;
	bool bandera;
	cout << "-> Indique el nombre archivo a guardar (añade la extension .yaml): ";
	cin >> archivo;
	agenda->guardar(archivo.c_str(), &bandera);
	if (!bandera)
		cout << "-> No se pudo guardar el archivo correspondiente." << endl;
	else
		cout << "   Archivo guardado correctamente" << endl;
}

void AgendaVista::indice() {
	unsigned long tam = agenda->longitud();
	Contacto* contacto;
	cout << "-> Listado de contactos" << endl;
	if (tam > 0) {
		for (unsigned long i = 0; i < tam; i++) {
			contacto = (*agenda)[i];
			cout << "   [" << i << "] - " << contacto->nombre << " " << contacto->apellidos << endl;
		}
	} else {
		cout << "-> La agenda se encuentra vacia. agregue contactos o cargue un archivo." << endl;
	}
}

void AgendaVista::alta() {
	Contacto *contacto = new Contacto;
	if (contacto) {
		buffoff();
		cout << "-> Datos de alta de nuevo contacto." << endl;
		cout << "   - Nombre: ";    getline(cin, contacto->nombre);
		cout << "   - Apellidos: "; getline(cin, contacto->apellidos);
		cout << "   - R.F.C.: ";    getline(cin, contacto->rfc);
		do { 
			if (pregunta("   - Desea agregar telefono?")) {
				buffoff();
				Telefono telefono;
				cout << "     + Telefono: " << endl;
				cout << "       - tipo: ";   getline(cin, telefono.tipo);
				cout << "       - numero: "; getline(cin, telefono.numero);
				contacto->telefonos.push_back(telefono);
			} else {
				break;
			}
		} while (true);
		do {
			if (pregunta("   - Desea agregar correo?")) {
				buffoff();
				Correo correo;
				cout << "     + Correo: " << endl;
				cout << "       - tipo: ";   getline(cin, correo.tipo);
				cout << "       - email: ";  getline(cin, correo.email);
				contacto->correos.push_back(correo);
			} else {
				break;
			}
		} while (true);
		do {
			if (pregunta("   - Desea agregar domicilio?")) {
				buffoff();
				Domicilio domicilio;
				cout << "     + Domicilio: " << endl;
				cout << "       - tipo: ";      getline(cin, domicilio.tipo);
				cout << "       - direccion: "; getline(cin, domicilio.direccion);
				contacto->domicilios.push_back(domicilio);
			} else {
				break;
			}
		} while (true);
		if (pregunta("-> Dar de alta el contacto especificado?")) {
			bool bandera;
			cout << "   Se procede a guardar el nuevo contacto..." << endl;
			agenda->agregar(contacto, &bandera);
			if (bandera) {
				cout << "   Se guardo el nuevo contacto " << contacto->nombre << " " << contacto->apellidos << "." << endl;
			} else {
				cout << "   Hubo un error al intentar guardar el contacto (Falta de memoria)." << endl;
				delete contacto;
			}
		} else {
			delete contacto;
		}
	} else {
		cout << "-> Hubo un error al intentar crear el nuevo contacto (Falta de memoria)." << endl;
	}
}

void AgendaVista::baja() {
	unsigned long i = obtenid("->Escriba el id del contacto que quiere dar de baja: ");
	if (i >= 0 && i < agenda->longitud()) {
		Contacto* contacto = (*agenda)[i];
		string nombre = contacto->nombre + " " + contacto->apellidos;
		if (pregunta("-> Dar de baja el contacto " + nombre + "?")) {
			cout << "-> Se procede a dar de baja el contacto " << nombre << "." << endl;
			agenda->elimina(i);
			cout << "-> Se elimino de la agenda el contacto." << endl;
		}
	} else {
		cout << "-> No existe tal registro de contacto dentro de la agenda." << endl;
	}
}

void AgendaVista::cambio() {
	unsigned long i = obtenid("-> Escriba el id del contacto que quiere editar: ");
	if (i >= 0 && i < agenda->longitud()) {
		Contacto* contacto = (*agenda)[i];
		string nombre = contacto->nombre + " " + contacto->apellidos;
		if (pregunta("-> Editar el contacto " + nombre + "?")) {
			buffoff();
			if (pregunta(" - Desea editar el nombre (" + contacto->nombre + ")?")) {
				cout << "   - Nombre: "; getline(cin, contacto->nombre);
			}
			if (pregunta(" - Desea editar el apellido(s) (" + contacto->apellidos + ")?")) {
				cout << "   - Apellido(s): "; getline(cin, contacto->apellidos);
			}
			if (pregunta(" - Desea editar el R.F.C. (" + contacto->rfc + ")?")) {
				cout << "   - R.F.C.: "; getline(cin, contacto->rfc);
			}
			if (contacto->telefonos.size() > 0) {
				cout << " - Edicion de Telefono(s):" << endl;
				list<Telefono>::iterator t;
				for (t = contacto->telefonos.begin(); t != contacto->telefonos.end(); ++t) {
					if (pregunta("   - Desea editar (" + t->tipo + ": " + t->numero + ")?")) {
						if (pregunta("   - Desea eliminarlo?")) {
							contacto->telefonos.erase(t);
						} else {
							buffoff();
							cout << "     + Telefono: (" << t->tipo << ": "<< t->numero << ")" << endl;
							cout << "       - tipo: ";   getline(cin, t->tipo);
							cout << "       - numero: "; getline(cin, t->numero);	
						}
					}	
				}
			}
		}
	} else {
		cout << "-> No existe tal registro de contacto dentro de la agenda." << endl;
	}
}

void AgendaVista::consulta() {
	unsigned long k, i = obtenid("-> Esciba el id del contacto que quiere consultar: ");
	if (i >= 0 && i < agenda->longitud()) {
		Contacto* contacto = (*agenda)[i];
		cout << "-> Consulta de contacto" << endl;
		cout << "   Nombre: \t" << contacto->nombre << endl;
		cout << "   Apellidos: \t" << contacto->apellidos << endl;
		cout << "   R.F.C.: \t" << contacto->rfc << endl;
		if (contacto->telefonos.size() > 0) {
			cout << "   Telefono(s):" << endl;
			list<Telefono>::iterator t;
			k = 0;
			for (t = contacto->telefonos.begin(); t != contacto->telefonos.end(); ++t)
	 			cout << "   [" << k++ << "] - " << t->tipo << ": " << t->numero << endl;
		}
		if (contacto->correos.size() > 0) {
			cout << "   Correo(s):" << endl;
			list<Correo>::iterator c;
			k = 0;
			for (c = contacto->correos.begin(); c != contacto->correos.end(); ++c)
	 			cout << "   [" << k++ << "] - " << c->tipo << ": " << c->email << endl;
		}
		if (contacto->domicilios.size() > 0) {
			cout << "   Domicilio(s):" << endl;
			list<Domicilio>::iterator d;
			k = 0;
			for (d = contacto->domicilios.begin(); d != contacto->domicilios.end(); ++d)
	 			cout << "   [" << k++ << "] - " << d->tipo << ": " << d->direccion << endl;
		}
	} else {
		cout << "-> No existe tal registro de contacto dentro de la agenda." << endl;
	}
}

void AgendaVista::vaciar() {
	if (pregunta("->Desea vaciar por completo la agenda de contactos?")) {
		if (agenda->estaVacia()) {
			cout << "-> La agenda se encuentra actualmente vacia." << endl;
		} else {
			cout << "-> Se procede a vaciar la agenda..." << endl;
			unsigned long c = agenda->longitud(); 
			agenda->vaciar();
			cout << "-> Se vacio la agenda de contactos." << endl;
			cout << "   Se eliminaron " << c << " contactos." << endl;
		}
	} else {
		cout << "-> Se cancelo la accion de vaciar la agenda." << endl;
	}
}

void AgendaVista::separador() {
	for (int i = 0; i < 110; i++) cout << "-";
	cout << endl;
}

void AgendaVista::pausar() {
	cin.ignore(1024, '\n');
	cout << "Presione ENTER para continuar...";
	cin.get();
}

void AgendaVista::limpiar() {
	#ifdef WINDOWS
		system("cls");
	#else
		system("clear");
	#endif
}

void AgendaVista::buffoff() {
	cin.clear();
	cin.ignore(1024, '\n');
}

bool AgendaVista::pregunta(const string& pregunta) {
	string respuesta;
	cout << pregunta << " [S] para si, cualquier otra letra para no: ";
	cin >> respuesta;
	return respuesta == "s" || respuesta == "S";
}

unsigned long AgendaVista::obtenid(const string& oracion) {
	string indice;
	unsigned long i;
	cout << oracion;
	cin >> indice;
	istringstream stream(indice);
	stream >> i;
	return i;
}


