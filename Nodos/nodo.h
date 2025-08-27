#ifndef NODO_H
#define NODO_H

typedef struct _nodo * Lista;

/***************** CONSTRUCTORA  *********************/

Lista crearLista();


/*****************  SELECTORAS  *********************/

//Pre-condicion: Lista no vacia
//Post-condicion: Retorna el primer elemento de la lista eliminandolo
int primerElementoLista(Lista &l);


//Pre-condicion: No tiene
//Post-condicion: Inserta el eemento 'elem' en el final de l
void insertarElementoLista(Lista &l, int elem);


/*****************  PREDICADOS  *********************/

bool esVacia(Lista l);


/*****************  DESTRUCTORA  ********************/

//Pre-condicion: Lista no vacia
//Post-condicion: No tiene
void destruirLista(Lista &l);


#endif