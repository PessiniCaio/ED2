#ifndef MERGESORT_H
#define MERGESORT_H

extern double mST;
extern long long int mSComp;
extern long long int mSSwaps;

void merge(int *array, int left, int mid, int right, long long int *mSComp, long long int *mSSwaps);
void mergeSortHelper(int *array, int left, int right, long long int *mSComp, long long int *mSSwaps);
void mergeSort(int *array, int tamanho);

#endif