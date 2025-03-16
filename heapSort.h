#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <fstream>
#include <chrono>

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
int callHeap();
#endif