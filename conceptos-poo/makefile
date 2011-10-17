applicaciones: app_instanciacion_1 app_instanciacion_2 app_herencia_1 app_herencia_2 app_polimorfismo_1 app_polimorfismo_2 app_privados_1 app_privados_2 app_protegidos_1 app_protegidos_2

# Sources de la biblioteca
punto.o: biblioteca/punto.cpp biblioteca/punto.h
	g++ -c biblioteca/punto.cpp

figura.o: biblioteca/figura.cpp biblioteca/figura.h
	g++ -c biblioteca/figura.cpp

# Applicaciones
instanciacion_1.o: instanciacion_1.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c instanciacion_1.cpp

app_instanciacion_1: punto.o figura.o instanciacion_1.o
	g++ -o app_instanciacion_1 punto.o figura.o instanciacion_1.o

instanciacion_2.o: instanciacion_2.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c instanciacion_2.cpp

app_instanciacion_2: punto.o figura.o instanciacion_2.o
	g++ -o app_instanciacion_2 punto.o figura.o instanciacion_2.o

herencia_1.o: herencia_1.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c herencia_1.cpp

app_herencia_1: punto.o figura.o herencia_1.o
	g++ -o app_herencia_1 punto.o figura.o herencia_1.o

herencia_2.o: herencia_2.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c herencia_2.cpp

app_herencia_2: punto.o figura.o herencia_2.o
	g++ -o app_herencia_2 punto.o figura.o herencia_2.o

polimorfismo_1.o: polimorfismo_1.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c polimorfismo_1.cpp

app_polimorfismo_1: punto.o figura.o polimorfismo_1.o
	g++ -o app_polimorfismo_1 punto.o figura.o polimorfismo_1.o

polimorfismo_2.o: polimorfismo_2.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c polimorfismo_2.cpp

app_polimorfismo_2: punto.o figura.o polimorfismo_2.o
	g++ -o app_polimorfismo_2 punto.o figura.o polimorfismo_2.o

privados_1.o: privados_1.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c privados_1.cpp

app_privados_1: punto.o figura.o privados_1.o
	g++ -o app_privados_1 punto.o figura.o privados_1.o

privados_2.o: privados_2.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c privados_2.cpp

app_privados_2: punto.o figura.o privados_2.o
	g++ -o app_privados_2 punto.o figura.o privados_2.o

protegidos_1.o: protegidos_1.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c protegidos_1.cpp

app_protegidos_1: punto.o figura.o protegidos_1.o
	g++ -o app_protegidos_1 punto.o figura.o protegidos_1.o

protegidos_2.o: protegidos_2.cpp biblioteca/punto.h biblioteca/figura.h
	g++ -c protegidos_2.cpp

app_protegidos_2: punto.o figura.o protegidos_2.o
	g++ -o app_protegidos_2 punto.o figura.o protegidos_2.o

# Elimina los archivos compilados
clean:
	rm punto.o figura.o
	rm instanciacion_1.o app_instanciacion_1
	rm instanciacion_2.o app_instanciacion_2
	rm herencia_1.o app_herencia_1
	rm herencia_2.o app_herencia_2
	rm polimorfismo_1.o app_polimorfismo_1
	rm polimorfismo_2.o app_polimorfismo_2
	rm privados_1.o app_privados_1
	rm privados_2.o app_privados_2
	rm protegidos_1.o app_protegidos_1
	rm protegidos_2.o app_protegidos_2

