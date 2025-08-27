#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "nodo.h"

struct _nodo {
    int elem;
    _nodo * sig;
};


Lista crearLista(){
    Lista l = NULL;
    return l;
}

int primerElementoLista(Lista &l){
    int num = l->elem;
    Lista aux = l;
    l = l->sig;
    delete(aux);
    return num;
}

void insertarElementoLista(Lista &l, int elem){
    Lista nodo = new _nodo;
    nodo->elem = elem;
    nodo->sig = NULL;
    if (l == NULL) l = nodo;
    else{
        Lista iterador = l;
        while (iterador->sig != NULL) {
            iterador = iterador->sig;
        }
        iterador->sig = nodo;
    }
}



bool esVacia(Lista l){
    return (l == NULL);
}

void destruirLista(Lista &l){
    if (l == NULL) perror("La lista ya esta vacia");
    else{
        Lista iterador = l;
        while (iterador->sig != NULL) {
            iterador = iterador->sig;
            delete(l);
            l = iterador;
        }
    }
}