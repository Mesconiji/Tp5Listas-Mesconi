/*4. Implementar una función/procedimiento que permita recorrer la lista y mostrar el
valor mayor y el menor almacenado.*/

#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista {
    pnodo inicio;
    pnodo fin;
};

void IniciarLista(tlista &lista) {
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    } else {
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void MostrarLista(tlista lista) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->sig;
    }
    cout << endl;
}

//  Punto 4: Mostrar el valor mayor y menor de la lista
void MostrarMayorYMenor(tlista lista) {
    if (lista.inicio == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int mayor = lista.inicio->dato;
    int menor = lista.inicio->dato;
    pnodo i = lista.inicio->sig;

    while (i != NULL) {
        if (i->dato > mayor)
            mayor = i->dato;
        if (i->dato < menor)
            menor = i->dato;
        i = i->sig;
    }

    cout << "Mayor valor: " << mayor << endl;
    cout << "Menor valor: " << menor << endl;
}

// ========== MAIN DE PRUEBA ==========
int main() {
    tlista miLista;
    IniciarLista(miLista);

    pnodo nuevo;

    CrearNodo(nuevo, 42);
    AgregarFinal(miLista, nuevo);

    CrearNodo(nuevo, 17);
    AgregarFinal(miLista, nuevo);

    CrearNodo(nuevo, 98);
    AgregarFinal(miLista, nuevo);

    CrearNodo(nuevo, 31);
    AgregarFinal(miLista, nuevo);

    cout << "Lista: ";
    MostrarLista(miLista);

    MostrarMayorYMenor(miLista);

    return 0;
}
