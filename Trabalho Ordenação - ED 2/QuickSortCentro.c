#include "QuickSortCentro.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

long long int qSCComp;
long long int qSCSwaps;
double qSCT;

void quicksortCentro(int *array, int low, int high) {
    if (low < high) {
        qSCComp++;
        int mid = low + (high - low) / 2; 
        int pivot = array[mid];
        qSCSwaps++;
        int temp = array[low];
        array[low] = array[mid];
        array[mid] = temp;

        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && array[i] <= pivot) {
                qSCComp++;
                i++;
            }
            while (array[j] > pivot) {
                qSCComp++;
                j--;
            }
            if (i < j) {
                qSCSwaps++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        qSCSwaps++;
        array[low] = array[j];
        array[j] = pivot;

        quicksortCentro(array, low, j - 1);
        quicksortCentro(array, j + 1, high);
    }
}

void quicksortCentroWrapper(int *array, int tamanho) {

    qSCComp = 0;
    qSCSwaps = 0;

    clock_t start = clock();
    quicksortCentro(array, 0, tamanho - 1);
    clock_t end = clock();

    qSCT = ((double)(end - start)) / CLOCKS_PER_SEC;
    
}
