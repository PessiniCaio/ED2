#include "Shellsort.h"
#include <time.h>
#include <stdio.h>

// Variáveis globais para rastrear comparações, trocas e tempo
double sST;
long long int sSComp;
long long int sSSwaps;

// Função para realizar a ordenação por shell
void shellSort(int *dados, int tamanho) {

    sSComp = 0;
    sSSwaps = 0;

    clock_t start, end;
    start = clock();

    // Ajusta o intervalo (gap) entre os elementos a serem comparados no vetor
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        // Itera sobre os elementos no intervalo do "gap"
        for (int i = gap; i < tamanho; i++) {
            int temp = dados[i];
            int j = i - gap;

            while (j >= 0 && temp < dados[j]) {
                sSComp++;
                dados[j + gap] = dados[j];
                sSSwaps++;
                j -= gap;
            }

            if (j >= 0) {
                sSComp++;
            }
            dados[j + gap] = temp;
        }
    }

    end = clock();
    sST = ((double)(end - start)) / CLOCKS_PER_SEC;
}