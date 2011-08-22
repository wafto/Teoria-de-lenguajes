/**
 * senoidal.c
 * Programa que imprime en pantalla una senoidal con asteriscos.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 21 de Agosto del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: gcc -o app_senoidal senoidal.c
 * Ejecucion: ./app_senoidal
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAFICA_X 140
#define GRAFICA_Y 40

int main() {
    int i, j;
    double valor;
    char grafica[GRAFICA_Y][GRAFICA_X];
    
    /* Llena el arreglo de la grafica con espacios */
    for ( i = 0; i < GRAFICA_Y; i++ ) {
        for ( j = 0; j < GRAFICA_X; j++ ) {
            grafica[i][j] = ' ';
        }
    }
    
    /* Inserta los asteriscos en las posiciones adecuadas */
    for ( j = 0; j < GRAFICA_X; j++) {
        valor = sin( (double) j / ( GRAFICA_X / 32 ) ) * (GRAFICA_Y / 3) + 0.5;
        grafica[(int) valor + (GRAFICA_Y / 2)][j] = '*';
    }
    
    /* Imprime el arreglo de la grafica */
    for ( i = 0; i < GRAFICA_Y; i++ ) {
        for ( j = 0; j < GRAFICA_X; j++ ) {
            printf("%c", grafica[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}