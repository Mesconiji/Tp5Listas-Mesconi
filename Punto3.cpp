/*3. Utilizando la implementación de lista del punto 2. Realice las siguientes funciones

a-Función buscar_indice que busque un valor dentro de la lista y retorne un
índice numérico (int) correspondiente a su posición lógica dentro de la lista, si
el valor no se encuentra retorna -1.

b-Función buscar_por_indice que busque un valor dentro de la lista según su
posición lógica, y si existe retorne un puntero con la dirección del elemento
buscado, caso contrario la función debe devolver NULL.
*/

#include <iostream>
using namespace std;

// TDA Nodo
typedef struct tnodo *pnodo;

typedef struct tnodo {
    int dato;
    pnodo siguiente;
};

// TDA Lista
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

// Agregar nodo al final
void agregar_final(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.cantidad++;
}

// Eliminar el último nodo
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
        lista.cantidad--;
    return borrado;
}

// Mostrar la lista
void mostrar(tlista lista) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        cout << "Nodo: " << i->dato << endl;
        i = i->siguiente;
    }
}

// Devolver cantidad de elementos
int contar_elementos(tlista lista) {
    return lista.cantidad;
}

// === A: buscar_indice(valor)
int buscar_indice(tlista lista, int valor) {
    pnodo i = lista.inicio;
    int indice = 0;
    while (i != NULL) {
        if (i->dato == valor) {
            return indice;
        }
        i = i->siguiente;
        indice++;
    }
    return -1; // No encontrado
}

// === B: buscar_por_indice(indice)
pnodo buscar_por_indice(tlista lista, int indice) {
    if (indice < 0 || indice >= lista.cantidad) {
        return NULL; // Índice fuera de rango
    }

    pnodo i = lista.inicio;
    int pos = 0;
    while (i != NULL && pos < indice) {
        i = i->siguiente;
        pos++;
    }
    return i; // Puede ser NULL si algo falla
}

// ------------------
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

    cout << "\nCantidad de elementos: " << contar_elementos(miLista) << endl;

    // Prueba buscar_indice
    int valor_buscar;
    cout << "\nIngrese valor a buscar (buscar_indice): ";
    cin >> valor_buscar;
    int pos = buscar_indice(miLista, valor_buscar);
    if (pos != -1)
        cout << "Valor encontrado en la posición: " << pos << endl;
    else
        cout << "Valor no encontrado." << endl;

    // Prueba buscar_por_indice
    int indice;
    cout << "\nIngrese índice a buscar (buscar_por_indice): ";
    cin >> indice;
    pnodo encontrado = buscar_por_indice(miLista, indice);
    if (encontrado != NULL)
        cout << "Nodo en índice " << indice << ": " << encontrado->dato << endl;
    else
        cout << "Índice inválido o fuera de rango." << endl;

    return 0;
}
