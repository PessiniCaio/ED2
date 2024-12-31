#include <stdio.h>
#include <time.h>
#include "Insertionsort.h"

double iST;
int iSComp;
int iSSwaps;

void insertionSort(int *array, int tamanho) {

    iSComp = 0;
    iSSwaps = 0;

    clock_t start, end;
    start = clock();


    for (int i = 1; i < tamanho; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            iSComp++;
            array[j + 1] = array[j];
            j = j - 1;
            iSSwaps++;
        }
        iSComp++;
        array[j + 1] = key;
    }

    end = clock();
    iST = ((double)(end - start)) / CLOCKS_PER_SEC;

}
