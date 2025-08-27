#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "pila.h"


int main(){
    Pila p;
    crearPila(5, p);
    std::cout << "Se creo la pila\n";

    apilar(1, p);
    apilar(2, p);
    apilar(3, p);
    apilar(4, p);
    apilar(5, p);
    if (esLlenaPila) {
        std::cout << "Se lleno toda la pila\n\n";
    }

    std::cout << cima(p) << " Se quito de la pila\n";
    desapilar(p);
    std::cout << cima(p) << " Se quito de la pila\n";
    desapilar(p);
    std::cout << cima(p) << " Se quito de la pila\n";
    desapilar(p);
    std::cout << cima(p) << " Se quito de la pila\n";
    desapilar(p);
    std::cout << cima(p) << " Se quito de la pila\n";
    desapilar(p);

    if (esVaciaPila) {
        std::cout << "\nLa pila esta vacia\n";
    }

    destruirPila(p);
    std::cout << "Se libero la memoria, chau";
    
}

