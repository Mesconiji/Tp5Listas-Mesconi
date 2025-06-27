/*4. Utilizando listas simples implemente:

a. TDA Pila y sus operaciones fundamentales.
b. TDA Cola y sus operaciones fundamentales (incluya un contador de
elementos para la cola).
*/

#include <iostream>
using namespace std;

//
// ==== TDA PILA (LIFO) ====
//
typedef struct nodoPila *pnodoP;

struct nodoPila {
    int dato;
    pnodoP siguiente;
};

// Iniciar pila
void initStack(pnodoP &pila) {
    pila = NULL;
}

// Pila vacía
bool isEmptyStack(pnodoP pila) {
    return pila == NULL;
}

// Agregar (push)
void pushStack(pnodoP &pila, int valor) {
    pnodoP nuevo = new nodoPila;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = pila;
        pila = nuevo;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

// Extraer (pop)
int popStack(pnodoP &pila) {
    if (isEmptyStack(pila)) {
        cout << "Pila vacía" << endl;
        return -999;
    } else {
        pnodoP borrado = pila;
        int valor = borrado->dato;
        pila = pila->siguiente;
        delete borrado;
        return valor;
    }
}

// Consultar cima (top)
int topStack(pnodoP pila) {
    if (isEmptyStack(pila)) {
        cout << "Pila vacía" << endl;
        return -999;
    }
    return pila->dato;
}

//
// ==== TDA COLA (FIFO) ====
//
typedef struct nodoCola *pnodoC;

struct nodoCola {
    int dato;
    pnodoC siguiente;
};

struct Cola {
    pnodoC frente;
    pnodoC final;
    int cantidad;
};

// Iniciar cola
void initQueue(Cola &cola) {
    cola.frente = NULL;
    cola.final = NULL;
    cola.cantidad = 0;
}

// Cola vacía
bool isEmptyQueue(Cola cola) {
    return cola.frente == NULL;
}

// Agregar (enqueue)
void enqueue(Cola &cola, int valor) {
    pnodoC nuevo = new nodoCola;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if (isEmptyQueue(cola)) {
            cola.frente = nuevo;
        } else {
            cola.final->siguiente = nuevo;
        }

        cola.final = nuevo;
        cola.cantidad++;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
}

// Quitar (dequeue)
int dequeue(Cola &cola) {
    if (isEmptyQueue(cola)) {
        cout << "Cola vacía" << endl;
        return -999;
    } else {
        pnodoC borrado = cola.frente;
        int valor = borrado->dato;
        cola.frente = cola.frente->siguiente;

        if (cola.frente == NULL)
            cola.final = NULL;

        delete borrado;
        cola.cantidad--;
        return valor;
    }
}

// Consultar frente
int frontQueue(Cola cola) {
    if (isEmptyQueue(cola)) {
        cout << "Cola vacía" << endl;
        return -999;
    }
    return cola.frente->dato;
}

// Consultar final
int rearQueue(Cola cola) {
    if (isEmptyQueue(cola)) {
        cout << "Cola vacía" << endl;
        return -999;
    }
    return cola.final->dato;
}

// Cantidad actual
int sizeQueue(Cola cola) {
    return cola.cantidad;
}

//
// ==== MENÚ PRINCIPAL ====
//
void menuPila() {
    pnodoP pila;
    initStack(pila);
    int opcion, valor;

    do {
        cout << "\n--- TDA PILA ---\n";
        cout << "1. Push (Agregar)\n";
        cout << "2. Pop (Extraer)\n";
        cout << "3. Top (Consultar cima)\n";
        cout << "4. Volver al menú principal\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                pushStack(pila, valor);
                break;
            case 2:
                valor = popStack(pila);
                if (valor != -999)
                    cout << "Valor extraído: " << valor << endl;
                break;
            case 3:
                valor = topStack(pila);
                if (valor != -999)
                    cout << "Valor en la cima: " << valor << endl;
                break;
            case 4:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 4);
}

void menuCola() {
    Cola cola;
    initQueue(cola);
    int opcion, valor;

    do {
        cout << "\n--- TDA COLA ---\n";
        cout << "1. Enqueue (Agregar)\n";
        cout << "2. Dequeue (Quitar)\n";
        cout << "3. Consultar frente\n";
        cout << "4. Consultar final\n";
        cout << "5. Ver cantidad actual\n";
        cout << "6. Volver al menú principal\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                enqueue(cola, valor);
                break;
            case 2:
                valor = dequeue(cola);
                if (valor != -999)
                    cout << "Valor quitado: " << valor << endl;
                break;
            case 3:
                valor = frontQueue(cola);
                if (valor != -999)
                    cout << "Frente de la cola: " << valor << endl;
                break;
            case 4:
                valor = rearQueue(cola);
                if (valor != -999)
                    cout << "Final de la cola: " << valor << endl;
                break;
            case 5:
                cout << "Cantidad de elementos: " << sizeQueue(cola) << endl;
                break;
            case 6:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

int main() {
    int opcion;

    do {
        cout << "\n======= MENÚ PRINCIPAL =======\n";
        cout << "1. Usar TDA PILA\n";
        cout << "2. Usar TDA COLA\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuPila();
                break;
            case 2:
                menuCola();
                break;
            case 3:
                cout << "Gracias por usar el programa. ¡Hasta luego!\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 3);

    return 0;
}
// Fin del programa