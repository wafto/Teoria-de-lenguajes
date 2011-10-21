#ifndef HASHMAP_H
#define HASHMAP_H

#include "string.h"

struct word {
	String english;
	String spanish;
};

class HashMap {
private:
	word *wds;
	long maxw;
public:
	// (1/2 punto) Carga diccionario Español/Ingles
	HashMap();
	// (1/2 punto) Libera memoria
	~HashMap();
	// (4 puntos) Busca la traduccion de la palabra wd
	String operator [] (const String&) const;
};

#endif