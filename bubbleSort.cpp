#include "bubblesort.h"
#include "funcionesGlobales.h"


// Para medir el tiempo de ejecución
using namespace std;
using namespace std::chrono;

// Función para imprimir el arreglo


// Función para realizar el ordenamiento de burbuja optimizado
int bubbleSort(int array[], int size, bool debugMode) {
    int totalSteps = 0; // Contador de pasadas

    for (int step = 0; step < (size - 1); ++step) {
        int swapped = 0; // Variable para verificar si hubo intercambios

        if (debugMode) {
            cout << "Pasada " << step + 1 << ":\n";
        }

        for (int i = 0; i < (size - step - 1); ++i) {
            if (debugMode) {
                cout << "  Comparando " << array[i] << " y " << array[i + 1];
            }

            if (array[i] > array[i + 1]) {
                if (debugMode) {
                    cout << " -> Intercambiando (porque " << array[i] << " > " << array[i + 1] << ")\n";
                }

                // Intercambiar elementos
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1; // Marcar que hubo un intercambio
            } else if (debugMode) {
                cout << " -> No se intercambia (porque " << array[i] << " <= " << array[i + 1] << ")\n";
            }

            if (debugMode) {
                cout << "  Estado actual del arreglo:\n";
                printArray(array, size);
                cout << "  Presiona Enter para continuar...\n";
                cin.ignore(); // Esperar a que el usuario presione Enter
            }
        }

        totalSteps++; // Incrementar el contador de pasadas

        if (debugMode) {
            cout << "Estado del arreglo después de la pasada " << step + 1 << ":\n";
            printArray(array, size);
        }

        // Si no hubo intercambios, el arreglo ya está ordenado
        if (swapped == 0) {
            if (debugMode) {
                cout << "No hubo intercambios en este paso, el arreglo ya está ordenado.\n";
            }
            break;
        }

        if (debugMode) {
            cout << "Presiona Enter para avanzar al siguiente paso...";
            cin.ignore();
        }
    }

    return totalSteps; // Devolver el número total de pasadas
}

int callBubble() {
    while (true) { // Bucle principal para permitir múltiples ejecuciones
        int choice;
        int size = 0;
        int data[100]; // Tamaño máximo del arreglo

        // Mostrar el menú y validar la opción ingresada
        while (true) {
            cout << "Seleccione una opción:\n";
            cout << "1. Usar el arreglo por defecto\n";
            cout << "2. Ingresar el arreglo manualmente\n";
            cout << "3. Salir\n";
            cout << "Opción: ";
            cin >> choice;

            if (choice >= 1 && choice <= 3) {
                break; // Salir del bucle si la opción es válida
            } else {
                cout << "Opción no válida. Intenta de nuevo con una opción disponible.\n";
            }
        }

        if (choice == 3) { // Salir del programa
            cout << "Saliendo del programa...\n";
            break;
        }

        switch (choice) {
            case 1: {
                // Arreglo por defecto
                int defaultData[] = {-2, 45, 0, 11, -9};
                size = sizeof(defaultData) / sizeof(defaultData[0]);
                for (int i = 0; i < size; ++i) {
                    data[i] = defaultData[i];
                }
                break;
            }
            case 2: {
                // Ingresar el arreglo manualmente
                cout << "Ingrese el número de elementos: ";
                cin >> size;
                cout << "Ingrese los elementos:\n";
                for (int i = 0; i < size; ++i) {
                    cin >> data[i];
                }
                break;
            }
        }

        // Guardar una copia del arreglo original para mostrarlo después
        int originalData[size];
        for (int i = 0; i < size; ++i) {
            originalData[i] = data[i];
        }

        // Primera ejecución: Sin salidas en pantalla, solo medir el tiempo
        auto start = high_resolution_clock::now();
        int totalStepsNormal = bubbleSort(data, size); // Ejecución sin depuración
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        // Mostrar el tiempo de ejecución y el número de pasadas
        cout << "Tiempo de ejecución: " << duration.count() << " microsegundos\n";
        cout << "Pasadas necesarias: " << totalStepsNormal << "\n";

        // Mostrar el arreglo original y el arreglo ordenado
        cout << "\nArreglo original:\n";
        printArray(originalData, size);

        cout << "Arreglo ordenado:\n";
        printArray(data, size);

        // Mensaje para iniciar el análisis paso a paso
        cout << "\nVamos a analizarlo. Presiona Enter para continuar...";
        cin.ignore(); // Esperar a que el usuario presione Enter
        cin.ignore(); // Limpiar el buffer de entrada

        // Reiniciar el arreglo para el análisis paso a paso
        int dataDebug[size];
        for (int i = 0; i < size; ++i) {
            dataDebug[i] = originalData[i];
        }

        // Ejecutar en modo de depuración (paso a paso)
        cout << "Arreglo original:\n";
        printArray(dataDebug, size);
        int totalStepsDebug = bubbleSort(dataDebug, size, true);

        cout << "Arreglo ordenado en orden ascendente:\n";
        printArray(dataDebug, size);
        cout << "Pasadas necesarias: " << totalStepsDebug << "\n";

        // Verificación adicional para mostrar que el arreglo ya está ordenado
        cout << "\nOk, vamos a comprobar si está ordenado.\n";
        cout << "Presiona Enter para continuar...";
        cin.ignore(); // Esperar a que el usuario presione Enter

        // Ejecutar el algoritmo nuevamente en modo de depuración
        bubbleSort(dataDebug, size, true);

        // Preguntar si desea ordenar otro arreglo
        int repeat;
        while (true) {
            cout << "\n¿Quiere ordenar otro arreglo? (1: Sí, 0: No): ";
            cin >> repeat;

            if (repeat == 0 || repeat == 1) {
                break; // Salir del bucle si la opción es válida
            } else {
                cout << "Opción no válida. Intenta de nuevo con una opción disponible.\n";
            }
        }

        if (repeat == 0) {
            break; // Salir del bucle si el usuario no desea continuar
        }
    }

    return 0;
}