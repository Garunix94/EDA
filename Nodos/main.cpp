#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "nodo.h"

int main(){
    Lista inicio = crearLista();
    std::cout << "Ya creo la lista inicio" << std::endl;
    insertarElementoLista(inicio, 10);
    std::cout << "Inserto el primer elemento" << std::endl;
    insertarElementoLista(inicio, 20);
    insertarElementoLista(inicio, 30);

    Lista final = crearLista();
    int num;
    std::cout << "Ya creo la lista final y la variable num" << std::endl;
    while (!esVacia(inicio)){
        num = primerElementoLista(inicio);
        std::cout << num << std::endl;
        insertarElementoLista(final, num);
    }
    std::cout << "Termino el bucle while" << std::endl;
    if (!esVacia(final)) {
        std::cout << "Bo, la lista no es vacia" << std::endl;
    }
}