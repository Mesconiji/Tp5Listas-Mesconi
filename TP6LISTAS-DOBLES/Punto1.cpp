/*1.De acuerdo a la definición del TDA Lista Doble, implemente el TDA y sus operaciones fundamentales, considerando:

a. TDA lista requiere de elementos, llamados nodos, que almacenen datos y que posean un indicador del próximo elemento de la lista.
b. Una operación de inicialización que permita crear (inicializar) una lista vacía.
c. Una operación que permita crear nodos.
d. Una operación de inserción que permita agregar un nuevo nodo al inicio de la lista.
e. Una operación de inserción que permita agregar un nuevo nodo al final de la lista.
f. Una operación de inserción que permita agregar, en orden, un nuevo nodo a la lista.
g. Una operación que extraiga un nodo del inicio de la lista.
h. Una operación que extraiga un nodo del final de la lista.
i. Una operación que extraiga un nodo específico (según un valor ingresado por el usuario) de la lista.
j. Una operación que permita buscar un nodo (valor) en la lista.
k. Una operación que permita mostrar el contenido de la lista*/

#include <iostream>
using namespace std;

// ========== TDA Nodo de Lista Doble ==========
typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo sig;
    pnodo ant;
};

// ========== Inicializar lista vacía ==========
void IniciarLista(pnodo &inicio) {
    inicio = NULL;
}

// ========== Crear nodo con un valor ==========
void CrearNodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}

// ========== Agregar al inicio ==========
void AgregarInicio(pnodo &inicio, pnodo nuevo) {
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        nuevo->sig = inicio;
        inicio->ant = nuevo;
        inicio = nuevo;
    }
}

// ========== Agregar al final ==========
void AgregarFinal(pnodo &inicio, pnodo nuevo) {
    pnodo i;
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        for (i = inicio; i->sig != NULL; i = i->sig);
        i->sig = nuevo;
        nuevo->ant = i;
    }
}

// ========== Agregar ordenado ==========
void AgregarOrden(pnodo &inicio, pnodo nuevo) {
    pnodo i;
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        if (nuevo->dato < inicio->dato) {
            nuevo->sig = inicio;
            inicio->ant = nuevo;
            inicio = nuevo;
        } else {
            for (i = inicio; i->sig != NULL && i->sig->dato < nuevo->dato; i = i->sig);
            if (i->sig != NULL) {
                nuevo->sig = i->sig;
                nuevo->ant = i;
                i->sig->ant = nuevo;
                i->sig = nuevo;
            } else {
                i->sig = nuevo;
                nuevo->ant = i;
            }
        }
    }
}

// ========== Quitar del inicio ==========
pnodo QuitarInicio(pnodo &inicio) {
    pnodo extraido;
    if (inicio == NULL) {
        extraido = NULL;
    } else {
        if (inicio->sig == NULL) {
            extraido = inicio;
            inicio = NULL;
        } else {
            extraido = inicio;
            inicio = inicio->sig;
            inicio->ant = NULL;
            extraido->sig = NULL;
        }
    }
    return extraido;
}

// ========== Quitar del final ==========
pnodo QuitarFinal(pnodo &inicio) {
    pnodo extraido, i;
    if (inicio == NULL) {
        extraido = NULL;
    } else {
        for (i = inicio; i->sig != NULL; i = i->sig);
        extraido = i;
        if (i->ant != NULL) {
            i->ant->sig = NULL;
            i->ant = NULL;
        } else {
            inicio = NULL;
        }
    }
    return extraido;
}

// ========== Quitar nodo por valor ==========
pnodo QuitarNodo(pnodo &inicio, int valor) {
    pnodo extraido = NULL, i;
    if (inicio == NULL) {
        return NULL;
    }

    if (inicio->dato == valor) {
        extraido = inicio;
        inicio = inicio->sig;
        if (inicio != NULL)
            inicio->ant = NULL;
        extraido->sig = NULL;
    } else {
        for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
        if (i != NULL) {
            extraido = i;
            if (i->ant != NULL)
                i->ant->sig = i->sig;
            if (i->sig != NULL)
                i->sig->ant = i->ant;
            extraido->sig = NULL;
            extraido->ant = NULL;
        }
    }
    return extraido;
}

// ========== Buscar nodo por valor ==========
bool BuscarNodo(pnodo inicio, int valor) {
    pnodo i;
    for (i = inicio; i != NULL; i = i->sig) {
        if (i->dato == valor)
            return true;
    }
    return false;
}

// ========== Mostrar lista ==========
void MostrarLista(pnodo inicio) {
    pnodo i;
    if (inicio != NULL) {
        for (i = inicio; i != NULL; i = i->sig) {
            cout << i->dato << " ";
        }
        cout << endl;
    } else {
        cout << "Lista vacía." << endl;
    }
}

// ========== MAIN DE PRUEBA ==========
int main() {
    pnodo lista;
    IniciarLista(lista);

    pnodo nuevo;

    CrearNodo(nuevo, 5);
    AgregarInicio(lista, nuevo);

    CrearNodo(nuevo, 10);
    AgregarFinal(lista, nuevo);

    CrearNodo(nuevo, 7);
    AgregarOrden(lista, nuevo);

    cout << "Lista después de insertar 5, 10, 7: ";
    MostrarLista(lista);

    pnodo quitado = QuitarInicio(lista);
    delete quitado;
    cout << "Luego de quitar el primero: ";
    MostrarLista(lista);

    quitado = QuitarFinal(lista);
    delete quitado;
    cout << "Luego de quitar el último: ";
    MostrarLista(lista);

    CrearNodo(nuevo, 3);
    AgregarInicio(lista, nuevo);

    CrearNodo(nuevo, 9);
    AgregarFinal(lista, nuevo);

    cout << "Lista actual: ";
    MostrarLista(lista);

    bool encontrado = BuscarNodo(lista, 7);
    cout << "¿Está el 7 en la lista?: " << (encontrado ? "Sí" : "No") << endl;

    quitado = QuitarNodo(lista, 7);
    if (quitado != NULL) {
        delete quitado;
        cout << "Luego de quitar el 7: ";
        MostrarLista(lista);
    }

    return 0;
}
