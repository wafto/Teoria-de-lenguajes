/**
 * matriz.c
 * Programa que suma, multiplica, escala, imprime y obtiene el determinante de matrices definidos con estructuras.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboración: 20 de Agosto del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: gcc -o app_matriz matriz.c
 * Ejecución:   ./app_matriz
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int filas;
    int columnas;
    double** info;
} Matriz;

Matriz* crearMatriz(int filas, int columnas) {
    int i, j;
    Matriz* matriz = (Matriz*) malloc( sizeof (Matriz) );
    if ( filas > 1 && columnas > 1 && matriz != NULL ) {
        matriz->filas = filas;
        matriz->columnas = columnas;
        matriz->info = (double**) malloc( sizeof(double*) * matriz->filas);
        for ( i = 0; i < matriz->filas; i++ ) {
            matriz->info[i] = (double*) malloc( sizeof(double) * matriz->columnas);
            for ( j = 0; j < matriz->columnas; j++ ) {
                matriz->info[i][j] = 0.0;
            }
        }
        return matriz;
    } else {
        return NULL;
    }
}

int eliminarMatriz(Matriz* matriz) {
    int i;
    if ( matriz != NULL && matriz->info != NULL ) {
        for ( i = 0; i < matriz->filas; i++ ) {
            free ( matriz->info[i] );
        }
        free ( matriz->info );
        free ( matriz );
        return 1;
    }
    return 0;
}

Matriz* identidadMatriz(int tam) {
    int i;
    Matriz* matriz = crearMatriz(tam, tam);
    if ( matriz != NULL ) {
        for ( i = 0; i < tam; i++ ) {
            matriz->info[i][i] = 1.0;
        }
    }
    return matriz;
}

void imprimirMatriz(const Matriz* matriz) {
    int i, j;
    if ( matriz != NULL ) {
        for ( i = 0; i < matriz->filas; i++) {
            for ( j = 0; j < matriz->columnas; j++ ) {
                printf("%f\t", matriz->info[i][j]);
            }
            printf("\n");
        }
    }
}

Matriz* escalarMatriz(const Matriz* ma, double escalar) {
    int i, j;
    Matriz* matriz = NULL;
    if ( ma != NULL ) {
        matriz = crearMatriz(ma->filas, ma->columnas);
        if (matriz == NULL) return matriz;
        for ( i = 0; i < matriz->filas; i++ ) {
            for ( j = 0; j < matriz->columnas; j++ ) {
                matriz->info[i][j] = ma->info[i][j] * escalar;
            }
        }
    }
    return matriz;
}

Matriz* sumarMatriz(const Matriz* ma, const Matriz* mb) {
    int i, j;
    Matriz* matriz = NULL;
    if ( ma != NULL && mb != NULL && ma->filas == mb->filas && ma->columnas == mb->columnas ) {
        matriz = crearMatriz(ma->filas, ma->columnas);
        if (matriz == NULL) return matriz;
        for ( i = 0; i < matriz->filas; i++ ) {
            for ( j = 0; j < matriz->columnas; j++ ) {
                matriz->info[i][j] = ma->info[i][j] + mb->info[i][j];
            }
        }
    }
    return matriz;
}

Matriz* multiplicarMatriz(const Matriz* ma, const Matriz* mb) {
    int i, j, k;
    Matriz* matriz = NULL;
    if ( ma != NULL && mb != NULL && ma->columnas == mb->filas ) {
        matriz = crearMatriz(ma->filas, mb->columnas);
        for ( i = 0; i < matriz->filas; i++ ) {
            for ( j = 0; j < matriz->columnas; j++ ) {
                for ( k = 0; k < ma->columnas; k++ ) {
                    matriz->info[i][j] += ma->info[i][k] * mb->info[k][j]; 
                }
            }
        }
    }
    return matriz;
}

double determinanteMatriz(const Matriz* matriz) {
    int i, k, x, y;
    double signo, determinante = 0.0;
    Matriz* Aux = NULL;
    if ( matriz == NULL || matriz->filas != matriz->columnas )
        return determinante;
    if ( matriz->filas == 1 )
        return matriz->info[0][0];
    if ( matriz->filas == 2 )
        return matriz->info[0][0] * matriz->info[1][1] - matriz->info[0][1] * matriz->info[1][0];
    for ( i = 0; i < matriz->columnas; i++ ) {
        signo = (i % 2 == 0) ? 1.0 : -1.0;
        Aux = crearMatriz(matriz->filas - 1, matriz->columnas - 1);
        for ( k = 0, x = 0; k < matriz->columnas; k++ ) {
            if ( k == i ) continue;
            for ( y = 0; y < Aux->filas; y++ ) {
                Aux->info[y][x] = matriz->info[y + 1][k];
            }
            x++;
        }
        determinante += signo * matriz->info[0][i] * determinanteMatriz(Aux);
        eliminarMatriz(Aux);
    }
    return determinante;
}


int main() {
    Matriz* M1 = crearMatriz(4,3);
    Matriz* M2 = crearMatriz(3,5);
    Matriz* M3 = identidadMatriz(4);
    Matriz* Aux;
    
    printf("\nPrimera matriz:\n");
    M1->info[0][0] = 1.0;
    M1->info[0][1] = 2.0;
    M1->info[1][0] = 3.0;
    M1->info[1][1] = 4.0;
    imprimirMatriz(M1);
    
    printf("\nSegunda matriz:\n");
    M2->info[0][0] = 1.3;
    M2->info[0][1] = 2.3;
    M2->info[1][0] = 3.3;
    M2->info[1][1] = 4.3;
    imprimirMatriz(M2);
    
    printf("\nTercera matriz (Identidad 2):\n");
    imprimirMatriz(M3);
    
    printf("\nSuma de las matrices:\n");
    Aux = sumarMatriz(M3, M3);
    imprimirMatriz(Aux);
    eliminarMatriz(Aux);
    
    printf("\nPrimera matriz por un escalar:\n");
    Aux = escalarMatriz(M1, 3.25);
    imprimirMatriz(Aux);
    eliminarMatriz(Aux);
    
    printf("\nMultiplicacion de las matrices:\n");
    Aux = multiplicarMatriz(M1, M2);
    imprimirMatriz(Aux);
    eliminarMatriz(Aux);
    
    printf("\nDeterminante de la matriz:\n");
    Aux = crearMatriz(2,2);
    Aux->info[0][0] =  1.0; Aux->info[0][1] =  3.0;
    Aux->info[1][0] =  5.0; Aux->info[1][1] =  7.0;
    imprimirMatriz(Aux);
    printf("El determinante es : %f\n", determinanteMatriz(Aux));
    eliminarMatriz(Aux);
    
    printf("\nDeterminante de la matriz:\n");
    Aux = crearMatriz(4,4);
    Aux->info[0][0] =  1.0; Aux->info[0][1] =  3.0; Aux->info[0][2] =  5.0; Aux->info[0][3] =  2.0;
    Aux->info[1][0] =  0.0; Aux->info[1][1] = -1.0; Aux->info[1][2] =  3.0; Aux->info[1][3] =  4.0;
    Aux->info[2][0] =  2.0; Aux->info[2][1] =  1.0; Aux->info[2][2] =  9.0; Aux->info[2][3] =  6.0;
    Aux->info[3][0] =  3.0; Aux->info[3][1] =  2.0; Aux->info[3][2] =  4.0; Aux->info[3][3] =  8.0;
    imprimirMatriz(Aux);
    printf("El determinante es : %f\n", determinanteMatriz(Aux));
    eliminarMatriz(Aux);
    
    eliminarMatriz(M1);
    eliminarMatriz(M2);
    eliminarMatriz(M3);
    return 0;
}

