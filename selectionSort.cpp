#include "selectionSort.h"
#include "funcionesGlobales.h"

using namespace std;
using namespace std::chrono;
//declaracion de funciones que vamos a necesitar
void swap(int *a, int *b);
void selection_sort();
void selectionSort(int array[], int size);
//menu principal.
//funcion de intercambio.
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// función que imprime el Array.
//funcion del selection sort.
void selectionSort(int array[], int size){
   for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
   for (int i = step + 1; i < size; i++) {

// Para ordenar en orden descendente, cambie > por < en esta línea.
// Seleccione el elemento mínimo en cada bucle.
      if (array[i] < array[min_idx])
        min_idx = i;
   }
// coloca min en la posición correcta
    swap(&array[min_idx], &array[step]);
    cout << "--- Antes del swap" << step + 1 << ": ";
    printArray(array, size);
  }
}
//menu unterno para seleccion modo, array quemado, array por teclado, array por txt
//donde el txt debe se llamado (array.txt).
//dentro de cada seleccion tiene incluido un cronometro el cual ayuda a saber 
//el tiempo de ejecucion del codigo.
void selection_sort(){
   cout << "--- ingrese opcion 1 para Array quemado.\n";
   cout << "--- ingrese opcion 2 para Array teclado.\n";
   cout << "--- ingrese opcion 3 para Array texto.\n";
   int mode;
   cin >>mode;
   if (mode==1){
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";
// Iniciar el contador de tiempo
    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";
// Detener el contador de tiempo
    auto stop = high_resolution_clock::now();
//calcular la duracion
    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);
//imprimir el tiempo.
    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
   }
      else{
   if(mode==2){
    cout << "--- Bienvenido en esta opción llenamos el array por teclado.\n";
    int size;
// Solicitar el tamaño del array
    cout << "--- Ingrese el tamaño del Array:\n";
    cin >> size;
// Crear un array del tamaño especificado
    int data[size];
// Solicitar los elementos del array
    cout << "--- Ingrese los números del array:\n";
   for (int i = 0; i < size; i++) {
    cin >> data[i];
   }
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";
// Iniciar el contador de tiempo
    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";
// Detener el contador de tiempo
    auto stop = high_resolution_clock::now();
//calcular la duracion
    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);
//imprimir el tiempo.
    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
   }
      else{
   if(mode==3){
    cout << "--- Bienvenido en esta opción llenamos el array por documento.\n";
// Abrir el archivo de entrada
    ifstream inputFile("array.txt");
//if para ver si el archivo esta abriendo.
     if (!inputFile.is_open()) {
    cout << "--- Error: No se pudo abrir el archivo.\n"<< endl;
// Salir del programa si no se puede abrir el archivo
    ;
     }
    int size;
// Leer el tamaño del array desde el archivo.
    inputFile >> size;
// Crear un array del tamaño especificado.
    int data[size];
// Lee los elementos del array.
     for (int i = 0; i < size; i++) {
    inputFile >> data[i];
     }
//cerrar el archivo
    inputFile.close();
    cout << "--- El Array original fue: \n";   
    printArray(data, size);
    cout << "--- El ordenamiento que se realiza es:\n";
// Iniciar el contador de tiempo
    auto start = high_resolution_clock::now();
    selectionSort(data, size);
    cout << "--- El Array ordenado es:\n";
// Detener el contador de tiempo
    auto stop = high_resolution_clock::now();
//calcular la duracion
    auto duration = duration_cast<microseconds>(stop - start);
    printArray(data, size);
//imprimir el tiempo.
    cout << "--- El tiempo que demoro hacer el proceso es: "<< duration.count() << " microseconds" << endl;
    }
      else{
    cout << "--- fuera de rango.\n";
    selection_sort();
         }
      }
      }
}
