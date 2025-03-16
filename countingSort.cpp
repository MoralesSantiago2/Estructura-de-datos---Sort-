#include "countingSort.h"
#include "funcionesGlobales.h"

#include <iostream>
using namespace std;

// Función que implementa el algoritmo Counting Sort
void countSort(int array[], int size) {
    int output[size];  // Array donde se almacenará el resultado ordenado
    int max = array[0]; // Variable para almacenar el valor máximo del array

    // Encontrar el valor máximo en el array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Crear el array de conteo con tamaño igual al valor máximo + 1
    int count[max + 1] = {0};  // Inicializado con ceros

    // Contar la frecuencia de cada elemento en el array original
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Convertir el array de conteo en acumulativo
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Construir el array ordenado colocando los elementos en la posición correcta
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--; // Reducir el contador
    }

    // Copiar el array ordenado al array original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}


int callCounting() {
    int n;

    // Pedir al usuario el tamaño del array
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int array[n];  // Declarar el array con el tamaño dado por el usuario

    // Leer los elementos del array desde la entrada del usuario
    cout << "Ingrese " << n << " elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Llamar a la función de ordenamiento
    countSort(array, n);

    // Mostrar el array ordenado
    cout << "Array ordenado: ";
    printArray(array, n);

    return 0;
}