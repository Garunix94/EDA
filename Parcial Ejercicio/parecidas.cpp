#include <stdio.h>
#include <stdlib.h>

int main(){}

struct _nodo_lista{
    int info;
    _nodo_lista* sig;
};

typedef _nodo_lista* Lista;



bool parecida(Lista l1, Lista l2){}



int largoLista(Lista l){
    int res = 0;
    while (l != NULL){
        res++;
    }
    return res;
}