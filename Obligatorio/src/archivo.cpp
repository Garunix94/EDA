/* 5512649 */ 

#include <time.h>
#include <string.h>
#include <stdio.h>
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

int nivelVersion(char* version) {
    int nivel = 1; // empezamos en 1
    for (int i = 0; version[i] != '\0'; i++) {
        if (version[i] == '.') {
            nivel++;
        }
    }
    return nivel;
}

void pasarCharNumero(char* version, int numeros[4]) {
    int pos = 0;
    for (int i = 0; version[i] != '\0' && pos < 4; i++) {
        if (version[i] >= '0' && version[i] <= '9') {
            numeros[pos] = version[i] - '0';
            pos++;
        }
    }
    // completar con 0 si quedaron posiciones vacías o ver si mejor con \0
    for (; pos < 4; pos++)numeros[pos] = 0;
}



void crearVersionArchivo (Archivo &archivo, char * numVersion){
    int nivel = nivelVersion(numVersion);
    int num[4];
    pasarCharNumero(numVersion, num);
    crearVersion(archivo->version, num, nivel);
}



//NO ENTIENDO DIFERENECIA CON FUNCION ANTERIOR
void versionIndependienteArchivo(Archivo &archivo, char *numVersion);

char* obtenerNombreArchivo(Archivo archivo){
    char* A = new char[20];
    strcpy(A,archivo->nombreArchivo);
    return A;
}


void mostrarVersionesArchivo(Archivo archivo){
    printf("%s\n\n", archivo->nombreArchivo);
    if (!existeArbol(archivo->version)){
        printf("No hay versiones creadas\n");
    } else {
        imprimirNumeroVersiones(archivo->version);   
    }
}

void insertarLineaVersionDeArchivo (Archivo &archivo, int * numeroVersion, char *textoFila, unsigned int numFila){
    agregarFilaVersion(archivo->version, numeroVersion, textoFila, numFila);
}

void imprimirVersionArchivo (Archivo archivo, int * numeroVersion){
    printf("%s\n\n", archivo->nombreArchivo);
    imprimirVersion(archivo->version, numeroVersion);
}





//IMPLEMENTAR EN EL SEGUNDO OBLIGATORIO
void mostrarCambiosArchivo (Archivo archivo, char* numeroVersion);




void mostrarTextoArchivoVersion (Archivo archivo, int * numeroVersion){
    printf("%s - %d.%d.%d", archivo->nombreArchivo, numeroVersion[1], numeroVersion[2], numeroVersion[3]);
    imprimirVersion(archivo->version, numeroVersion);
}



unsigned int numeroUltimaVersionArchivo (Archivo archivo){
    Version aux = archivo->version;
    unsigned int num = 0;
    while (aux != NULL && existeArbol(aux)){
        aux = hijoVersion(aux);
        num++;
    }
    return num;
}





unsigned int numeroUltimaLinea (Archivo archivo, int * nombreVersion){
    Version aux = obtenerVersion(archivo->version, nombreVersion);
    return numeroUltimaLineaVersion(aux);
}




//FALTA IMPLEMENTAR
bool igualesVersionesArchivo (Archivo archivo, char* numeroVersion1, char* numeroVersion2);

bool existeVersionEnArchivo(Archivo archivo, int * numeroVersion){
    return existeVersion(archivo->version, numeroVersion);
}

void borrarArchivoCompleto(Archivo &archivo){
    destruirTodasLasVersiones(archivo->version);
    delete archivo;
    archivo = NULL;
}

void borrarVersionDeArchivo (Archivo &archivo, int * numeroVersion){
    destruirVersion(archivo->version, numeroVersion);
}

void borrarLineaVersionArchivo (Archivo &archivo, int * numeroVersion, unsigned int numFila){
    eliminarLineaVersion(archivo->version, numeroVersion, numFila);
}








