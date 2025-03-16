#include "funcionesGlobales.h"
#include "linearSort.h"

using namespace std;

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x)
            return i;
    }
    return -1;
}
// Función de array establecido
int ArrayEstablecido() {
    int array[] = {2, 4, 0, 1, 9};
    int x = 0;
    int n = sizeof(array) / sizeof(array[0]);
    int result = linearSearch(array, n, x);
    
    (result == -1) ? cout << "Element not found\n" : cout << "Element found at index: " << result << endl;
    
    return 0;
}
// Función donde el array lo establece el usuario
int EstablecerArray() {
    int sizeArrayUser;
    
    // Tamaño del array por teclado
    cout << "Ingrese el tamaño del array: ";
    cin >> sizeArrayUser;

    // Usar memoria dinámica para el array
    int* array = new int[sizeArrayUser];

    // Llenado de array
    cout << "Ingrese los números en el array:\n";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> array[i];
    }

    // 🔹 Mostrar el array antes de buscar
    cout << "El array ingresado es: { ";
    for (int i = 0; i < sizeArrayUser; i++) {
        cout << array[i] << " ";
    }
    cout << "}\n";

    // Número a encontrar
    int x;
    cout << "Qué número del array quiere encontrar: ";
    cin >> x;

    int result = linearSearch(array, sizeArrayUser, x);
    
    // Verifica si existe o no existe el número a encontrar
    (result == -1) ? cout << "Element not found\n" : cout << "Element found at index: " << result << endl;
    
    // Liberar memoria dinámica
    delete[] array;

    return 0;
}
// Menú para escoger qué operación hacer
int linearcall() {
    int opcion;
    cout << "Menú Linear Search\n";
    cout << "1. Array Establecido\n";
    cout << "2. Establecer Array\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            ArrayEstablecido();
            break;
        case 2:
            EstablecerArray();
            break;
        default:
            cout << "Opción no válida\n";
            break;
    }

    return 0;
}