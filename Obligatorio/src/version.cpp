/* 5512649 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/version.h"
#include "../include/linea.h"
#include <time.h>
#include <string.h>
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
    if (version == NULL || strcmp(num_version, version->num) < 0) {
        Version nuevo = new _rep_version;
        nuevo->num = new char[15];
        strcpy(nuevo->num, num_version);
        nuevo->linea = crearLineaVacia();
        nuevo->sig = version;
        nuevo->hijo = NULL;
        version = nuevo;
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
    while (!esVaciaLinea(aux)){
        char* A = obtenerTextoLinea(aux, getNumeroLinea(aux));
        //std::cout << A << std::endl;
        printf("%s", A);
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

bool esVaciaVersion (Version version, char* numeroVersion){
    return version->linea == NULL;
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


/*
void crearVersion (Version &version, char *num_version){
    if (version == NULL) {
        Version nueva = new _rep_version();
        nueva->num = num_version;
        nueva->nivel = nivelVersion(nueva);
        nueva->linea = crearLineaVacia();
        nueva->sig = NULL;
        nueva->hijo = NULL;
        version = nueva;
    } else {
        crearVersion(version->sig, num_version);
    }  
}


//FUNCION AUXILIAR
int nivelVersion(Version version){
    int cont = 1;
    for (int i = 0; version->num[i] != '\0'; i++){
        if (version->num[i] == '.') cont++;       
    }
    return cont;
}
*/