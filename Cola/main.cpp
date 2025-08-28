#include <iostream>
#include <time.h>
#include "cola.h"

int main(){
<<<<<<< HEAD
    Cola Cola;
    crearCola(Cola);
    insertarFinal(10, Cola);
    std::cout << primeroEnCola(Cola) << " es el primero en la cola" <<std::endl;
    
=======
    Cola nueva;
    crearCola(nueva);
    insertarFinal(10, nueva);
    int num = primeroEnCola(nueva);
    std::cout << "El primer elemento es" << num<< std::endl;
>>>>>>> f4a27257f1f4f1c69f86e3fb4b4f6c68ecd14cfe
}