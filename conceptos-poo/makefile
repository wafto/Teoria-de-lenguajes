applicaciones: app_instanciacion_1 app_instanciacion_2 app_herencia_1 app_herencia_2 app_polimorfismo_1 app_polimorfismo_2

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

# Elimina los archivos compilados
clean:
	rm punto.o figura.o
	rm instanciacion_1.o app_instanciacion_1
	rm instanciacion_2.o app_instanciacion_2
	rm herencia_1.o app_herencia_1
	rm herencia_2.o app_herencia_2
	rm polimorfismo_1.o app_polimorfismo_1
	rm polimorfismo_2.o app_polimorfismo_2

