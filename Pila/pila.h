#ifndef _PILA_H
#define _PILA_H

typedef struct _pila * Pila;

// CONSTRUCTORAS
void crearPila(int cota, Pila &p);
/* Devuelve en p la pila vacía, que podrá contener hasta cota elementos. 
   Nota: crearPila podría ser una función que retorne la Pila creada. */

void apilar(int i, Pila &p);
/* Si !esLlenaPila(p) inserta i en la cima de p, en otro caso no hace nada. */

// SELECTORAS
int cima(Pila p);
/* Devuelve la cima de p.
   Precondición: !esVaciaPila(p). */

void desapilar(Pila &p);
/* Remueve la cima de p.
   Precondición: !esVaciaPila(p). */

// PREDICADOS
bool esVaciaPila(Pila p);
/* Devuelve 'true' si p es vacía, 'false' en otro caso. */

bool esLlenaPila(Pila p);
/* Devuelve 'true' si p tiene cota elementos (la cota es el valor pasado en 
   crearPila), 'false' en otro caso. */

// DESTRUCTORA
void destruirPila(Pila &p);
/* Libera toda la memoria ocupada por p. */

#endif /* _PILA_H */
