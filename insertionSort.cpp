#include "insertionSort.h"
#include "funcionesGlobales.h"


using namespace std;




void insertionSort(int array[], int size) {
  clock_t start_time = clock(); 
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;

    
    cout << "Iteración " << step << ": ";
    printArray(array, size);
  }
  clock_t end_time = clock(); 
  double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC; 
  cout << "Tiempo total de ordenamiento: " << elapsed_time << " segundos" << endl;
}


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


void leerDesdeTeclado(int array[], int& size) {
  cout << "¿Cuántos elementos quieres ingresar? ";
  cin >> size;
  for (int i = 0; i < size; i++) {
    cout << "Ingresa el valor " << i + 1 << ": ";
    cin >> array[i];
  }
}


int callInsertion(){
  int data[100];  
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
      
      if (!leerDesdeArchivo(data, size)) {
        cout << "No se encontró el archivo 'array.txt'.\n";
      } else {
        cout << "Datos leídos desde 'array.txt':\n";
        printArray(data, size);
      }
      break;
      
    case 3:
    
      leerDesdeTeclado(data, size);
      break;
      
    default:
      cout << "Opción no válida, terminando programa.\n";
      return 1;
  }

 
  cout << "\nArreglo original:\n";
  printArray(data, size);

  
  insertionSort(data, size);

 
  cout << "Arreglo ordenado en orden ascendente:\n";
  printArray(data, size);

  return 0;
}
