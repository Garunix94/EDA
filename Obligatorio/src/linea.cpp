/* 5512649 */ // sustituiir con los 7 dígitos de la cédula
#include "../include/linea.h"
#include "../include/cadena.h"
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
            nueva->sig = aux->sig;
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
    Linea aux = linea;
    unsigned int i = 0;
    while (aux != NULL){
        aux = aux->sig;
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

//*************************** PREDICADOS ********************** */

//Pos-Cond: retorna true si linea es vacía
bool esVaciaLinea(Linea linea);

//Pre-Cond: Retorna true si la Linea "numLinea" existe en la estructura "linea"
bool existeNumeroLinea(Linea linea, unsigned int numLinea);

//Pre-Cond: (esVaciaFila(fila1) && esVaciaFila(fila2)) retorna false
//Pos-Cond: retorna true si fila1 tiene los mismos caracteres 
//          y en el mismo orden que fila2
bool sonIgualesLineas(Linea linea1, Linea linea2);


//***************************** DESTRUCTORAS **************** */

//Pre-cond: la Linea "numLinea" existe en la Linea "linea"
//Pos-Cond: elimina la Linea de la estructura "linea" de la posicion "numLinea"
void eliminarLinea(Linea &linea, unsigned int numLinea);

//Pos-Cond: elimina toda la memoria de la estructura Linea "linea"
void destruirLinea(Linea &linea);
