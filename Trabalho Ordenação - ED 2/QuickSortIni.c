#include "QuickSortIni.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long int qSIComp;
long long int qSISwaps;
double qSIT;

int particionar(int *array, int low, int high, long long int *num_comparacoes, long long int *num_trocas) {
    int pivot = array[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        (*num_comparacoes)++;
        if (array[j] < pivot) {
            i++;
            (*num_trocas)++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    (*num_trocas)++;
    int temp = array[i];
    array[i] = array[low];
    array[low] = temp;

    return i;
}

void quicksortIni(int *array, int low, int high, long long int *num_comparacoes, long long int *num_trocas) {
    if (low < high) {
        int pivotIndex = particionar(array, low, high, num_comparacoes, num_trocas);
        quicksortIni(array, low, pivotIndex - 1, num_comparacoes, num_trocas);
        quicksortIni(array, pivotIndex + 1, high, num_comparacoes, num_trocas);
    }
}

void quicksortIniWrapper(int *array, int tamanho) {


    qSIComp = 0;
    qSISwaps = 0;
    
    clock_t start = clock();
    quicksortIni(array, 0, tamanho - 1, &qSIComp, &qSISwaps);
    clock_t end = clock();

    qSIT = ((double)(end - start)) / CLOCKS_PER_SEC;
}
