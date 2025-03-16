#include "funcionesGlobales.h"
#include "heapSort.h"
using namespace std;
using namespace std::chrono;
// Función para mantener la propiedad de Heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa el nodo raíz como el más grande
    int left = 2 * i + 1; // Índice del hijo izquierdo
    int right = 2 * i + 2; // Índice del hijo derecho

    // Verifica si el hijo izquierdo es mayor que la raíz
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // Verifica si el hijo derecho es mayor que el mayor hasta ahora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el mayor no es la raíz, intercambia y continúa el heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
// Implementación de Heap Sort
void heapSort(int arr[], int n) {
    // Construir el Heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Mueve la raíz al final
        heapify(arr, i, 0); // Llama a heapify en el subárbol reducido
    }
}
int callHeap() {
    int opcion;
    cout << "Seleccione el modo de entrada:\n";
    cout << "1. Array quemado\n";
    cout << "2. Ingresar valores manualmente\n";
    cout << "3. Leer desde archivo\n";
    cin >> opcion;
    
    int *arr;
    int size;
    
    if (opcion == 1) {
        int data[] = {1, 12, 9, 5, 6, 10};
        size = sizeof(data) / sizeof(data[0]);
        arr = data;
    } else if (opcion == 2) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        arr = new int[size];
        cout << "Ingrese los elementos del array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    } else if (opcion == 3) {
        ifstream inputFile("array.txt");
        if (!inputFile) {
            cout << "Error: No se pudo abrir el archivo." << endl;
            return 1;
        }
        inputFile >> size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            inputFile >> arr[i];
        }
        inputFile.close();
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }
    
    cout << "--- El Array original fue: \n";
    printArray(arr, size);
    
    auto start = high_resolution_clock::now();
    heapSort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "--- El Array ordenado es:\n";
    printArray(arr, size);
    cout << "--- Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
    
    if (opcion == 2 || opcion == 3) {
        delete[] arr;
    }
    
    return 0;
}