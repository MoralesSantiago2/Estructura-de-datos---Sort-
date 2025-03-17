#include "funcionesGlobales.h"
#include "shellsort.h"
#include <iostream>
#include <sys/timeb.h> 

using namespace std;

void ordenarShell(int arr[], int n) {
    int gap = n / 2;
    
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; 
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            arr[j] = temp;
        }
        
        gap /= 2;
    }
}

int ejecutarShell() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    int arr[n];

    cout << "Ingrese los numeros, uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nArreglo original: ";
    mostrarArray(arr, n);

    struct timeb inicio, fin;
    ftime(&inicio);  

    ordenarShell(arr, n);

    ftime(&fin);  
    int tiempoTotal = (int)(1000 * (fin.time - inicio.time) + (fin.millitm - inicio.millitm));

    cout << "Arreglo ordenado: ";
    mostrarArray(arr, n);

    cout << "Tiempo de ejecución: " << tiempoTotal << " ms" << endl;

    return 0;
}

