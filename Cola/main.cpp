#include <iostream>
#include <time.h>
#include "cola.h"

int main(){
    Cola nueva;
    crearCola(nueva);
    insertarFinal(10, nueva);
    int num = primeroEnCola(nueva);
    std::cout << "El primer elemento es" << num<< std::endl;
}