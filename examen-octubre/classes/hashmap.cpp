#include "hashmap.h"

HashMap::HashMap() {
	maxw = 10;
	wds = new word[maxw];
	wds[0].spanish = "casa";        wds[0].english = "house";
	wds[1].spanish = "limon";       wds[1].english = "lemon";
	wds[2].spanish = "escuela";     wds[2].english = "school";
	wds[3].spanish = "manzana";     wds[3].english = "apple";
	wds[4].spanish = "libro";       wds[4].english = "book";
	wds[5].spanish = "cuaderno";    wds[5].english = "notebook";
	wds[6].spanish = "fuego";       wds[6].english = "fire";
	wds[7].spanish = "cama";        wds[7].english = "bed";
	wds[8].spanish = "computadora"; wds[8].english = "computer";
	wds[9].spanish = "semidios";    wds[9].english = "aftab";
}

HashMap::~HashMap() {
	delete [] wds;
}

String HashMap::operator [] (const char* s) const {
	String aux(s);
	return (*this)[aux];
}

String HashMap::operator [] (const String& s) const {
	String aux(s);
	for (int i = 0; i < maxw; i++)
		if (wds[i].english == aux) return wds[i].spanish;
	return aux;
}

