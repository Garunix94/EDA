/* 5512649 */

#include "../include/version.h"
#include "../include/linea.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct _rep_version {
    char * num;
    Linea linea;
    _rep_version * sig;
    _rep_version * hijo;
};



Version crearVersionVacia(){
    return NULL;
}

void crearVersion(Version &version, char *num_version){
    if (version == NULL || strcmp(num_version, version->num) == 0)  {
        Version nuevo = new _rep_version;
        nuevo->num = new char[15];
        strcpy(nuevo->num, num_version);
        nuevo->linea = crearLineaVacia();
        nuevo->sig = version;
        nuevo->hijo = NULL;
        if (version == NULL || strcmp(version->num, nuevo->num) == 0){
            version = nuevo;
        }
        if (nuevo->sig != NULL && strcmp(num_version,nuevo->sig->num) == 0){
            nuevo = nuevo->sig;
            while (nuevo != NULL){
                unsigned int valor = atoi(nuevo->num);
                valor++;
                char* string = new char[10];
                sprintf(string, "%d", valor);nuevo->num++;
                strcpy(nuevo->num,string);
                nuevo = nuevo->sig;
            }
        }
        
    }else{
        crearVersion(version->sig, num_version);
    }
}

Version obtenerVersion(Version &version, char *numVersion){
    if (strcmp(version->num, numVersion) == 0){
        Version nueva = version;
        return nueva;
    } else {
        return obtenerVersion(version->sig, numVersion);
    }
}

void agregarFilaVersion (Version &version, char* numeroVersion, char *textoFila,unsigned int numLinea){
    Version insertar = obtenerVersion(version, numeroVersion);
    insertarLinea(insertar->linea, textoFila, numLinea);
}

void imprimirVersion(Version version, char* numeroVersion){
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

Version siguienteVersion(Version version){
    return version->sig;
}

char* nombreVersion(Version version){
    char* A = new char[20];
    strcpy(A, version->num);
    return A;
}

int numeroUltimaVersion(Version version){
    if (esVaciaVersion(siguienteVersion(version))){
        return atoi(nombreVersion(version));
    } else {
        return numeroUltimaVersion(siguienteVersion(version));
    }
}

int numeroUltimaLineaVersion(Version version){
    return cantidadLineas(version->linea);
}

bool esVaciaVersion (Version version){
    return version == NULL;
}

bool existeVersion (Version version, char* numeroVersion){
    while (version != NULL){
        int condicion = strcmp(version->num, numeroVersion);
        if (condicion == 0) return true;
        version = siguienteVersion(version);        
    }
    return version != NULL;
}

void eliminarLineaVersion (Version &version, char* numeroVersion, unsigned int numLinea){
    Version aux = version;
    aux = obtenerVersion(aux, numeroVersion);
    eliminarLinea(aux->linea, numLinea);
}

void destruirVersion (Version &version, char* numeroVersion){
    Version borrar = version;
    borrar = obtenerVersion(borrar, numeroVersion);
    destruirLinea(borrar->linea);
    delete borrar;
}

void destruirTodasLasVersiones(Version &version){
    Version borrar = version;
    while (version != NULL){
        version = version->sig;
        destruirLinea(borrar->linea);
        delete borrar;
        borrar = version;
    }
    version = NULL;
}

