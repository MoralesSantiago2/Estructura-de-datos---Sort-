#include "funcionesGlobales.h"
#include "binarySort.h"
using namespace std;
int binarySearch(int array[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;
    //busca la mitad del array
    if (x == array[mid])
      return mid;
    //compara si el número a encontrar es mayor que el de la mitad
    if (x > array[mid]){
      low = mid + 1;
      printf("valor nuevo tomado por low \n");
      printf("%i \n", low);
    }
    else {
      high = mid - 1;
      printf("valor nuevo tomado por high \n");
      printf("%i \n", high);
    }
  }
  

  return -1;
}
//Función de array establecido
int arrayEstablecido() {
//define el array que debe estar ordenado
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  for(int i = 0; i < 7; i++){
      printf("%i ", array[i]);
  }
  printf("\n");
  int x = 4;
  //verifica tamaño del array
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Elemento encontrado en la posición %d del array", result);
return 0;
}
//Función donde el array lo establece el usuario
int establecerArray(){
    int sizeArrayUser;
    //tamaño de array por teclado
    printf("Ingrese el tamaño del array: ");
    cin >> sizeArrayUser;
    int array[sizeArrayUser];
    //llenado de array
    for(int i = 0; i < sizeArrayUser; i++){
        printf("Ingrese número %i para llenar el array en orden: ", i);
        cin >> array[i];
    }
    //número a encontrar
    int x;
    printf("Qué número del array quiere encontrar: ");
    cin >> x;
    //verifica que sea un solo array
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    //Verifica si existe o no existe el número a encontrar
    if (result == -1)
        printf("Not found");
    else
        printf("Elemento encontrado en la posición %d del array", result);
return 0;
}
//Función de array establecido
int arrayArchivo(){
  // Abrir el archivo de entrada
  ifstream inputFile("array.txt");
//if para ver si el archivo esta abriendo.
  if (!inputFile.is_open()) {
    cout << "--- Error: No se pudo abrir el archivo.\n"<< endl;
  }
  int size;
// Leer el tamaño del array desde el archivo.
  inputFile >> size;
// Crear un array del tamaño especificado.
  int array[size];
// Lee los elementos del array.
  for (int i = 0; i < size; i++) {
    inputFile >> array[i];
    printf("%i ", array[i]);
  }
//cerrar el archivo
  inputFile.close();
  printf("\n");
  int x;
  printf("Qué número del array quiere encontrar: ");
  cin >> x;
  //verifica tamaño del array
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Elemento encontrado en la posición %d del array", result);
return 0;
}
//menú para escoger que operación hacer
int callBinary(){
    int opcion;
    printf("Menú Binary Search \n");
    printf("1. Array Establecido\n");
    printf("2. Establecer Array\n");
    printf("3. Array por archivo\n");
    printf("Seleccione una opción: ");
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        arrayEstablecido();
        break;
    case 2:
        establecerArray();
        break;
    case 3:
        arrayArchivo();
        break;
    default:
        break;
    }
return 0;
}