#ifndef HEAPSORT_H
#define HEAPSORT_H

extern double hST;
extern long long int hSComp;
extern long long int hSSwaps;
void heapify(int *array, int tamanho, int i, long long int *hSComp, long long int *hSSwaps);
void heapSort(int *array, int tamanho);

#endif