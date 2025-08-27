#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "pila.h"


int main(){
    Pila p;
    crearPila(25, p);
    char A[] = "(( )))( ";

    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == '(') apilar(1, p);
        else if (A[i] == ')' && esVaciaPila(p)) {
                std::cout << "Expresion no balanceada";
                return 0;
            } else {
                desapilar(p);
            }
    }

    if (esVaciaPila(p)) std::cout << "Expresion balanceada";
    else std::cout << "La expresion no es balanceada";
    
    destruirPila(p);

}