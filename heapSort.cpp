#include "funcionesGlobales.h"
#include "heapSort.h"
#include <iostream>
#include <sys/timeb.h> 
#include <fstream>

using namespace std;

void ajustarMonticulo(int arr[], int n, int i) {
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && arr[izquierda] > arr[mayor])
        mayor = izquierda;
    
    if (derecha < n && arr[derecha] > arr[mayor])
        mayor = derecha;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        ajustarMonticulo(arr, n, mayor);
    }
}

void ordenarMonticulo(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        ajustarMonticulo(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        ajustarMonticulo(arr, i, 0);
    }
}

int ejecutarHeap() {
    int opcion;
    cout << "Seleccione el modo de entrada:\n";
    cout << "1. Array predeterminado\n";
    cout << "2. Ingresar valores manualmente\n";
    cout << "3. Leer desde archivo\n";
    cin >> opcion;
    
    int *arr = nullptr;
    int size = 0;
    
    if (opcion == 1) {
        size = 6;
        arr = new int[size]{1, 12, 9, 5, 6, 10};
    } else if (opcion == 2) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        arr = new int[size];
        cout << "Ingrese los elementos: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    } else if (opcion == 3) {
        ifstream archivo("array.txt");
        if (!archivo) {
            cout << "Error: No se pudo abrir el archivo." << endl;
            return 1;
        }
        archivo >> size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            archivo >> arr[i];
        }
        archivo.close();
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }
    
    cout << "--- El Array original fue: \n";
    mostrarArray(arr, size);
    
    struct timeb inicio, fin;
    ftime(&inicio);

    ordenarMonticulo(arr, size);

    ftime(&fin);
    int tiempoTotal = (int)(1000 * (fin.time - inicio.time) + (fin.millitm - inicio.millitm));

    cout << "--- El Array ordenado es:\n";
    mostrarArray(arr, size);
    cout << "--- Tiempo de ejecución: " << tiempoTotal << " ms" << endl;
    
    delete[] arr;
    
    return 0;
}
