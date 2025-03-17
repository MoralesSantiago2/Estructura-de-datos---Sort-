#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void countSort(int array[], int size) {
    auto start = chrono::high_resolution_clock::now(); 
    
    if (size == 0) return; 

    int max = array[0]; 

    
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    
    int* count = new int[max + 1]();  
    int* output = new int[size](); 

    
    cout << "\nPaso 1: Contar la frecuencia de cada número\n";
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    
    for (int i = 0; i <= max; i++) {
        if (count[i] > 0)
            cout << "Número " << i << " aparece " << count[i] << " veces.\n";
    }

    
    cout << "\nPaso 2: Convertir el array de conteo en acumulativo\n";
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    
    for (int i = 0; i <= max; i++) {
        if (count[i] > 0)
            cout << "Conteo acumulado de " << i << ": " << count[i] << "\n";
    }

    
    cout << "\nPaso 3: Construir el array ordenado paso a paso\n";
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
        
        cout << "Insertando " << array[i] << " en la posición " << count[array[i]] << " -> ";
        for (int j = 0; j < size; j++) {
            if (j < size - 1)
                cout << output[j] << " ";
            else
                cout << output[j] << "\n";
        }
    }

    
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    delete[] count; 
    delete[] output;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start; 

    cout << "\nTiempo de ejecución: " << elapsed.count() << " segundos\n";  
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int* leerDesdeArchivo(const string &nombreArchivo, int size) { 
    ifstream archivo(nombreArchivo); 
    
    if (!archivo) { 
        cerr << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'\n";
        return nullptr; 
        

    int* datos = new int[size]; 

    for (int i = 0; i < size; i++) {
        if (!(archivo >> datos[i])) { 
            cerr << "Error: No hay suficientes datos en el archivo.\n";
            delete[] datos; 
            return nullptr; 
        }
    }

    archivo.close(); 
    return datos; 
}

int main() {
    int *array = nullptr; 
    int size = 0;
    int opcion;
    string nombreArchivo;
    
    cout << "Seleccione el método de entrada de datos:\n";
    cout << "1. Ingresar datos manualmente\n";
    cout << "2. Leer datos desde un archivo\n";
    cout << "3. Usar datos predefinidos (quemados en el código)\n";
    cout << "Opción: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;

        if (size <= 0) {
            cerr << "Tamaño inválido.\n";
            return 1; 
        }

        array = new int[size]; 

        cout << "Ingrese " << size << " elementos:\n";
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }

    } else if (opcion == 2) {
        cout << "Ingrese el tamaño del array: ";
        cin >> size;

        if (size <= 0) {
            cerr << "Tamaño inválido.\n";
            return 1;
        }

        cout << "Ingrese el nombre del archivo (ejemplo: datos.txt): ";
        cin >> nombreArchivo;

        array = leerDesdeArchivo(nombreArchivo, size);
        if (array == nullptr) {
            return 1; 
        }
    } else if (opcion == 3) {
        size = 10;
        array = new int[size]{10, 7, 3, 8, 5, 2, 9, 6, 4, 1}; 
        cout << "Usando datos predefinidos.\n";
    } else {
        cout << "Opción inválida.\n";
        return 1;
    }

    
    cout << "\nArray original: ";
    printArray(array, size);

    countSort(array, size);

    
    cout << "\nArray ordenado: ";
    printArray(array, size);

    delete[] array; 

    return 0; 
}
