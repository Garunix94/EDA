#include <iostream>
#include <time.h>
#include "cola.h"
const int n = 10;

struct _nodoCola {
    unsigned int elem;
    _nodoCola *sig;
};

struct _cola {
    _nodoCola *inicio;
    _nodoCola *final;
    unsigned int cantidad;
    bool estaEnCola[n];
};


void crearCola(Cola &cola) {
    cola = new _cola;
    cola->inicio = NULL;
    cola->final = NULL;
    cola->cantidad = 0;
    for (int i = 0; i < 10; i++) {
        cola->estaEnCola[i]= false;
    }
}

bool esLlenaCola(Cola cola){ return cola->cantidad == n; }

bool esVaciaCola(Cola cola){ return cola->inicio == NULL; }

void insertarFinal(int elem, Cola &cola){
    if (elem <= n) {
        if (!esLlenaCola(cola)) {
        _nodoCola * nuevo = new _nodoCola;
        nuevo->elem = elem;
        nuevo->sig = NULL;
        cola->cantidad++;
        if (esVaciaCola(cola)) {
            cola->final = nuevo;
            cola->inicio = nuevo;
            cola->estaEnCola[elem] = true;
        }else{
            cola->final->sig = nuevo;
            cola->final = nuevo;
            cola->estaEnCola[elem] = true;
        }
    }
    }else{
        std::cout << "La colo admite solo elementos del 0 al 9";
    }
}

int primeroEnCola(Cola cola){ return cola->inicio->elem; }

void quitarPrimero(Cola &cola){
    _nodoCola * aux = cola->inicio;
    cola->inicio = cola->inicio->sig;
    cola->estaEnCola[aux->elem] = false;
    cola->cantidad--;
    delete aux;
    if (cola->inicio == NULL) cola->final = NULL;
}

void destruirCola(Cola &cola){
    while (!esVaciaCola(cola)) {
        quitarPrimero(cola);
    }
    delete cola;
    cola = NULL;    
}



