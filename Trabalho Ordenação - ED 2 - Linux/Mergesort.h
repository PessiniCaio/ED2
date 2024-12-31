#ifndef MERGESORT_H
#define MERGESORT_H


extern double mST;
extern int mSComp;
extern int mSSwaps;

void merge(int *array, int left, int mid, int right, int *mSComp, int *mSSwaps);
void mergeSortHelper(int *array, int left, int right, int *mSComp, int *mSSwaps);
void mergeSort(int *array, int tamanho);

#endif