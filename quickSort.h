#ifndef QUICKSORT_H
#define QUICKSORT_H


#include <iostream>
#include <iomanip> // Para mostrar el tiempo en notaci—n cient’fica
#include <ctime> 

int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void quicksortIterativo(int arr[], int low, int high);
int callQuick();

#endif