/* 5512649 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/version.h"
#include "../include/linea.h"
#include <time.h>
#include <iostream>
#include <string.h>


struct _rep_version {
    char * num;
    int nivel;
    int cantLineas;
    Linea linea;
    _rep_version * sig;
    _rep_version * hijo;
};



Version crearVersionVacia(){
    return NULL;
}

//FUNCION AUXILIAR
int nivelVersion(Version version){
    int cont = 1;
    for (int i = 0; version->num[i] != '\0'; i++){
        if (version->num[i] == '.') cont++;       
    }
    return cont;
}

void crearVersion (Version &version, char *num_version){
    if (version == NULL || version->sig == NULL || strcmp(version->sig->num, num_version) > 0){
        Version nueva = new _rep_version();
        strcpy(nueva->num, num_version);
        nueva->nivel = nivelVersion(nueva);
        nueva->cantLineas = 0;
        nueva->linea = crearLineaVacia();
        if (version == NULL) version =nueva;
        else if (strcmp(version->num, num_version) < 0) {
            nueva->sig = version->sig;
            version = nueva;
        }
    } else {
        crearVersion(version->sig, num_version);
    }
}


Version obtenerVersion(Version &version, char *numVersion){
    if (version->num == numVersion){
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
    while (!esVaciaLinea(aux)){
        char* A = obtenerTextoLinea(aux, getNumeroLinea(aux));
        std::cout << A << std::endl;
        aux = siguienteLinea(aux);
    }
}

Version siguienteVersion(Version version){
    return version->sig;
}

char* nombreVersion(Version version){
    char* A = version->num;
    return A;
}

bool esVaciaVersion (Version version, char* numeroVersion){
    Version res = obtenerVersion(version, numeroVersion);
    return esVaciaLinea(res->linea);
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