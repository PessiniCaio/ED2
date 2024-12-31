#include <stdio.h>
#include <time.h>
#include "Radixsort.h"

double rST;
int rSComp;
int rSSwaps;

int getMax(int *array, int tamanho) {
    int max = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void countingSort(int *array, int tamanho, int place, int *rSComp, int *rSSwaps) {
    int output[tamanho];
    int count[10] = {0};

    for (int i = 0; i < tamanho; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
        (*rSSwaps)++;
    }

    for (int i = 0; i < tamanho; i++) {
        array[i] = output[i];
        (*rSComp)++;
    }
}

void radixSort(int *array, int tamanho) {

    rSComp = 0;
    rSSwaps = 0;

    clock_t start, end;
    start = clock();

    int maxElement = getMax(array, tamanho);

    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSort(array, tamanho, place, &rSComp, &rSSwaps);
    }

    end = clock();
    rST = ((double)(end - start)) / CLOCKS_PER_SEC;

}
