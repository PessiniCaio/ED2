#ifndef RADIXSORT_H
#define RADIXSORT_H


extern double rST;
extern int rSComp;
extern int rSSwaps;
int getMax(int *array, int tamanho);
void countingSort(int *array, int tamanho, int place, int *rSComp, int *rSSwaps);
void radixSort(int *array, int tamanho);

#endif