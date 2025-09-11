/* 5512649 */ 

#include <time.h>
#include <iostream>
#include "../include/archivo.h"
#include "../include/version.h"


struct _rep_archivo {
    char * nombreArchivo;
    Version version;
};


Archivo crearArchivoVacio(char *nomArchivo){
    Archivo nuevo = new _rep_archivo();
    nuevo->nombreArchivo = nomArchivo;
    nuevo->version = crearVersionVacia();
    return nuevo;
}

void crearVersionArchivo (Archivo &archivo, char *numVersion){
    crearVersion(archivo->version, numVersion);
}

//NO ENTIENDO DIFERENECIA CON FUNCION ANTERIOR
void versionIndependienteArchivo(Archivo &archivo, char *numVersion);

//PARECE QUE FALTA UNA FUNCION EN VERSION
void mostrarVersionesArchivo(Archivo archivo){
    std::cout << "Nada de nada" << std::endl;
}

void insertarLineaVersionDeArchivo (Archivo &archivo, char* numeroVersion, char *textoFila,unsigned int numFila){
    agregarFilaVersion(archivo->version, numeroVersion, textoFila, numFila);
}

void borrarLineaVersionArchivo (Archivo &archivo, char* numeroVersion, unsigned int numFila){
    eliminarLineaVersion(archivo->version, numeroVersion, numFila);
}

void imprimirVersionArchivo (Archivo archivo, char* numeroVersion){
    imprimirVersion(archivo->version, numeroVersion);
}

//IMPLEMENTAR EN EL SEGUNDO OBLIGATORIO
void mostrarCambiosArchivo (Archivo archivo, char* numeroVersion);

void mostrarTextoArchivoVersion (Archivo archivo, char* numeroVersion){
    imprimirVersion(archivo->version, numeroVersion);
}

//FALTA IMPLEMENTAR OJOOOO
bool igualesVersionesArchivo (Archivo archivo, char* numeroVersion1, char* numeroVersion2);

bool existeVersionEnArchivo(Archivo archivo, char* numeroVersion){
    return existeVersion(archivo->version, numeroVersion);
}

void borrarArchivoCompleto(Archivo &archivo){
    destruirTodasLasVersiones(archivo->version);
    delete archivo;
    archivo = NULL;
}

void borrarVersionDeArchivo (Archivo &archivo, char* numeroVersion){
    destruirVersion(archivo->version, numeroVersion);
}