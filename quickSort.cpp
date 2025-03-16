#include "funcionesGlobales.h"
#include "quickSort.h"

#include <iostream>
#include <iomanip> // Para mostrar el tiempo en notaci—n cient’fica
#include <ctime>   // Para medir el tiempo de ejecuci—n

using namespace std;

/**
 * Funcion para dividir el arreglo en dos partes y colocar el pivote en su posicion correcta.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Se elige el ultimo elemento como pivote
    int i = low - 1; // Indice del menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { 
            i++; // Incrementa el indice del menor elemento
            swap(arr[i], arr[j]); // Intercambia elementos
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca el pivote en su posicion correcta
    return i + 1;
}

/**
 * Funcion recursiva de Quicksort.
 */
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Encuentra el indice del pivote
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

/**
 * Implementaci—n iterativa de Quicksort.
 */
void quicksortIterativo(int arr[], int low, int high) {
    int stack[high - low + 1];
    int top = -1;
    
    stack[++top] = low;
    stack[++top] = high;
    
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        
        int pi = partition(arr, low, high);
        
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}





int callQuick() {
    int opcion;
    
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Ordenar con Quicksort Recursivo\n";
        cout << "2. Ordenar con Quicksort Iterativo\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opci—n: ";
        cin >> opcion;
        
        if (opcion == 3) {
            cout << "Saliendo del programa...\n";
            break;
        }
        
        int n;
        cout << "Ingrese el tama–o del arreglo (m‡x 1000): ";
        cin >> n;
        
        if (n <= 0 || n > 1000) {
            cout << "Tama–o inv‡lido. Intente nuevamente.\n";
            continue;
        }
        
        int arr[n];
        cout << "Ingrese los elementos del arreglo: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        clock_t start, end;
        if (opcion == 1) {
            start = clock();
            quicksort(arr, 0, n - 1);
            end = clock();
            cout << "Array ordenado (Recursivo): ";
        } else if (opcion == 2) {
            start = clock();
            quicksortIterativo(arr, 0, n - 1);
            end = clock();
            cout << "Array ordenado (Iterativo): ";
        } else {
            cout << "Opci—n inv‡lida. Intente de nuevo.\n";
            continue;
        }
        
        printArray(arr, n);
        cout << "Tiempo de ejecuci—n: " << scientific << double(end - start) / CLOCKS_PER_SEC << " segundos\n";
    }
    
    return 0;
}
