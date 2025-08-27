#include <stdio.h>
#include <stdlib.h>
#include "calculadoraRacionales.h"

int main(){
    int a1 = 0;
    int b1 = 0;
    int a2 = 0;
    int b2 = 0;
    char A[10];
    char B[10];
    int i = 0;

    printf("Ingrese la primera fraccion (n/d): ");
    scanf("%s", &A);
    while (A[i] != '/' && A[i] != '\0') i++;

    int mult = 1;
    for (int j = i - 1; j >= 0; j--) {
        a1 += (A[j] - '0') * mult;
        mult *= 10;
    }
    
    i++;
    while (A[i] != '\0') {
        b1 = b1 * 10 + (A[i] - '0');
        i++;
    }


    i = 0;
    printf("Ingrese la segunda fraccion (n/d): ");
    scanf("%s", &B);
    while (B[i] != '/' && B[i] != '\0') i++;

    mult = 1;
    for (int j = i - 1; j >= 0; j--) {
        a2+= (B[j] - '0') * mult;
        mult *= 10;
    }
    
    i++;
    while (B[i] != '\0') {
        b2 = b2* 10 + (B[i] - '0');
        i++;
    }

    num r1 = crearNumero(a1, b1);
    num r2 = crearNumero(a2, b2);
    num total;

    total = sumar(r1, r2);

    destruir(r1);
    destruir(r2);

    simplificar(total);
    mostrar(total);

    destruir(total);

    return 0;

}