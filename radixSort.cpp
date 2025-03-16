#include "radixSort.h"
#include "funcionesGlobales.h"


using namespace std;
using namespace std::chrono;

// Declaración de funciones



// Obtiene el valor máximo en el array
int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Ordena el array usando Counting Sort en base al dígito actual
void countingSort(int array[], int size, int place) {
    const int max = 10; // Para los dígitos (0-9)
    int output[size];
    int count[max] = {0};

    // Cuenta la frecuencia de cada dígito en la posición actual
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calcula las posiciones acumulativas
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Construye el array ordenado
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    // Copia los valores ordenados de vuelta al array original
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Implementación de Radix Sort
void radixSort(int array[], int size) {
    int max = getMax(array, size);

    // Ordena el array aplicando Counting Sort para cada posición decimal
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

int callRadix(){
    int opcion;
    cout << "Seleccione el modo de entrada:\n";
    cout << "1. Array quemado\n";
    cout << "2. Ingresar valores manualmente\n";
    cout << "3. Leer desde archivo\n";
    cin >> opcion;
    
    int *arr;
    int size;
    
    if (opcion == 1) {
        // Opción de array predefinido
        int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
        size = sizeof(data) / sizeof(data[0]);
        arr = data;
    } else if (opcion == 2) {
        // Opción de ingreso manual
        cout << "Ingrese el tamaño del array: ";
        cin >> size;
        arr = new int[size];
        cout << "Ingrese los elementos del array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    } else if (opcion == 3) {
        // Opción de lectura desde archivo
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
    
    // Medir el tiempo de ejecución
    auto start = high_resolution_clock::now();
    radixSort(arr, size);
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

