#include "radixSort.h"
#include "funcionesGlobales.h"


using namespace std;
using namespace std::chrono;






int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}


void countingSort(int array[], int size, int place) {
    const int max = 10; 
    int output[size];
    int count[max] = {0};

    
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}


void radixSort(int array[], int size) {
    int max = getMax(array, size);

    
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
        
        int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
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

