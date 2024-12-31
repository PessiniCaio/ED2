#include <stdio.h>
#include <time.h>
#include "Mergesort.h"

double mST;
int mSComp;
int mSSwaps;

void merge(int *array, int left, int mid, int right, int *mSComp, int *mSSwaps) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        (*mSComp)++;
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        (*mSSwaps)++;
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        (*mSSwaps)++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        (*mSSwaps)++;
    }
}

void mergeSortHelper(int *array, int left, int right, int *mSComp, int *mSSwaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortHelper(array, left, mid, mSComp, mSSwaps);
        mergeSortHelper(array, mid + 1, right, mSComp, mSSwaps);

        merge(array, left, mid, right, mSComp, mSSwaps);
    }
}

void mergeSort(int *array, int tamanho) {

    mSComp = 0;
    mSSwaps = 0;

    clock_t start, end;
    start = clock();

    mergeSortHelper(array, 0, tamanho - 1, &mSComp, &mSSwaps);

    end = clock();
    mST = ((double)(end - start)) / CLOCKS_PER_SEC;
}
