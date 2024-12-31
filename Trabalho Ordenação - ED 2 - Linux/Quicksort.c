#include <stdio.h>
#include <time.h>
#include "Quicksort.h"

double qST;
int qSComp;
int qSSwaps;

void swapQuick(int *a, int *b, int *qSSwaps) {
    int t = *a;
    *a = *b;
    *b = t;
    (*qSSwaps)++;
}

int partition(int *array, int low, int high, int *qSComp, int *qSSwaps) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        (*qSComp)++;
        if (array[j] <= pivot) {
            i++;
            swapQuick(&array[i], &array[j], qSSwaps);
        }
    }

    swapQuick(&array[i + 1], &array[high], qSSwaps);
    return (i + 1);
}

void quickSortHelper(int *array, int low, int high, int *qSComp, int *qSSwaps) {
    if (low < high) {
        int pi = partition(array, low, high, qSComp, qSSwaps);

        quickSortHelper(array, low, pi - 1, qSComp, qSSwaps);
        quickSortHelper(array, pi + 1, high, qSComp, qSSwaps);
    }
}

void quickSort(int *array, int tamanho) {

    qSComp = 0;
    qSSwaps = 0;

    clock_t start, end;
    start = clock();

    quickSortHelper(array, 0, tamanho - 1, &qSComp, &qSSwaps);

    end = clock();
    qST = ((double)(end - start)) / CLOCKS_PER_SEC;
}
