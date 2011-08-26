/**
 * float-hexadecimal.c
 * Programa que imprime un numero de punto flotante a su forma hexadecimal.
 * Elaborado por: Aftab Hussain Miranda
 * Fecha de elaboracion: 25 de Agosto del 2011.
 *
 * Repositorio: https://github.com/wafto
 * Compilacion: gcc -o app_float_hexadecimal float-hexadecimal.c
 * Ejecucion: ./app_float_hexadecimal
 */
#include <stdio.h>

void dumpFloatToHex(float number) {
    int i, value, aux = *(int*) &number;
    for ( i = sizeof(int) * 8 - 4; i >= 0; i-= 4) {
        value = aux >> i & 15;
        printf("%c", value > 9 ? (char)value + 55 : (char)value + 48);
    }
}

int main() {
    dumpFloatToHex(-9.0);
    return 0;
}