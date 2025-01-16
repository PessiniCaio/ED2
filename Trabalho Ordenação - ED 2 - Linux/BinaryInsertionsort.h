#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H

extern long long int bIComp;
extern long long int bISwaps;
extern double bIST;

int binarySearch(int a[], int item, int low, int high);
void binaryInsertionSort(int *array, int tamanho);

#endif