/*1. De acuerdo a la definición de TDA lista simple, implemente el TDA y sus
operaciones fundamentales considerando que la lista solo tiene un puntero con la
dirección del primer nodo de la lista (HEAD). Luego, implemente la operación
mínimo que permita extraer el menor valor almacenado en una lista desordenada*/

#include <iostream>
using namespace std;

// Definición del TDA Nodo
typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo siguiente;
};

// Iniciar lista
void iniciar_lista(pnodo &lista) {
    lista = NULL;
}

// Crear nodo
void crear_nodo(pnodo &nuevo) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        cout << "Ingrese valor: ";
        cin >> nuevo->dato;
        nuevo->siguiente = NULL;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

// Agregar al inicio
void agregar_inicio(pnodo &lista, pnodo nuevo) {
    nuevo->siguiente = lista;
    lista = nuevo;
}

// Mostrar lista
void mostrar(pnodo lista) {
    pnodo i;
    if (lista != NULL) {
        for (i = lista; i != NULL; i = i->siguiente) {
            cout << "Nodo: " << i->dato << endl;
        }
    } else {
        cout << "Lista vacía" << endl;
    }
}

// Obtener el menor valor de la lista
int minimo(pnodo lista) {
    if (lista == NULL) {
        cout << "Error: Lista vacía" << endl;
        return -1; // Indicador de error
    }

    int min = lista->dato;
    pnodo i = lista->siguiente;

    while (i != NULL) {
        if (i->dato < min) {
            min = i->dato;
        }
        i = i->siguiente;
    }

    return min;
}

// ---------------------------
// Programa principal de prueba
int main() {
    pnodo lista;
    iniciar_lista(lista);

    // Cargar lista
    char continuar = 's';
    while (continuar == 's') {
        pnodo nuevo;
        crear_nodo(nuevo);
        agregar_inicio(lista, nuevo);
        cout << "¿Desea agregar otro nodo? (s/n): ";
        cin >> continuar;
    }

    cout << "\nContenido de la lista:\n";
    mostrar(lista);

    int menor = minimo(lista);
    if (menor != -1)
        cout << "\nEl valor mínimo de la lista es: " << menor << endl;

    return 0;
}
// Fin del programa