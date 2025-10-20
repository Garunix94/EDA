/* 5512649 */

#include "../include/version.h"
#include "../include/linea.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct _rep_version {
    int num[4];
    int tope;
    Linea linea;
    _rep_version * sH;      //Siguiente hermano
    _rep_version * pH;      //Primer Hijo
    _rep_version * padre;
    bool existe;
};


Version nuevoNodo(int *num, int nivel) {
    Version v = new _rep_version;
    for (int i = 0; i < 4; i++) v->num[i] = num[i];
    v->tope = nivel;
    v->pH = NULL;
    v->sH = NULL;
    v->padre = NULL;
    v->existe = true;
    v->linea = NULL; // si aún no tiene contenido
    return v;
}


void correrVersiones(Version v) {
    while (v != NULL) {
        v->num[v->tope - 1]++; // incrementa el número del nivel actual
        if (v->pH != NULL)
            correrVersiones(v->pH); // correr los hijos también
        v = v->sH; // siguiente hermano
    }
}


Version crearVersionVacia(){
    int k = 1;
    Version puntero = new _rep_version;
    puntero->pH = NULL;
    puntero->sH = NULL;
    puntero->existe = false;
    puntero->num[0] = k;
    Version aux = puntero->pH;

    while (k < 9){
        k++;
        aux = new _rep_version;
        puntero->pH = NULL;
        puntero->sH = NULL;
        puntero->existe = false;
        puntero->num[0] = k;
        aux = aux->pH;
    }
    return puntero;
}
                   
bool sonIguales(int * a, int * b){
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void copiarNumero(int *a, int *b){
    for (int i = 0; i < 4; i++){
        a[i] = b[i];
    }
}


//CORREGIR LUEGO
void imprimirNumero(int * num) {
    for (int i = 0; i < 4; i++) {
        printf("%d", num[i]);
        if (i < 4 - 1)
            printf(".");
    }
}

bool existeArbol(Version version){
    return version->existe == true;
}



//Los inserta pero no mueve versiones de lugar
void crearVersion(Version &version, int *num_version, int nivel) {
    printf("Aca esta el error\n");
    // Caso base: el árbol está vacío
    if (version == NULL) {
        version = nuevoNodo(num_version, nivel);
    }

    // Si estamos insertando en el mismo nivel
    if (nivel == version->tope) {
        Version actual = version;
        Version anterior = NULL;

        // Buscar la posición donde insertar
        while (actual != NULL && actual->num[nivel - 1] < num_version[nivel - 1]) {
            anterior = actual;
            actual = actual->sH;
        }

        // Si encontramos una versión igual -> hay que correr las siguientes
        if (actual != NULL && actual->num[nivel - 1] == num_version[nivel - 1]) {
            correrVersiones(actual);
        }

        // Crear nuevo nodo
        Version nuevo = nuevoNodo(num_version, nivel);

        // Insertar al inicio
        if (anterior == NULL) {
            nuevo->sH = version;
            version = nuevo;
        } else {
            nuevo->sH = anterior->sH;
            anterior->sH = nuevo;
        }
        return;
    }

    // Si el nivel no coincide, bajar al hijo adecuado
    Version hijo = version->pH;
    while (hijo != NULL && hijo->num[version->tope] < num_version[version->tope]) {
        hijo = hijo->sH;
    }

    // Si no existe el hijo correspondiente, lo creamos
    if (hijo == NULL || hijo->num[version->tope] > num_version[version->tope]) {
        // Crear el hijo padre intermedio si falta
        Version padreNuevo = nuevoNodo(num_version, version->tope + 1);
        padreNuevo->padre = version;
        padreNuevo->sH = version->pH;
        version->pH = padreNuevo;
        hijo = padreNuevo;
    }

    // Llamada recursiva
    crearVersion(hijo, num_version, nivel);
}



Version obtenerVersion(Version version, int*  numVersion){
    if (version == NULL) 
        return NULL;
    else{
        if (!sonIguales(version->num, numVersion)){
            Version esta_sH = obtenerVersion(version->sH, numVersion);
            if (esta_sH != NULL)
                return esta_sH;
            else
                return obtenerVersion(version->pH, numVersion);            
        }
        else
            return version;
    }
}

void agregarFilaVersion (Version &version, int * numeroVersion, char *textoFila,unsigned int numLinea){
    Version insertar = obtenerVersion(version, numeroVersion);
    insertarLinea(insertar->linea, textoFila, numLinea);
}

void imprimirNumeroVersionesAux(Version version, int nivel) {
    if (version != NULL) {
        // Mostrar sangría
        for (int i = 0; i < nivel; i++)
            printf("    ");

        // Imprimir número de versión
        imprimirNumero(version->num);
        printf("\n");

        // Primero mostrar hijos (nivel + 1)
        imprimirNumeroVersionesAux(version->pH, nivel + 1);

        // Luego mostrar hermanos (mismo nivel)
        imprimirNumeroVersionesAux(version->sH, nivel);
    }
}

void imprimirNumeroVersiones(Version version) {
    while ( version != NULL && version->existe) {
        imprimirNumeroVersionesAux(version->sH, 1);
        version = version->pH;
    }
    
}

void imprimirVersion(Version version, int * numeroVersion){
    Version res = obtenerVersion(version, numeroVersion);
    Linea aux = res->linea;
    if (esVaciaLinea(aux)) printf("No contiene lineas\n");
    
    int renglon = 1;
    while (!esVaciaLinea(aux)){
        char* A = obtenerTextoLinea(aux, getNumeroLinea(aux));
        //std::cout << A << std::endl; 
        printf("%d>     %s\n",renglon, A);
        renglon++;
        aux = siguienteLinea(aux);
    }
}

Version hermanoVersion(Version version){
    return version->sH;
}

Version hijoVersion(Version version){
    return version->pH;
}

int* nombreVersion(Version version) {
    int *A = new int[4];
    copiarNumero(A, version->num);
    return A;
}

int numeroUltimaVersion(Version version){
    /*if (esVaciaVersion(siguienteVersion(version))){
        return atoi(nombreVersion(version));
    } else {
        return numeroUltimaVersion(siguienteVersion(version));
    }*/
   return 0;
}

int numeroUltimaLineaVersion(Version version){
    return cantidadLineas(version->linea);
}

bool esVaciaVersion (Version version){
    return version == NULL;
}

bool existeVersion(Version version, int * numeroVersion) {
    bool existe = false;
    if (version != NULL) {
        // Comparar el número de esta versión con el buscado
        if (sonIguales(version->num, numeroVersion)) {
            existe = true;
        } else {
            // Buscar en el hijo
            existe = existeVersion(version->pH, numeroVersion);
            // Si no se encontró en el hijo, buscar en el hermano
            if (!existe) {
                existe = existeVersion(version->sH, numeroVersion);
            }
        }
    }

    return existe;
}

void eliminarLineaVersion (Version &version, int * numeroVersion, unsigned int numLinea){
    Version aux = version;
    aux = obtenerVersion(aux, numeroVersion);
    eliminarLinea(aux->linea, numLinea);
}

void destruirVersion (Version &version, int * numeroVersion){
    Version borrar = version;
    borrar = obtenerVersion(borrar, numeroVersion);
    destruirLinea(borrar->linea);
    delete borrar;
}

void destruirTodasLasVersiones(Version &version){
    if (version != NULL){
        destruirTodasLasVersiones(version->pH);
        destruirTodasLasVersiones(version->sH);
        delete version;
        version = NULL;
    }
}

