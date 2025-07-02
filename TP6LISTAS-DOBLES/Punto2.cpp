/*2. Utilizando eI código de listas dobles con puntero inicio y fin- Complete las
operaciones Eliminarlnicio y EliminarFinaI.

https://virtual.unju.edu.ar/pluginfile.php/918501/mod_resource/content/1/tp7punto2.cpp
*/

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

void AgregarInicio(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    } else {
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
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

// ✅ Quitar nodo del inicio de la lista
void QuitarInicio(tlista &lista) {
    pnodo eliminado;

    if (lista.inicio == NULL) {
        cout << "Lista vacía." << endl;
        return;
    }

    eliminado = lista.inicio;

    if (lista.inicio == lista.fin) {
        // Solo un nodo
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        lista.inicio = lista.inicio->sig;
        lista.inicio->ant = NULL;
    }

    cout << "Nodo eliminado del inicio: " << eliminado->dato << endl;
    delete eliminado;
}

// ✅ Quitar nodo del final de la lista
void QuitarFinal(tlista &lista) {
    pnodo eliminado;

    if (lista.fin == NULL) {
        cout << "Lista vacía." << endl;
        return;
    }

    eliminado = lista.fin;

    if (lista.inicio == lista.fin) {
        // Solo un nodo
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        lista.fin = lista.fin->ant;
        lista.fin->sig = NULL;
    }

    cout << "Nodo eliminado del final: " << eliminado->dato << endl;
    delete eliminado;
}

// ✅ Mostrar lista desde inicio
void MostrarLista(tlista lista) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->sig;
    }
    cout << endl;
}

int main() {
    tlista miLista;
    IniciarLista(miLista);

    pnodo nuevo;

    CrearNodo(nuevo, 10);
    AgregarInicio(miLista, nuevo);

    CrearNodo(nuevo, 20);
    AgregarFinal(miLista, nuevo);

    CrearNodo(nuevo, 5);
    AgregarInicio(miLista, nuevo);

    cout << "Lista actual: ";
    MostrarLista(miLista);

    QuitarInicio(miLista);
    cout << "Después de quitar del inicio: ";
    MostrarLista(miLista);

    QuitarFinal(miLista);
    cout << "Después de quitar del final: ";
    MostrarLista(miLista);

    return 0;
}
