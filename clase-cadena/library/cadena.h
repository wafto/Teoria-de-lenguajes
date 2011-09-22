#ifndef CADENA_H
#define CADENA_H

class Cadena {
	private:
		char* mInfo;
		int mLongitud;
	public:
		// Constructoress
		Cadena();
		Cadena(const char* c);
		// Destructor
		~Cadena();
		// Metodos
		void invierte();
		void imprimir();
		int longitud();
		void mayusculas();
		void minusculas();
		void recortar();
		char* extraer(int pos, int tam);
		char* remplazar(char* v, char* n);
};

#endif