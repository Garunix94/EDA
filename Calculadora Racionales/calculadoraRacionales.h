#ifndef CALCULADORARACIONEALES_H
#define CALCULADORARACIONEALES_H

typedef struct Racional *num;

num crearNumero(int a, int b);

num simplificar (num numero);

num sumar(num a, num b);

num restar(num a, num b);

num dividir(num a, num b);

num multiplicar(num a, num b);

void destruir(num a);

void mostrar(num numero);

#endif