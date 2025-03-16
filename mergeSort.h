#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <chrono> 
#include <fstream>


void merge(int array[], int left, int mid, int right);
void mergeSortHelper(int array[], int left, int right);
void mergeSort(int array[], int size);
void merge_sort();
int callMerge();


#endif