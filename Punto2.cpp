/*2.
Implemente una lista con puntero al inicio y al final además de un contador que
registre la cantidad de elementos actuales que hay en la lista_ Realice las
modificaciones necesarias a los métodos agregar y eliminar para que actualice el
contador, además de agregar una función que retorne la cantidad de elementos
actuales de la lista.*/

#include <iostream>
using namespace std;

// TDA Nodo
typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo siguiente;
};

// TDA Lista con punteros al inicio, final y contador
typedef struct {
    pnodo inicio;
    pnodo final;
    int cantidad;
} tlista;

// Inicializar la lista
void iniciar_lista(tlista &lista) {
    lista.inicio = NULL;
    lista.final = NULL;
    lista.cantidad = 0;
}

// Crear un nuevo nodo
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

// Agregar al final de la lista
void agregar_final(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.cantidad++; // Aumentar el contador
}

// Eliminar al final de la lista
pnodo eliminar_final(tlista &lista) {
    pnodo borrado, i;

    if (lista.inicio == NULL) {
        borrado = NULL;
    } else if (lista.inicio == lista.final) {
        borrado = lista.inicio;
        lista.inicio = NULL;
        lista.final = NULL;
    } else {
        for (i = lista.inicio; (i->siguiente)->siguiente != NULL; i = i->siguiente);
        borrado = lista.final;
        lista.final = i;
        lista.final->siguiente = NULL;
    }

    if (borrado != NULL)
        lista.cantidad--; // Disminuir el contador

    return borrado;
}

// Mostrar lista
void mostrar(tlista lista) {
    pnodo i = lista.inicio;
    if (i != NULL) {
        while (i != NULL) {
            cout << "Nodo: " << i->dato << endl;
            i = i->siguiente;
        }
    } else {
        cout << "Lista vacía" << endl;
    }
}

// Obtener cantidad de elementos
int contar_elementos(tlista lista) {
    return lista.cantidad;
}

// ----------------------
// Programa principal de prueba
int main() {
    tlista miLista;
    iniciar_lista(miLista);

    char continuar = 's';
    while (continuar == 's') {
        pnodo nuevo;
        crear_nodo(nuevo);
        agregar_final(miLista, nuevo);
        cout << "¿Desea agregar otro nodo? (s/n): ";
        cin >> continuar;
    }

    cout << "\nContenido de la lista:\n";
    mostrar(miLista);

    cout << "\nCantidad de elementos actuales: " << contar_elementos(miLista) << endl;

    cout << "\nEliminando último nodo..." << endl;
    pnodo eliminado = eliminar_final(miLista);
    if (eliminado != NULL)
        cout << "Nodo eliminado: " << eliminado->dato << endl;

    cout << "\nLista actualizada:\n";
    mostrar(miLista);
    cout << "Cantidad de elementos actuales: " << contar_elementos(miLista) << endl;

    return 0;
}
