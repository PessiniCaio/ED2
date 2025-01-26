#include "QuickSortMediana.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

long long int qSMComp;
long long int qSMSwaps;
double qSMT;

void quicksortMediana(int *array, int low, int high) {
    if (low < high) {
        qSMComp++;
        int mid = low + (high - low) / 2;
        int a = array[low], b = array[mid], c = array[high];
        int pivotIndex = (a < b) ? ((b < c) ? mid : ((a < c) ? high : low)) 
                                 : ((a < c) ? low : ((b < c) ? high : mid));
        int pivot = array[pivotIndex];

        qSMSwaps++;
        int temp = array[low];
        array[low] = array[pivotIndex];
        array[pivotIndex] = temp;

        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && array[i] <= pivot) {
                qSMComp++;
                i++;
            }
            while (array[j] > pivot) {
                qSMComp++;
                j--;
            }
            if (i < j) {
                qSMSwaps++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        qSMSwaps++;
        array[low] = array[j];
        array[j] = pivot;

        quicksortMediana(array, low, j - 1);
        quicksortMediana(array, j + 1, high);
    }
}

void quicksortMedianaWrapper(int *array, int tamanho) {

    printf("Executando quicksortMediana\n");

    qSMComp = 0;
    qSMSwaps = 0;


    clock_t start = clock();
    quicksortMediana(array, 0, tamanho - 1);
    clock_t end = clock();

    qSMT = ((double)(end - start)) / CLOCKS_PER_SEC;
}
