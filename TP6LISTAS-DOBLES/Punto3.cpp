/*3. Utilice la definición de lista del punto anterior para implementar un
procedimiento/función que convierta un número en base decimal a base binaria.*/

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

void MostrarLista(tlista lista) {
    pnodo i = lista.inicio;
    while (i != NULL) {
        cout << i->dato;
        i = i->sig;
    }
    cout << endl;
}

// ✅ Conversión de decimal a binario usando lista doble
void DecimalABinario(int numero, tlista &lista) {
    if (numero == 0) {
        pnodo nuevo;
        CrearNodo(nuevo, 0);
        AgregarInicio(lista, nuevo);
        return;
    }

    while (numero > 0) {
        int resto = numero % 2;
        pnodo nuevo;
        CrearNodo(nuevo, resto);
        AgregarInicio(lista, nuevo); // se agrega al INICIO para conservar orden binario
        numero /= 2;
    }
}

// ========== MAIN DE PRUEBA ==========
int main() {
    int num;
    tlista binario;
    IniciarLista(binario);

    cout << "Ingrese un número decimal: ";
    cin >> num;

    DecimalABinario(num, binario);

    cout << "Representación binaria: ";
    MostrarLista(binario);

    return 0;
}
