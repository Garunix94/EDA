/* 5512649 */ 

#include <time.h>
#include "../include/archivo.h"
#include "../include/version.h"


struct _rep_archivo {
    char * nombreArchivo;
    Version version;
};



//***********************  CONSTRUCTORAS ***************** */

Archivo crearArchivoVacio(char *nomArchivo){
    Archivo nuevo =new _rep_archivo();
    nuevo->nombreArchivo = nomArchivo;
    nuevo->version = NULL;
    return nuevo;
}

//Pre-Cond: No existe otra version en la estructura con nombre "nombreVersion"
//Pos-Cond: Crea una nueva version de 
void crearVersionArchivo (Archivo &archivo, char *numVersion){
    crearVersion(archivo->version, numVersion);
}

//Pre-Cond: No existe otra version en la estructura con nombre "nombreVersion"
//Pos-Cond: Crea una nueva version de
void versionIndependienteArchivo(Archivo &archivo, char *numVersion);

//************************ SELECTORAS ********************* */

//Pre-Cond: la version num_version existe en version
//Pos-Cond: Retorna un puntero a la version de nombre "num_version"
void mostrarVersionesArchivo(Archivo archivo);

//Pre-cond: La version "version" tiene por lo menos "num_fila" de Filas
//Pos-Cond: Agrega el string texto como la fila num_fila de la Version "version"
//          Las filas debajo de num_filas se renumeran como num_fila=num_fila+1
void insertarLineaVersionDeArchivo (Archivo &archivo, char* numeroVersion, char *textoFila,unsigned int numFila);

//Pre-Cond: la Fila "num_fila" existe en la version "version"
//Pos-Cond: se elimina la Fila de la posicion "num_fila"
//          el resto de las Filas debajo se renumeran como num_fila=num_fila-1
void borrarLineaVersionArchivo (Archivo &archivo, char* numeroVersion, unsigned int numFila);

//Pre-Cond: la version nombre_version existe en Version
//Pos-Cond: Imprime la Version "nombre_version"
void imprimirVersionArchivo (Archivo version, char* numeroVersion);

//Pre-Cond: Tiene version padre.
//Pos-Cond: Imprime los cambios realizados en la version numeroVersion con respecto al padre.
void mostrarCambiosArchivo (Archivo archivo, char* numeroVersion);

//********************* PREDICADOS ************************* */



//Retorna true si la Version "numeroVersion" existe en "version"
bool igualesVersionesArchivo (Archivo version, char* numeroVersion1, char* numeroVersion2);


//****************  DESTRUCTORAS ***********************

void borrarArchivoCompleto(Archivo &archivo){
    delete archivo;
    archivo = NULL;
}

//Pre-Cond: la version "numeroVersion" existe en version
//Pos-Cond: elimina toda la mermoria reservada por "numeroVersion"
//          y sus sub-versiones del Archivo "archivo"
void borrarVersionDeArchivo (Archivo &archivo, char* numeroVersion);