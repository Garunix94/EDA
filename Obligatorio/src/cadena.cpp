/* 5512649 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "time.h"

struct _rep_cadena {
    char letra;
    _rep_cadena * sig;
};

/* Operaciones de Cadena */

//Pos-Cond: retorna una cadena de caracteres vacia
Cadena crearCadenaVacia(){
    return NULL;
}

//Pre-Cond: esVaciaCadenaCaracteres(cadena)retorna true.
//Pos-Cond: agrega los caracteres de cadena a la fila vaica "fila"
void agregarCaracteresCadena(Cadena &cadena, char* texto){
    int i = 0;
    while (texto[i] != '\0'){
        Cadena nuevo = new _rep_cadena();
        nuevo->letra = texto[i];
        nuevo->sig == NULL;
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

//retorna true si la cadena es vacia
bool esVaciaCadenaCaracteres (Cadena cadena){
    return cadena == NULL;
}

//retorna true si la cadena1 es igual a la cadena2, false en caso contrario
bool sonIgualesCadenas(Cadena cadena1, Cadena cadena2){
    Cadena it1 = cadena1;
    Cadena it2 = cadena2;
    while (it1 != NULL && it2 != NULL && cadena1->letra == cadena2->letra){
        it1 = it1->sig;
        it2 = it2->sig;
    }
    return it1 == NULL && it2 == NULL;
}

//retorna el dato char* de la tupla tup
//pre-cond retorna un puntero a un arreglo dinamico 
char* convertirCadenaArregloChar(Cadena cadena){
    char* A;
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

//Pos-Cond: libera toda la memoria de cadena
void destruirCadena (Cadena &cadena){
    Cadena borrar = cadena;
    while (cadena != NULL) {
        cadena = cadena->sig;
        delete borrar;
        borrar = cadena;
    }
}
