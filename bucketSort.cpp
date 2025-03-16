#include "funcionesGlobales.h"
#include "bucketSort.h"

#define NBUCKET 6  // Número de buckets
#define INTERVAL 10  // Capacidad de cada bucket
using namespace std;
using namespace std::chrono;
// Estructura para los nodos de la lista enlazada
struct Node {
    int data;
    struct Node *next;
};
// Función de ordenamiento por Bucket Sort
void bucketSort(int arr[], int n) {
    Node *buckets[NBUCKET] = {nullptr};

    // Distribuir los elementos en los buckets
    cout << "\nDistribuyendo elementos en los buckets..." << endl;
    for (int i = 0; i < n; i++) {
        int pos = getBucketIndex(arr[i]);
        Node *current = new Node{arr[i], buckets[pos]};
        buckets[pos] = current;
        cout << "Elemento " << arr[i] << " colocado en el bucket " << pos << endl;
    }

    // Imprimir los buckets antes de ordenarlos
    for (int i = 0; i < NBUCKET; i++) {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }

    // Ordenar los elementos dentro de cada bucket
    for (int i = 0; i < NBUCKET; i++) {
        buckets[i] = insertionSort(buckets[i]);
    }

    // Imprimir los buckets después de ordenarlos
    cout << "\nBuckets después de ordenar:" << endl;
    for (int i = 0; i < NBUCKET; i++) {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }

    // Fusionar los elementos ordenados de los buckets en el array original
    int index = 0;
    for (int i = 0; i < NBUCKET; i++) {
        Node *node = buckets[i];
        while (node) {
            arr[index++] = node->data;
            Node *tmp = node;
            node = node->next;
            delete tmp;
        }
    }
}
// Función de ordenamiento por inserción para cada bucket
struct Node *insertionSort(struct Node *list) {
    if (!list || !list->next) return list;

    Node *sorted = nullptr;
    while (list) {
        Node *current = list;
        list = list->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sorted;
}
// Función para obtener el índice del bucket correspondiente
int getBucketIndex(int value) {
    return value / INTERVAL;
}
// Función para imprimir los elementos de un bucket
void printBuckets(struct Node *list) {
    struct Node *cur = list;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}
int callBucket() {
    int opcion;
    cout << "Seleccione el modo de entrada:\n";
    cout << "1. Array quemado\n";
    cout << "2. Ingresar valores manualmente\n";
    cout << "3. Leer desde archivo\n";
    cin >> opcion;

    int *arr = nullptr;
    int size = 0;

    if (opcion == 1) {
        size = 7;
        arr = new int[size]{42, 32, 33, 52, 37, 47, 51};
    } else if (opcion == 2) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        cin.ignore();
        arr = new int[size];
        cout << "Ingrese los elementos del array separados por espacio: ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        for (int i = 0; i < size; i++) {
            ss >> arr[i];
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
    bucketSort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "--- El Array ordenado es:\n";
    printArray(arr, size);
    cout << "--- Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;

    // Liberar memoria dinámica
    delete[] arr;

    return 0;
}