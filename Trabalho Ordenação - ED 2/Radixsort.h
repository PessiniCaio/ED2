#ifndef RADIXSORT_H
#define RADIXSORT_H

extern double rST;
extern long long int rSComp;
extern long long int rSSwaps;
int getMax(int *array, int tamanho);
void countingSort(int *array, int tamanho, int place, long long int *rSComp, long long int *rSSwaps);
void radixSort(int *array, int tamanho);

#endif