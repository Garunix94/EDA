#ifndef FECHA_H
#define FECHA_H

typedef struct _cola *Cola;

void crearCola(Cola &cola);
/*Crear una cola vacia con 10 limite de elementos*/

bool esLlenaCola(Cola cola);
/*Devuelve True si la cola está llena False en otro caso*/

bool esVaciaCola(Cola cola);
/*Devuleve True si la cola está vacía*/

void insertarFinal(int elem, Cola &cola);
//Pre-condición: !esLLenaCola
/*Inserta un elem al final de cola*/

int primeroEnCola(Cola cola);
//Pre-condición: !esVaciaCola
/*Devuelve el primer elemento de la cola*/

void quitarPrimero(Cola &cola);
//Pre-condición: !esVaciaCola
/*Elimina el primer elemento de cola*/

void destruirCola(Cola &cola);
/*Elimina todos los elementos de cola*/

#endif