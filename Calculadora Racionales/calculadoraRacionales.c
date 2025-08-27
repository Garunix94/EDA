#include <stdio.h>
#include <stdlib.h>
#include "calculadoraRacionales.h"


struct Racional {
    int n;
    int d;
};

num crearNumero(int a, int b){
    
    num numero = malloc(sizeof(struct Racional));
    numero->n = a;
    numero->d = b;

    return numero;

}

int mcd(int num, int den){
    if (num < 0){
        num = -num;
    }

    if (den < 0){
        den = -den;
    }
    
    
    while (num % den != 0) {
        int aux = num % den;
        num =  den;
        den = aux;
    }

    return den;

}

num simplificar (num numero){
    int divisor = mcd(numero->n, numero->d);
    numero->n = numero->n / divisor;
    numero->d = numero->d / divisor;
    
    return numero;
    
}


num sumar(num a, num b){
    num total = malloc(sizeof(struct Racional));
    total->n = (a->n * b->d) + (b->n * a->d);
    total->d = a->d * b->d;

    return total;
}

num restar(num a, num b){
    num total = malloc(sizeof(struct Racional));
        total->n = (a->n * b->d) - (b->n * a->d);
        total->d = a->d * b->d;
        
        return total;
}

num dividir(num a, num b){
    num total = malloc(sizeof(struct Racional));
    total->n = a->n * b->d;
    total->d = a->d * b->n;

    return total;
}

num multiplicar(num a, num b){
    num total = malloc(sizeof(struct Racional));
    total->n = a->n * b->n;
    total->d = a->d * b->d;

    return total;
}

void destruir(num a){
    free(a);
}

void mostrar(num numero){
    printf("%d/%d", numero->n, numero->d);
}

