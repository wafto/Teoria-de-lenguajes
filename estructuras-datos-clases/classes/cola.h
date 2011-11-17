#ifndef COLA_H
#define COLA_H

template <class T>
class Cola {
private:
	struct nodo {
		T dato;
		nodo* siguiente;
	};
	nodo* inicio;
	nodo* final;
public:
	Cola();
	~Cola();
	void insertar(T);
	T sacar();
	T verFinal();
	bool estaVacia();
};

#endif

template <class T>
Cola<T>::Cola() {
	inicio = 0;
	final = 0;
}

template <class T>
Cola<T>::~Cola() {
	while (!estaVacia()) sacar();
}

template <class T>
void Cola<T>::insertar(T dato) {
	nodo* nuevo = new nodo;
	if (nuevo) {
		nuevo->dato = dato;
		nuevo->siguiente = 0;
		if (estaVacia()) {
			inicio = final = nuevo;
		} else {
			final->siguiente = nuevo;
			final = nuevo;
		}
	}
}

template <class T>
T Cola<T>::sacar() {
	T dato;
	if (!estaVacia()) {
		nodo* aux = inicio;
		dato = aux->dato;
		inicio = aux->siguiente;
		delete aux; 
	}
	return dato;
}

template <class T>
T Cola<T>::verFinal() {
	T dato;
	if (!estaVacia())
		dato = final->dato;
	return dato;
}

template <class T>
bool Cola<T>::estaVacia() {
	return inicio == 0;
}

