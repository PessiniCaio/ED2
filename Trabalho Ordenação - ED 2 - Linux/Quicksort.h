#ifndef QUICKSORT_H
#define QUICKSORT_H

extern double qST;
extern int qSComp;
extern int qSSwaps;
void swapQuick(int *a, int *b, int *qSSwaps);
int partition(int *array, int low, int high, int *qSComp, int *qSSwaps);
void quickSortHelper(int *array, int low, int high, int *qSComp, int *qSSwaps);
void quickSort(int *array, int tamanho);

#endif