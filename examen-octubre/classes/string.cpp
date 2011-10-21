#include "string.h"

String::String() {
	str = 0;
	len = 0;
}

String::String(const char* s) {
	for (len = 0; s[len] != '\0'; len += 1);
	str = new char[len];
	for (int i = 0 ; i < len; i += 1) str[i] = s[i];
}

String::String(const String& c) {
	len = c.lenght();
	str = new char[len];
	for (int i = 0; i < len; i += 1) str[i] = c[i];
}

String::String(const long l) {
	stringstream stream;
	stream << l;
	const char* cadena = stream.str().c_str();
	for (len = 0; cadena[len] != '\0'; len += 1);
	str = new char[len];
	for (int i = 0 ; i < len; i += 1) str[i] = cadena[i];
}

String::~String() {
	if (str != 0) delete [] str;
}

void String::operator = (const String& c) {
	if (str != 0) delete [] str;
	str = new char[c.lenght()];
	for (len = 0; len < c.lenght(); len += 1) str[len] = c[len];  
}

void String::operator = (long l) {
	stringstream stream;
	stream << l;
	const char* cadena = stream.str().c_str();
	if (str != 0) delete [] str;
	for (len = 0; cadena[len] != '\0'; len += 1);
	str = new char[len];
	for (int i = 0 ; i < len; i += 1) str[i] = cadena[i];
}

void String::operator = (const char* s) {
	if (str != 0) delete [] str;
	for (len = 0; s[len] != '\0'; len += 1);
	str = new char[len];
	for (int i = 0 ; i < len; i += 1) str[i] = s[i];
}

String String::operator + (const String& c) {
	long longitud = c.lenght() + len;
	char *cadena = new char[longitud];
	long i = 0;
	for (; i < len; i++) cadena[i] = str[i];
	for (int j = 0; j < c.lenght(); j++)
		cadena[i + j] = c[j];
	String nueva(cadena);
	delete [] cadena;
	return nueva;
}

bool String::operator == (const String& c) {
	if (c.lenght() != len) return false;
	for (int i = 0; i < len; i++)
		if (str[i] != c[i]) return false;
	return true;
}

long* String::search(const String& c) {
	long* encontrados;
	if (c.lenght() < len) {
		encontrados = new long[matches(c)];
		int k = 0, i = 0;
		for (; i < len - c.lenght(); i++) {
			bool flag = true; 
			for (int j = 0; j < c.lenght(); j++)
				if (c[j] != str[j + i]) { flag = false; break; }
			if (flag) { 
				encontrados[k++] = i;
				i += c.lenght();
			}
		}
	}
	return encontrados;
}

long String::lenght() const {
	return len;
}

char String::operator [] (const long i) const {
	return i >= 0 && i < len ? str[i] : '\0';
}

long String::matches(const String& c) const {
	long matches = 0;
	if (c.lenght() < len) {
		int i = 0;
		for (; i < len - c.lenght(); i++) {
			bool flag = true; 
			for (int j = 0; j < c.lenght(); j++)
				if (c[j] != str[j + i]) { flag = false; break; }
			if (flag) { matches += 1; i += c.lenght(); }
		}
	}
	return matches;
}

ostream& operator<<(ostream& out, const String& s) {
	for (int i = 0; i < s.lenght(); i++)
		out << s[i];
	return out;
}


