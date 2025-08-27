#include <iostream>
#include "pila.h"
#include <time.h>

struct _nodo {
    int elem;
    _nodo * sig;
};

struct _pila {
    unsigned int cota;
    unsigned int cantidad;
    _nodo * sig;
};


void crearPila(int cota, Pila &p){
    p = new _pila;
    p->cota = cota;
    p->cantidad = 0;
    p->sig = NULL;

}

bool esVaciaPila(Pila p) { return p->sig == NULL; }

bool esLlenaPila(Pila p) { return p->cota == p->cantidad; }

void apilar(int i, Pila &p) {
    if (!esLlenaPila(p)) {
        _nodo *Nuevo = new _nodo;
        Nuevo->elem = i;
        Nuevo->sig = p->sig;
        p->sig = Nuevo;
        p->cantidad++;
    }    
}

int cima(Pila p){ return p->sig->elem; }

void desapilar(Pila &p){
    _nodo *aux = p->sig;
    p->sig = p->sig->sig;
    p->cantidad--;
    delete aux;
}

void destruirPila(Pila &p){
    while (!esVaciaPila(p)){
        desapilar(p);
    }
    delete p;
    p = NULL;
    
}

