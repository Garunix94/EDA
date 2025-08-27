#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main() {
    Fecha Daniel = crearFecha();
    Fecha Xandra = crearFecha();

    if (compararFecha(Daniel, Xandra) < 0){
        printf("Daniel cumple antes que Xandra\n");
        printf("Daniel: ");
        mostrarFecha(Daniel);
        printf("\n");
        printf("Xandra: ");
        mostrarFecha(Xandra);

    }else{
        printf("Xandra cumple antes que Daniel\n");
        printf("Daniel: ");
        mostrarFecha(Daniel);
        printf("\n");
        printf("Xandra: ");
        mostrarFecha(Xandra);
    }

    destruirFecha(Daniel);
    destruirFecha(Xandra);
    

}