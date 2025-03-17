#include "selectionSort.h"
#include "funcionesGlobales.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
        cout << "--- Antes del swap " << step + 1 << ": ";
        printArray(array, size);
    }
}

void selection_sort() {
    while (true) {
        cout << "--- Ingrese opcion 1 para Array quemado.\n";
        cout << "--- Ingrese opcion 2 para Array teclado.\n";
        cout << "--- Ingrese opcion 3 para Array texto.\n";
        cout << "--- Ingrese opcion 4 para salir.\n";
        int mode;
        cin >> mode;

        int *data = nullptr;
        int size = 0;

        if (mode == 1) {
            int tempData[] = {20, 12, 10, 15, 2};
            size = sizeof(tempData) / sizeof(tempData[0]);
            data = new int[size];
            copy(tempData, tempData + size, data);
        } else if (mode == 2) {
            cout << "--- Ingrese el tamaño del Array:\n";
            cin >> size;
            data = new int[size];
            cout << "--- Ingrese los números del array:\n";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
        } else if (mode == 3) {
            ifstream inputFile("array.txt");
            if (!inputFile.is_open()) {
                cout << "--- Error: No se pudo abrir el archivo.\n";
                continue;
            }
            inputFile >> size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                inputFile >> data[i];
            }
            inputFile.close();
        } else if (mode == 4) {
            cout << "--- Saliendo del programa.\n";
            break;
        } else {
            cout << "--- Opción inválida, intente nuevamente.\n";
            continue;
        }

        cout << "--- El Array original fue: \n";
        printArray(data, size);
        cout << "--- El ordenamiento que se realiza es:\n";

        auto start = high_resolution_clock::now();
        selectionSort(data, size);
        auto stop = high_resolution_clock::now();

        cout << "--- El Array ordenado es:\n";
        printArray(data, size);

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "--- El tiempo que demoró hacer el proceso es: " << duration.count() << " microsegundos" << endl;

        delete[] data;
    }
}
