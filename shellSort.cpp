#include "funcionesGlobales.h"
#include "shellsort.h"
using namespace std;
void shellSort(int arr[], int n) {
    // Definir el espacio inicial (gap)
    int gap = n / 2;

    // Reducir el gap en cada iteración
    while (gap > 0) {
        // Aplicar el algoritmo de inserción para cada sublista
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Guardar el valor actual
            int j = i;

            // Mover los elementos de la sublista
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            // Colocar el valor temporal en su posición correcta
            arr[j] = temp;
        }
        // Reducir el gap a la mitad
        gap /= 2;
    }
}
// Función para imprimir un arreglo
int callShell() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    // Crear un arreglo dinámico de tamaño n
    int* arr = new int[n];

    // Pedir al usuario que ingrese los números
    cout << "Ingrese los numeros, uno por uno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mostrar el arreglo original
    cout << "\nArreglo original: ";
    printArray(arr, n);

    // Llamar a la función shellSort
    shellSort(arr, n);

    // Mostrar el arreglo ordenado
    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    // Liberar la memoria dinámica
    delete[] arr;

    return 0;
}