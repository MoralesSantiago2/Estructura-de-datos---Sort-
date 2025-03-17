#include "funcionesGlobales.h"
#include "linearSort.h"
#include <ctime>

using namespace std;

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int ArrayPredefinido() {
    int array[] = {2, 4, 0, 1, 9};
    int x;
    int n = sizeof(array) / sizeof(array[0]);
    
    cout << "Ingrese el número a buscar: ";
    cin >> x;
    
    clock_t start = clock();
    int result = linearSearch(array, n, x);
    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    
    (result == -1) ? cout << "Elemento no encontrado\n" : cout << "Elemento encontrado en la posición: " << result << endl;
    cout << "Tiempo de búsqueda: " << tiempo << " segundos" << endl;
    
    return 0;
}

int IngresarArray() {
    int sizeArrayUser;
    cout << "Ingrese el tamaño del array: ";
    cin >> sizeArrayUser;
    
    int* array = new int[sizeArrayUser];
    
    cout << "Ingrese los números en el array:\n";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> array[i];
    }
    
    cout << "El array ingresado es: { ";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << array[i] << " ";
    }
    cout << "}\n";
    
    int x;
    cout << "Ingrese el número a buscar: ";
    cin >> x;
    
    clock_t start = clock();
    int result = linearSearch(array, sizeArrayUser, x);
    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;
    
    (result == -1) ? cout << "Elemento no encontrado\n" : cout << "Elemento encontrado en la posición: " << result << endl;
    cout << "Tiempo de búsqueda: " << tiempo << " segundos" << endl;
    
    delete[] array;
    return 0;
}

int linearcall() {
    int opcion;
    cout << "Menú Linear Search\n";
    cout << "1. Array Predefinido\n";
    cout << "2. Ingresar Array\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            ArrayPredefinido();
            break;
        case 2:
            IngresarArray();
            break;
        default:
            cout << "Opción no válida\n";
            break;
    }
    return 0;
}
