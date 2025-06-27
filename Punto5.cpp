/*5. Dada una colección de valores enteros, se pretende ordenar dicha colección
aplicando el algoritmo de ordenación por selección_ En virtud de ello, se solicita.

a. Implemente mediante listas simplemente enlazadas la colección de valores
enteros.
b. Desarrolle los procedimientos/funciones necesarios para implementar eI
algoritmo de ordenación por selección para la estructura definida.
c. Implemente dos método que permitan combinar dos listas, donde, eI
resultado final es una lista única con los elementos de ambas listas.
Considerando que:
    1-Para el primer método no importa el orden de los elementos de la
    lista.
    2-Para eI segundo método si importa el orden de los elementos de la
    lista.
*/

#include <iostream>
using namespace std;

// ==== TDA Nodo para lista simplemente enlazada ====
typedef struct nodo *pnodo;

struct nodo {
    int dato;
    pnodo siguiente;
};

// ==== FUNCIONES BÁSICAS DE LISTA ====
void agregarFinal(pnodo &lista, int valor) {
    pnodo nuevo = new nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        pnodo temp = lista;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void mostrarLista(pnodo lista) {
    while (lista != NULL) {
        cout << lista->dato << " -> ";
        lista = lista->siguiente;
    }
    cout << "NULL" << endl;
}

// ==== ORDENAMIENTO POR SELECCIÓN ====
void ordenarSeleccion(pnodo lista) {
    pnodo i, j, min;

    for (i = lista; i != NULL && i->siguiente != NULL; i = i->siguiente) {
        min = i;
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->dato < min->dato) {
                min = j;
            }
        }
        if (min != i) {
            int aux = i->dato;
            i->dato = min->dato;
            min->dato = aux;
        }
    }
}

// ==== COMBINACIÓN DE LISTAS ====

// Combinar sin importar orden
void combinarSinOrden(pnodo &lista1, pnodo lista2) {
    if (lista1 == NULL) {
        lista1 = lista2;
        return;
    }

    pnodo actual = lista1;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = lista2;
}

// Combinar con orden (listas ya ordenadas)
pnodo combinarConOrden(pnodo lista1, pnodo lista2) {
    pnodo resultado = NULL, ultimo = NULL;

    while (lista1 != NULL && lista2 != NULL) {
        pnodo nuevo = new nodo;
        if (lista1->dato <= lista2->dato) {
            nuevo->dato = lista1->dato;
            lista1 = lista1->siguiente;
        } else {
            nuevo->dato = lista2->dato;
            lista2 = lista2->siguiente;
        }
        nuevo->siguiente = NULL;

        if (resultado == NULL) {
            resultado = nuevo;
        } else {
            ultimo->siguiente = nuevo;
        }
        ultimo = nuevo;
    }

    // Agregar lo que queda de la lista más larga
    pnodo restante = (lista1 != NULL) ? lista1 : lista2;
    while (restante != NULL) {
        pnodo nuevo = new nodo;
        nuevo->dato = restante->dato;
        nuevo->siguiente = NULL;

        if (resultado == NULL) {
            resultado = nuevo;
        } else {
            ultimo->siguiente = nuevo;
        }
        ultimo = nuevo;
        restante = restante->siguiente;
    }

    return resultado;
}

// ==== MENÚ INTERACTIVO ====
void menu() {
    pnodo lista1 = NULL, lista2 = NULL, listaCombinada = NULL;
    int opcion, valor, n;

    do {
        cout << "\n========= MENÚ PRINCIPAL =========\n";
        cout << "1. Agregar valor a Lista 1\n";
        cout << "2. Agregar valor a Lista 2\n";
        cout << "3. Mostrar listas\n";
        cout << "4. Ordenar Lista 1 por selección\n";
        cout << "5. Ordenar Lista 2 por selección\n";
        cout << "6. Combinar listas SIN importar orden\n";
        cout << "7. Combinar listas CON orden\n";
        cout << "8. Mostrar lista combinada\n";
        cout << "9. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese cantidad de elementos a agregar en Lista 1: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Valor " << (i + 1) << ": ";
                    cin >> valor;
                    agregarFinal(lista1, valor);
                }
                break;
            case 2:
                cout << "Ingrese cantidad de elementos a agregar en Lista 2: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Valor " << (i + 1) << ": ";
                    cin >> valor;
                    agregarFinal(lista2, valor);
                }
                break;
            case 3:
                cout << "Lista 1: ";
                mostrarLista(lista1);
                cout << "Lista 2: ";
                mostrarLista(lista2);
                break;
            case 4:
                ordenarSeleccion(lista1);
                cout << "Lista 1 ordenada." << endl;
                break;
            case 5:
                ordenarSeleccion(lista2);
                cout << "Lista 2 ordenada." << endl;
                break;
            case 6:
                combinarSinOrden(lista1, lista2);
                cout << "Listas combinadas SIN ordenar (resultado en Lista 1)." << endl;
                break;
            case 7:
                listaCombinada = combinarConOrden(lista1, lista2);
                cout << "Listas combinadas CON orden (resultado en nueva lista)." << endl;
                break;
            case 8:
                cout << "Lista combinada: ";
                mostrarLista(listaCombinada);
                break;
            case 9:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 9);
}

// ==== FUNCIÓN PRINCIPAL ====
int main() {
    menu();
    return 0;
}
