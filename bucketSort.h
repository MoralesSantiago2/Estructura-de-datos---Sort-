#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
void bucketSort(int arr[], int n);
struct Node *insertionSort(struct Node *list);
void printBuckets(struct Node *list);
int getBucketIndex(int value);
int callBucket();

#endif