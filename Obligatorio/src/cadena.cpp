/* 5512649 */

#include "../include/cadena.h"
#include "time.h"
#include <stdio.h>

struct _rep_cadena {
    char letra;
    _rep_cadena * sig;
};

Cadena crearCadenaVacia(){
    return NULL;
}

void agregarCaracteresCadena(Cadena &cadena, char* texto){
    int i = 0;
    while (texto[i] != '\0'){
        Cadena nuevo = new _rep_cadena();
        nuevo->letra = texto[i];
        nuevo->sig = NULL;
        if (cadena == NULL) {
            cadena = nuevo;
            i++;
        }else{
            Cadena iterador = cadena;
            while (iterador->sig != NULL) {
                iterador = iterador->sig;
            }
            iterador->sig = nuevo;
            i++;
        }
    }
}

bool esVaciaCadenaCaracteres (Cadena cadena){
    return cadena == NULL;
}

bool sonIgualesCadenas(Cadena cadena1, Cadena cadena2){
    Cadena it1 = cadena1;
    Cadena it2 = cadena2;
    while (it1 != NULL && it2 != NULL && cadena1->letra == cadena2->letra){
        it1 = it1->sig;
        it2 = it2->sig;
    }
    return it1 == NULL && it2 == NULL;
}

char* convertirCadenaArregloChar(Cadena cadena){
    char* A;
    A = new char[100];
    int i = 0;
    Cadena iterador = cadena;
    while (iterador != NULL) {
        A[i] = iterador->letra;
        iterador = iterador->sig;
        i++;
    }
    A[i] = '\0';
    return A;
}

void destruirCadena (Cadena &cadena){
    Cadena borrar = cadena;
    while (cadena != NULL) {
        cadena = cadena->sig;
        delete borrar;
        borrar = cadena;
    }
}
