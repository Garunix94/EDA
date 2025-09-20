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

void crearVersionArchivo (Archivo &archivo, char *numVersion){
    crearVersion(archivo->version, numVersion);
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
    if (archivo->version == NULL){
        printf("No hay versiones creadas\n");
    } else {
        Version aux = archivo->version;
        while (aux != NULL){
            char* A = nombreVersion(aux);
            for (int i = 0; A[i] != '\0'; i++){
                if (A[i] == '.'){
                    printf("    ");
                }
            }    
            printf("%s\n", nombreVersion(aux));
            aux = siguienteVersion(aux);
        }
    }
}

void insertarLineaVersionDeArchivo (Archivo &archivo, char* numeroVersion, char *textoFila,unsigned int numFila){
    agregarFilaVersion(archivo->version, numeroVersion, textoFila, numFila);
}

void imprimirVersionArchivo (Archivo archivo, char* numeroVersion){
    printf("%s\n\n", archivo->nombreArchivo);
    imprimirVersion(archivo->version, numeroVersion);
}




//IMPLEMENTAR EN EL SEGUNDO OBLIGATORIO
void mostrarCambiosArchivo (Archivo archivo, char* numeroVersion);

void mostrarTextoArchivoVersion (Archivo archivo, char* numeroVersion){
    Version num = obtenerVersion(archivo->version, numeroVersion);
    printf("%s - %s\n\n", archivo->nombreArchivo, nombreVersion(num));
    imprimirVersion(archivo->version, numeroVersion);
}

unsigned int numeroUltimaVersionArchivo (Archivo archivo){
    if (esVaciaVersion(archivo->version)){
        return 0;
    }else{
        return 1 + numeroUltimaVersion(archivo->version);
    }
    
}

unsigned int numeroUltimaLinea (Archivo archivo, char* nombreVersion){
    Version aux = obtenerVersion(archivo->version, nombreVersion);
    return numeroUltimaLineaVersion(aux);
}




//FALTA IMPLEMENTAR
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

void borrarLineaVersionArchivo (Archivo &archivo, char* numeroVersion, unsigned int numFila){
    eliminarLineaVersion(archivo->version, numeroVersion, numFila);
}


