#include <stdio.h>
#include <time.h>
#include "Heapsort.h"

double hST;
int hSComp;
int hSSwaps;

void heapify(int *array, int tamanho, int i, int *hSComp, int *hSSwaps) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < tamanho) {
        (*hSComp)++;
        if (array[l] > array[largest]) {
            largest = l;
        }
    }

    if (r < tamanho) {
        (*hSComp)++;
        if (array[r] > array[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        (*hSSwaps)++;

        heapify(array, tamanho, largest, hSComp, hSSwaps);
    }
}

void heapSort(int *array, int tamanho) {

    hSComp = 0;
    hSSwaps = 0;

    clock_t start, end;
    start = clock();


    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(array, tamanho, i, &hSComp, &hSSwaps);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0, &hSComp, &hSSwaps);
    }

    end = clock();
    hST = ((double)(end - start)) / CLOCKS_PER_SEC;

}