#include <iostream>
#define INT_MIN -100
using namespace std;


struct _rep_lista{
    int num;
    _rep_lista* sig;
};
typedef _rep_lista*Lista;

void mostrarLista(Lista lista);
Lista cargarListaDesdeArreglo(int arreglo[], int tamaño);
int mayorLista(Lista lista);






int main(){
    int numeros[] = {2, 7, 1, 9, 23, 8, -1, 89, 34, 0, 12};
    Lista lista = cargarListaDesdeArreglo(numeros, 11);
    mostrarLista(lista);

    int mayor = mayorLista(lista);
    cout << "\n" << mayor << endl;
}






//Mi funcion recursiva creada por mi jajajaja
int mayorLista(Lista lista){
    if (lista == NULL)
        return INT_MIN;
    else if (lista->num > mayorLista(lista->sig))
        return lista->num;
    else
        return mayorLista(lista->sig);
}


// Función para cargar un arreglo de enteros en una lista
Lista cargarListaDesdeArreglo(int arreglo[], int tamaño) {
    Lista lista = NULL;
    Lista ultimo = NULL;
    
    for(int i = 0; i < tamaño; i++) {
        // Crear nuevo nodo
        Lista nuevoNodo = new _rep_lista;
        nuevoNodo->num = arreglo[i];
        nuevoNodo->sig = NULL;
        
        // Insertar al final de la lista
        if (lista == NULL) {
            // Lista vacía - primer elemento
            lista = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            // Insertar al final
            ultimo->sig = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }
    
    return lista;
}

// Función para mostrar una lista
void mostrarLista(Lista lista) {
    cout << "Lista: ";
    Lista actual = lista;
    while (actual != NULL) {
        cout << actual->num;
        if (actual->sig != NULL) {
            cout << " -> ";
        }
        actual = actual->sig;
    }
    cout << endl;
}