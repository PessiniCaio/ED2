#ifndef HEAPSORT_H
#define HEAPSORT_H

extern double hST;
extern int hSComp;
extern int hSSwaps;
void heapify(int *array, int tamanho, int i, int *hSComp, int *hSSwaps);
void heapSort(int *array, int tamanho);

#endif