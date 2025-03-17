#include "funcionesGlobales.h"
#include "binarySort.h"
using namespace std;
int binarySearch(int array[], int x, int low, int high) {
  
	
  while (low <= high) {
    int mid = low + (high - low) / 2;
   
    if (x == array[mid])
      return mid;
 
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

int arrayEstablecido() {

  int array[] = {3, 4, 5, 6, 7, 8, 9};
  for(int i = 0; i < 7; i++){
      printf("%i ", array[i]);
  }
  printf("\n");
  int x = 4;
 
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Elemento encontrado en la posición %d del array", result);
return 0;
}

int establecerArray(){
    int sizeArrayUser;
    
    printf("Ingrese el tamaño del array: ");
    cin >> sizeArrayUser;
    int array[sizeArrayUser];
  
    for(int i = 0; i < sizeArrayUser; i++){
        printf("Ingrese número %i para llenar el array en orden: ", i);
        cin >> array[i];
    }
    
    int x;
    printf("Qué número del array quiere encontrar: ");
    cin >> x;
    
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    
    if (result == -1)
        printf("Not found");
    else
        printf("Elemento encontrado en la posición %d del array", result);
return 0;
}

int arrayArchivo(){
 
  ifstream inputFile("array.txt");

  if (!inputFile.is_open()) {
    cout << "--- Error: No se pudo abrir el archivo.\n"<< endl;
  }
  int size;

  inputFile >> size;

  int array[size];

  for (int i = 0; i < size; i++) {
    inputFile >> array[i];
    printf("%i ", array[i]);
  }

  inputFile.close();
  printf("\n");
  int x;
  printf("Qué número del array quiere encontrar: ");
  cin >> x;
  
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Elemento encontrado en la posición %d del array", result);
return 0;
}

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