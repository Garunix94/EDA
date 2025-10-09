/* 5512649 */
#include "../include/linea.h"
#include "../include/cadena.h"
#include <stdio.h>
#include <time.h>

struct _rep_linea {
    unsigned int numLinea;
    Cadena cadena;
    _rep_linea* sig;
    _rep_linea* ant;
};

Linea crearLineaVacia(){
    return NULL;
}

void insertarLinea(Linea &linea, char* texto, unsigned int numLinea){
    Linea nueva = new _rep_linea();
    nueva->numLinea = numLinea;
    nueva->cadena = crearCadenaVacia();
    agregarCaracteresCadena(nueva->cadena, texto);
    nueva->sig = NULL;
    nueva->ant = NULL;
    
    if (linea == NULL) linea = nueva;
    else{
        Linea aux = linea;
        while (aux->sig != NULL && aux->numLinea < numLinea) aux = aux->sig;
        
        if (aux->numLinea != numLinea){
            aux->sig = nueva;
            nueva->ant = aux;
        } else if (aux == linea && linea->numLinea == numLinea){
            nueva->sig = aux;
            aux->ant = nueva;
            linea = nueva;
            while (aux != NULL) {
                aux->numLinea++;
                aux = aux->sig;
            }
        } else if (aux == linea && aux->sig != NULL){
            nueva->ant = aux;
            nueva->sig = aux->sig;
            aux->sig->ant = nueva;
            aux->sig = nueva;
            aux = nueva->sig;
            while (aux != NULL){
                aux->numLinea++;
                aux = aux->sig;
            }
        } else {
            nueva->sig = aux;
            nueva->ant = aux->ant;
            aux->ant->sig = nueva;
            aux->ant = nueva;
            while (aux != NULL){
                aux->numLinea++;
                aux = aux->sig;
            }
        }
    }
}

Linea siguienteLinea(Linea linea){
    return linea->sig;
}

Linea anteriorLinea(Linea linea){
    return linea->ant;
}

unsigned int cantidadLineas(Linea linea){
    unsigned int i = 0;
    while (linea != NULL){
        linea = linea->sig;
        i++;
    }
    return i;
}

unsigned int getNumeroLinea(Linea linea){
    return linea->numLinea;
}

char* obtenerTextoLinea (Linea linea, unsigned int numLinea){
    Linea aux = linea;
    while (aux->numLinea != numLinea) aux = aux->sig;
    char* A;
    A = convertirCadenaArregloChar(linea->cadena);
    return A;
}

bool esVaciaLinea(Linea linea){
    return linea == NULL;
}

bool existeNumeroLinea(Linea linea, unsigned int numLinea){
    Linea aux;
    aux = linea;
    while (aux != NULL && linea->numLinea != numLinea) aux = aux->sig;
    return aux->numLinea == numLinea;
}

bool sonIgualesLineas(Linea linea1, Linea linea2){
    return sonIgualesCadenas(linea1->cadena, linea2->cadena);
}

void eliminarLinea(Linea &linea, unsigned int numLinea){
    Linea aux;
    aux = linea;
    while (aux->numLinea != numLinea) aux = aux->sig;
    destruirCadena(aux->cadena);
    if (aux == linea && aux->sig == NULL){
        delete linea;
        linea = NULL;
        aux = NULL;
    }else if (aux == linea && aux->sig != NULL){
        aux = aux->sig;
        delete linea;
        aux->sig = NULL;
        linea = aux;
    }else if (aux->sig == NULL){
        aux->ant->sig = NULL;
        delete aux;
        aux = NULL;
    }else{
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        Linea borrar;
        borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    while (aux != NULL){
        aux->numLinea--;
        aux =aux->sig;
    }
}

void destruirLinea(Linea &linea){
    Linea aux;
    Linea borrar;
    aux = linea;
    while (aux->sig != NULL) aux = aux->sig;
    while (aux != NULL){
        borrar = aux;
        destruirCadena(borrar->cadena);
        aux =aux->ant;
        delete borrar;
    }
    linea = NULL;
}
