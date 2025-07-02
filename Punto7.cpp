/*
--------------------------------------------------------
EJERCICIO 7 – ANÁLISIS DE FUNCIONES CON LISTAS SIMPLES
--------------------------------------------------------

Dada la lista:
    6 → 4 → 9 → 5 → 8 → NULL

Analizamos las siguientes funciones y su propósito:

--------------------------------------------------------
1. void enigma(Nodo* nodo)
--------------------------------------------------------
Función recursiva que:
- Llega hasta el último nodo de la lista.
- Imprime los valores de los nodos en el retorno de la recursión.

Comportamiento:
- Si el nodo actual no es el último:
    Llama recursivamente a enigma con el siguiente nodo.
    Luego imprime el dato actual.

Orden de ejecución con la lista:
    6 → 4 → 9 → 5 → 8

    Llamadas anidadas: enigma(6) → enigma(4) → enigma(9) → enigma(5) → enigma(8)
    Salida por pantalla:
        8
        5
        9
        4
        6

Propósito:
>> Imprimir la lista en orden inverso (desde el final al principio).

--------------------------------------------------------
2. int misterio(Nodo* nodo)
--------------------------------------------------------
Función recursiva que:
- Llega hasta el final de la lista.
- Suma 1 por cada nodo que encuentra.

Comportamiento:
- Si el nodo es nulo: retorna 0.
- Si no: retorna 1 + resultado del llamado a misterio con el siguiente nodo.

Con la lista de 5 elementos:
    misterio(6) → misterio(4) → misterio(9) → misterio(5) → misterio(8) → nullptr
    Retorno: 0 + 1 + 1 + 1 + 1 + 1 = 5

Propósito:
>> Contar la cantidad de nodos en la lista.

Resultado esperado:
    Retorna 5.

--------------------------------------------------------
3. Nodo* desconocido(Nodo* nodo)
--------------------------------------------------------
Función recursiva que:
- Busca el último nodo de la lista.

Comportamiento:
- Si el nodo es NULL o su siguiente es NULL → es el último nodo → retorna el nodo.
- Si no → llama recursivamente con el siguiente nodo.

Con la lista:
    desconocido(6) → desconocido(4) → desconocido(9) → desconocido(5) → desconocido(8)

Resultado:
    Retorna puntero al nodo que contiene el valor 8.

Propósito:
>> Obtener el último nodo de la lista (nodo final).

--------------------------------------------------------
RESUMEN FINAL:
--------------------------------------------------------
Función        | Propósito                                   | Resultado con la lista (6 4 9 5 8)
---------------|---------------------------------------------|-----------------------------------
enigma         | Imprimir en orden inverso                   | 8 5 9 4 6
misterio       | Contar la cantidad de nodos                 | 5
desconocido    | Obtener el nodo final                       | Nodo con dato 8

*/
