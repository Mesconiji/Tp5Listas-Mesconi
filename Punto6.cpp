/*6.Haciendo uso de listas enérica ue realice:
a. Que la lista se cargue con números enteros y realice una función que busque
números primos dentro de la lista y los cuente. Muestre el resultado de la
cuenta.
b. Que la lista se cargue con caracteres y realice la cuenta de mayúsculas y
minúsculas dentro de la lista- Muestre los resultados por pantalla.
*/

#include <iostream>
#include <cctype> // Para isupper, islower
using namespace std;

// ==== TDA Nodo Genérico ====
template <class T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

// ==== TDA Lista Genérica ====
template <class T>
class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista() { cabeza = NULL; }

    void agregarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevo;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != NULL)
                temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    void mostrar() {
        Nodo<T>* temp = cabeza;
        while (temp != NULL) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL" << endl;
    }

    // === Parte A: contar primos (solo si T es int) ===
    int contarPrimos() {
        Nodo<T>* temp = cabeza;
        int contador = 0;

        while (temp != NULL) {
            if (esPrimo(temp->dato)) {
                contador++;
            }
            temp = temp->siguiente;
        }
        return contador;
    }

    // === Parte B: contar mayúsculas y minúsculas ===
    void contarMayusMinus(int &mayus, int &minus) {
        mayus = minus = 0;
        Nodo<T>* temp = cabeza;

        while (temp != NULL) {
            if (isupper(temp->dato))
                mayus++;
            else if (islower(temp->dato))
                minus++;
            temp = temp->siguiente;
        }
    }

private:
    bool esPrimo(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0)
                return false;
        return true;
    }
};

// ==== FUNCIÓN PRINCIPAL CON MENÚ ====
int main() {
    int opcion;

    do {
        cout << "\n===== MENÚ PRINCIPAL (Lista Genérica) =====\n";
        cout << "1. Cargar lista con enteros y contar primos\n";
        cout << "2. Cargar lista con caracteres y contar mayúsculas/minúsculas\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Lista<int> listaEnteros;
                int cantidad, valor;
                cout << "¿Cuántos enteros desea cargar? ";
                cin >> cantidad;
                for (int i = 0; i < cantidad; ++i) {
                    cout << "Valor " << i + 1 << ": ";
                    cin >> valor;
                    listaEnteros.agregarFinal(valor);
                }

                cout << "Lista cargada: ";
                listaEnteros.mostrar();

                int totalPrimos = listaEnteros.contarPrimos();
                cout << "Cantidad de números primos: " << totalPrimos << endl;
                break;
            }

            case 2: {
                Lista<char> listaCaracteres;
                int cantidad;
                char c;
                cout << "¿Cuántos caracteres desea cargar? ";
                cin >> cantidad;
                for (int i = 0; i < cantidad; ++i) {
                    cout << "Caracter " << i + 1 << ": ";
                    cin >> c;
                    listaCaracteres.agregarFinal(c);
                }

                cout << "Lista cargada: ";
                listaCaracteres.mostrar();

                int mayus = 0, minus = 0;
                listaCaracteres.contarMayusMinus(mayus, minus);
                cout << "Mayúsculas: " << mayus << ", Minúsculas: " << minus << endl;
                break;
            }

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    return 0;
}
// Fin del programa