#include "Shellsort.h"
#include <time.h>
#include <stdio.h>

double sST;
int sSComp;
int sSSwaps;

void shellSort(int *dados, int tamanho) {

    sSComp = 0;
    sSSwaps = 0;

    clock_t start, end;
    start = clock();

    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            int temp = dados[i];
            int j;
            for (j = i; j >= gap && dados[j - gap] > temp; j -= gap) {
                dados[j] = dados[j - gap];
                sSComp++;
                sSSwaps++;

            }
            dados[j] = temp;
            sSSwaps++;
        }
    }

    end = clock();
    sST = ((double)(end - start)) / CLOCKS_PER_SEC;
}