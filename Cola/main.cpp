#include <iostream>
#include <time.h>
#include "cola.h"

int main(){
    Cola Cola;
    crearCola(Cola);
    insertarFinal(10, Cola);
    std::cout << primeroEnCola(Cola) << " es el primero en la cola" <<std::endl;
    
}