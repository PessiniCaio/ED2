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
            int j;
            
            // Move elementos maiores que `temp` para frente no intervalo do "gap"
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