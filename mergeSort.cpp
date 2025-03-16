#include "mergeSort.h"
#include "funcionesGlobales.h"

using namespace std;
using namespace std::chrono;


// Función para combinar dos subarrays en Merge Sort
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}

// Función auxiliar recursiva para Merge Sort
void mergeSortHelper(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(array, left, mid);
        mergeSortHelper(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// Función principal de Merge Sort
void mergeSort(int array[], int size) {
    mergeSortHelper(array, 0, size - 1);
}

// Menú para Merge Sort con cronómetro
void merge_sort() {
    cout << "--- Seleccione el modo de entrada ---\n";
    cout << "1. Array quemado\n2. Array por teclado\n3. Array por archivo\n";

    int mode;
    cin >> mode;

    int data[100]; // Tamaño máximo de 100 (puedes cambiarlo según sea necesario)
    int size = 0;

    if (mode == 1) {
        // Array quemado
        int temp[] = {20, 12, 10, 15, 2};
        size = sizeof(temp) / sizeof(temp[0]);
        for (int i = 0; i < size; i++) data[i] = temp[i];

    } else if (mode == 2) {
        // Array por teclado
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        cout << "Ingrese los elementos:\n";
        for (int i = 0; i < size; i++) cin >> data[i];

    } else if (mode == 3) {
        // Array por archivo
        ifstream inputFile("array.txt");
        if (!inputFile) {
            cout << "Error al abrir el archivo.\n";
            return;
        }
        inputFile >> size;
        for (int i = 0; i < size; i++) inputFile >> data[i];
        inputFile.close();
    } else {
        cout << "Opción inválida.\n";
        return;
    }

    // Mostrar array original
    cout << "\n--- Array original ---\n";
    printArray(data, size);

    // Iniciar cronómetro
    auto start = high_resolution_clock::now();

    // Ordenar con Merge Sort
    mergeSort(data, size);

    // Detener cronómetro
    auto stop = high_resolution_clock::now();

    // Mostrar resultados
    cout << "\n--- Array ordenado ---\n";
    printArray(data, size);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "--- Tiempo de ejecución: " << duration.count() << " microsegundos\n";
}

// Función principal
int callMerge() {
    merge_sort();
    return 0;
}
