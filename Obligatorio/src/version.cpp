/* 5512649 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/version.h"
#include <time.h>
#include <string.h>


struct _rep_version {
    char * numero;
    _rep_version * sig;
    _rep_version * hijo;
};

//***********************  CONSTRUCTORAS ***************** */

//Pos-Cond: Retorna una version vacia
Version crearVersionVacia(){
    return NULL;
}

//Pre-Cond: No existe otra version en la estructura con nombre "nombreVersion"
//Pos-Cond: Crea una nueva version de 
void crearVersion (Version &version, char *num_version){
    if (version == NULL) {
        Version nueva = crearVersionVacia();
        nueva->numeroVersion = num_version;
        version = nueva;
    }else if( strcmp(version->numeroVersion, num_version) < 0 ) {
        crearVersion(version->hijo, num_version);
    }else{
        crearVersion(version->sig, num_version);
    }
}


//************************ SELECTORAS ********************* */

//Pre-Cond: la version numVersion existe en version
//Pos-Cond: Retorna un puntero a la version de nombre "numVersion"
Version obtenerVersion(Version &version, char *numVersion);

//Pre-cond: La version "version" tiene por lo menos "numLinea" de Lineas
//Pos-Cond: Agrega el string texto como la fila num_fila de la Version "version"
//          Las filas debajo de num_filas se renumeran como numLinea=numLinea+1
void agregarFilaVersion (Version &version, char* numeroVersion, char *textoFila,unsigned int numLinea);



//Pre-Cond: existeVersion(version, numeroVersion) retorna true.
//Pos-Cond: Imprime la Version "nombreVersion"
void imprimirVersion(Version version, char* numeroVersion);

//********************* PREDICADOS ************************* */

//Retorna true si la Version "version" no tiene texto
bool esVaciaVersion (Version version, char* numeroVersion);

//Retorna true si la Version "numeroVersion" existe en "version"
bool existeVersion (Version version, char* numeroVersion);

//****************  DESTRUCTORAS ***********************

//Pre-Cond: la Linea "numLinea" existe en la version "version"
//Pos-Cond: se elimina la Linea de la posicion "numLinea"
//          el resto de las Lineas debajo se renumeran como numLinea=numLinea-1
void eliminarLineaVersion (Version &version, char* numeroVersion, unsigned int numLinea);

//Pre-Cond: la version "numeroVersion" existe en version
//Pos-Cond: elimina toda la mermoria reservada por "numeroVersion"
//          y sus sub-versiones.
void destruirVersion (Version &version, char* numeroVersion);


//Pre-Cond: La version que se le pasa no es vacia
//Pos-Cond: devuelve un intero con el nivel de version
int nivelVersion(Version version){
    int cont = 1;
    for (int i = 0; version->numero[i] != '\0'; i++)
    {
        /* code */
    }
    
}
