#include <stdio.h>
#include <time.h>
#include "Selectionsort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double sSTE;
long long int sSCompE;
long long int sSSwapsE;

// Função para realizar a troca entre dois elementos no vetor
void swapSelection(int *a, int *b, long long int *sSSwaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*sSSwaps)++;
}

// Função principal para realizar a ordenação por seleção 
void selectionSort(int *array, int tamanho) {

    sSCompE = 0;
    sSSwapsE = 0;

    clock_t start, end;
    start = clock();

    for (int step = 0; step < tamanho - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < tamanho; i++) {
            sSCompE++;
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        if (min_idx != step) {
            swapSelection(&array[min_idx], &array[step], &sSSwapsE);
        }
    }

    end = clock();

    sSTE = ((double)(end - start)) / CLOCKS_PER_SEC;
}
