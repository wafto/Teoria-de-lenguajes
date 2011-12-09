#include "agenda.h"

void operator >> (const YAML::Node& node, Domicilio& domicilio) {
	node["tipo"] >> domicilio.tipo;
	node["direccion"] >> domicilio.direccion;
}

void operator >> (const YAML::Node& node, Correo& correo) {
	node["tipo"] >> correo.tipo;
	node["email"] >> correo.email; 
}

void operator >> (const YAML::Node& node, Telefono& telefono) {
	node["tipo"] >> telefono.tipo;
	node["numero"] >> telefono.numero;
}

void operator >> (const YAML::Node& node, Contacto& contacto) {
	node["nombre"] >> contacto.nombre;
	node["apellidos"] >> contacto.apellidos;
	node["rfc"] >> contacto.rfc;
	const YAML::Node& telefonos = node["telefonos"];
	for (int i = 0; i < telefonos.size(); i++) {
		Telefono telefono;
		telefonos[i] >> telefono;
		contacto.telefonos.push_back(telefono);
	}
	const YAML::Node& correos = node["correos"];
	for (int i = 0; i < correos.size(); i++) {
		Correo correo;
		correos[i] >> correo;
		contacto.correos.push_back(correo);
	}
	const YAML::Node& domicilios = node["domicilios"];
	for (int i = 0; i < domicilios.size(); i++) {
		Domicilio domicilio;
		domicilios[i] >> domicilio;
		contacto.domicilios.push_back(domicilio);
	}
}

YAML::Emitter& operator << (YAML::Emitter& emitter, const Domicilio& domicilio) {
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "tipo" << YAML::Value << domicilio.tipo;
	emitter << YAML::Key << "direccion" << YAML::Value << domicilio.direccion;
	emitter << YAML::EndMap;
	return emitter;
}

YAML::Emitter& operator << (YAML::Emitter& emitter, const Correo& correo) {
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "tipo" << YAML::Value << correo.tipo;
	emitter << YAML::Key << "email" << YAML::Value << correo.email;
	emitter << YAML::EndMap;
	return emitter;
}

YAML::Emitter& operator << (YAML::Emitter& emitter, const Telefono& telefono) {
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "tipo" << YAML::Value << telefono.tipo;
	emitter << YAML::Key << "numero" << YAML::Value << telefono.numero;
	emitter << YAML::EndMap;
	return emitter;
}

YAML::Emitter& operator << (YAML::Emitter& emitter, const Contacto& contacto) {
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "nombre" << YAML::Value << contacto.nombre;
	emitter << YAML::Key << "apellidos" << YAML::Value << contacto.apellidos;
	emitter << YAML::Key << "rfc" << YAML::Value << contacto.rfc;
    // Aregamos los telefonos
    emitter << YAML::Key << "telefonos" << YAML::Value;
    emitter << YAML::BeginSeq;
    list<Telefono>::const_iterator t;
	for (t = contacto.telefonos.begin(); t != contacto.telefonos.end(); ++t)	
	 	emitter << *t;
	emitter << YAML::EndSeq;
	// Agregamos los correos
	emitter << YAML::Key << "correos" << YAML::Value;
    emitter << YAML::BeginSeq;
    list<Correo>::const_iterator c;
	for (c = contacto.correos.begin(); c != contacto.correos.end(); ++c)	
	 	emitter << *c;
	emitter << YAML::EndSeq;
	// Agregamos los domicilios
	emitter << YAML::Key << "domicilios" << YAML::Value;
    emitter << YAML::BeginSeq;
    list<Domicilio>::const_iterator d;
	for (d = contacto.domicilios.begin(); d != contacto.domicilios.end(); ++d)	
	 	emitter << *d;
	emitter << YAML::EndSeq;
	emitter << YAML::EndMap;
	return emitter;
}

// Clase Agenda
Agenda::Agenda() {
	inicio = final = 0;
	tam = 0;
}

Agenda::~Agenda() {
	vaciar();
}

void Agenda::cargar(const char* archivo, bool* bandera) {
	*bandera = false;
	ifstream fin(archivo);
	if (fin.is_open()) {
		try {
			YAML::Parser parser(fin);
			YAML::Node doc;
			parser.GetNextDocument(doc);
			bool flag;
			for (int i = 0; i < doc.size(); i++) {
				Contacto* contacto = new Contacto;
				if (contacto) {
					doc[i] >> *contacto;
					agregar(contacto, &flag);
				}
	 		}
	 		*bandera = true;
	 	} catch (YAML::ParserException& e) {
	 		// cout << e.what() << endl;
	 	}
		fin.close();
	}
}

void Agenda::guardar(const char* archivo, bool* bandera) {
	*bandera = false;
	ofstream fout(archivo);
	if (fout) {
		YAML::Emitter emitter;
		if (!estaVacia()) {
			emitter << YAML::BeginSeq;
			for (nodo* aux = inicio; aux != 0; aux = aux->siguiente)
				emitter << *aux->contacto;
			emitter << YAML::EndSeq;
		}
		fout << emitter.c_str();
		fout.close();
		if (fout.good())
			*bandera = true;
	}
}

bool Agenda::estaVacia() const {
	return longitud() == 0;
}

unsigned long Agenda::longitud() const {
	return tam;
}

void Agenda::agregar(Contacto* contacto, bool* bandera) {
	*bandera = false;
	nodo* nuevo = new nodo;
	if (nuevo) {
		nuevo->contacto = contacto;
		nuevo->siguiente = 0;
		if (estaVacia()) {
			nuevo->anterior = 0;
			inicio = final = nuevo;
		} else {
			nuevo->anterior = final;
			final->siguiente = nuevo;
			final = nuevo;
		}
		tam += 1;
		*bandera = true;
	}
}

void Agenda::vaciar() {
	if (!estaVacia()) {
		nodo *aux;
		while (final != 0) {
			aux = final;
			final = final->anterior;
			delete aux->contacto;
			delete aux;
			tam -= 1;
		}
	}
}

Contacto* Agenda::en(const unsigned long indice) {
	Contacto* contacto = 0;
	if (!estaVacia() && indice < longitud()) {
		nodo *aux = inicio;
		for (unsigned long i = 0; i < indice; i++)
			aux = aux->siguiente;
		contacto = aux->contacto;
	}
	return contacto;
}

Contacto* Agenda::operator [] (const unsigned long indice) {
	return en(indice);
}

void Agenda::elimina(const unsigned long indice) {
	if (!estaVacia() && indice < longitud()) {
		nodo* aux = inicio;
		if (longitud() == 1) {
			inicio = final = 0;
		} else {
			for (unsigned long i = 0; i < indice; i++)
				aux = aux->siguiente;
			if (aux == inicio) {
			inicio = aux->siguiente;
			inicio->anterior = 0;
			} else if (aux == final) {
				final = aux->anterior;
				final->siguiente = 0;
			} else {
				aux->siguiente->anterior = aux->anterior;
				aux->anterior->siguiente = aux->siguiente;
			}
		}
		tam -= 1;
		delete aux->contacto;
		delete aux;
	}
}







