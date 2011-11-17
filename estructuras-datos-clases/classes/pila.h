#ifndef PILA_H
#define PILA_H

template <class T>
class Pila {
private:
	struct nodo {
		T dato;
		nodo* anterior;
	};
	nodo* inicio;
public:
	Pila();
	~Pila();
	void insertar(T);
	T sacar();
	T verTope();
	bool estaVacia();
};

#endif

template <class T>
Pila<T>::Pila() {
	inicio = 0;
}

template <class T>
Pila<T>::~Pila() {
	while (!estaVacia()) sacar();
}

template <class T>
void Pila<T>::insertar(T dato) {
	nodo* nuevo = new nodo;
	if (nuevo) {
		nuevo->dato = dato;
		nuevo->anterior = inicio;
		inicio = nuevo;
	}
}

template <class T>
T Pila<T>::sacar() {
	T dato;
	if (!estaVacia()) {
		nodo* aux = inicio;
		inicio = inicio->anterior;
		dato = aux->dato;
		delete aux;
	}
	return dato;
}

template <class T>
T Pila<T>::verTope() {
	T dato;
	if (inicio)
		dato = inicio->dato;
	return dato;
}

template <class T>
bool Pila<T>::estaVacia() {
	return inicio == 0;
}

