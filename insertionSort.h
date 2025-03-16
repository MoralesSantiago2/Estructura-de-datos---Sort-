#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
#include <ctime>
#include <fstream>

void insertionSort(int array[], int size);
bool leerDesdeArchivo(int array[], int& size);
void leerDesdeTeclado(int array[], int& size);
int callInsertion();

#endif