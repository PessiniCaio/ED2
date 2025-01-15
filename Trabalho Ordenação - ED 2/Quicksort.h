#ifndef QUICKSORT_H
#define QUICKSORT_H

extern double qST;
extern long long int qSComp;
extern long long int qSSwaps;
void swapQuick(int *a, int *b, long long int *qSSwaps);
int partition(int *array, int low, int high, long long int *qSComp, long long int *qSSwaps);
void quickSortHelper(int *array, int low, int high, long long int *qSComp, long long int *qSSwaps);
void quickSort(int *array, int tamanho);

#endif