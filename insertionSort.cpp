#include "insertionSort.h"
#include "funcionesGlobales.h"


using namespace std;

// Función para imprimir un arreglo

// Función de ordenamiento por inserción
void insertionSort(int array[], int size) {
  clock_t start_time = clock(); // Inicio del temporizador
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compara la clave con cada elemento a la izquierda de ella hasta que encuentre un elemento más pequeño
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;

    // Mostrar el arreglo después de cada paso de inserción
    cout << "Iteración " << step << ": ";
    printArray(array, size);
  }
  clock_t end_time = clock(); // Fin del temporizador
  double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
  cout << "Tiempo total de ordenamiento: " << elapsed_time << " segundos" << endl;
}

// Función para leer los datos desde el archivo "Array.txt"
bool leerDesdeArchivo(int array[], int& size) {
  ifstream archivo("Array.txt");
  if (archivo.is_open()) {
    int valor, index = 0;
    while (archivo >> valor) {
      array[index++] = valor;
    }
    size = index;
    archivo.close();
    return true;
  }
  return false;
}

// Función para leer los datos desde el teclado
void leerDesdeTeclado(int array[], int& size) {
  cout << "¿Cuántos elementos quieres ingresar? ";
  cin >> size;
  for (int i = 0; i < size; i++) {
    cout << "Ingresa el valor " << i + 1 << ": ";
    cin >> array[i];
  }
}

// Función principal
int callInsertion(){
  int data[100];  // Arreglo de tamaño fijo 100, puedes ajustar este valor según sea necesario
  int size = 0;

  int opcion;
  cout << "Selecciona una opción para ingresar los datos:\n";
  cout << "1. Usar los valores predefinidos\n";
  cout << "2. Leer desde el archivo 'Array.txt'\n";
  cout << "3. Ingresar datos por teclado\n";
  cout << "Opción: ";
  cin >> opcion;

  switch(opcion) {
    case 1:
      // Valores predefinidos
      {
        int predefinidos[] = {9, 5, 1, 4, 3};
        size = sizeof(predefinidos) / sizeof(predefinidos[0]);
        for (int i = 0; i < size; i++) {
          data[i] = predefinidos[i];
        }
        cout << "Valores predefinidos cargados:\n";
        printArray(data, size);
      }
      break;
      
    case 2:
      // Intentamos leer desde el archivo primero
      if (!leerDesdeArchivo(data, size)) {
        cout << "No se encontró el archivo 'array.txt'.\n";
      } else {
        cout << "Datos leídos desde 'array.txt':\n";
        printArray(data, size);
      }
      break;
      
    case 3:
      // Leer desde teclado
      leerDesdeTeclado(data, size);
      break;
      
    default:
      cout << "Opción no válida, terminando programa.\n";
      return 1;
  }

  // Imprimir el arreglo original
  cout << "\nArreglo original:\n";
  printArray(data, size);

  // Ordenar el arreglo
  insertionSort(data, size);

  // Imprimir el arreglo ordenado
  cout << "Arreglo ordenado en orden ascendente:\n";
  printArray(data, size);

  return 0;
}
