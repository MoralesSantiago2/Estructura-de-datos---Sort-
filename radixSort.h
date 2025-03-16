#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iostream>
#include <chrono> 
#include <fstream>

void radixSort(int array[], int size);
int getMax(int array[], int size);
void countingSort(int array[], int size, int place);
int callRadix();
#endif