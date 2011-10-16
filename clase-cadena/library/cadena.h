#ifndef CADENA_H
#define CADENA_H

class Cadena {
	private:
		char* mInfo;
		int mLongitud;
	protected:
		int tam(const char* c);
	public:
		// Constructoress
		Cadena();
		Cadena(const char* c);
		// Destructor
		~Cadena();
		// Metodos
		void poner(const char* c);
		void invierte();
		void imprimir(); 
		int longitud();
		void mayusculas();
		void minusculas();
		void recortar();
		void remplazar(char* o, char* r);
		char* extraer(int pos, int tam);
};

#endif