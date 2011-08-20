/**
 * sumas-grandes.c
 * Programa que realiza sumas grandes atraves de cadenas de digitos enteros.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 20 de Agosto del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: gcc -o app_sumas_grandes sumas-grandes.c
 * Ejecucion: ./app_sumas_grandes
 */
#include <stdio.h>
#include <stdlib.h>

typedef char* biginteger;

int charToInt(char n, int defaultInt) {
    if ( (int) n > 47 && (int) n < 58 )
        return (int) n - 48;
    return defaultInt;
}

biginteger sumar(biginteger m, biginteger n) {
    int valor = 0, resTam, mTam, nTam, i;
    biginteger resultado = NULL;
    if ( m != NULL && n != NULL ) {
        for ( mTam = 0; m[mTam] != '\0'; mTam++ );
        for ( nTam = 0; n[nTam] != '\0'; nTam++ );
        resTam = ( mTam > nTam ? mTam : nTam ) + 1;
        resultado = (char*) malloc( sizeof(char) * resTam );
        for ( i = 0; i < resTam; i++ ) resultado[i] = '0';
        for ( i = resTam; i > 0; i--) {
            if ( mTam > 0) valor += charToInt(m[--mTam], 0);
            if ( nTam > 0) valor += charToInt(n[--nTam], 0);
            resultado[i - 1] = (char) (valor % 10 + 48);
            valor /= 10;
        }
    }
    return resultado;
}

int main() {
    biginteger a = "0101010101010101010101010101010101";
    biginteger b = "202020202020202020202020202020";
    biginteger c = "898989898989898989898989898980";
    biginteger d = "75";
    biginteger e = "25";
    biginteger resultado;
    
    resultado = sumar(a,b);
    printf("%s\n", resultado);
    free(resultado);
    
    resultado = sumar(b,a);
    printf("%s\n", resultado);
    free(resultado);
    
    resultado = sumar(b,c);
    printf("%s\n", resultado);
    free(resultado);
    
    resultado = sumar(d,e);
    printf("%s\n", resultado);
    free(resultado);
    
    return 0;
}