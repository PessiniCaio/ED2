#include <stdio.h>
#include <time.h>
#include "Quicksort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double qST;
int qSComp;
int qSSwaps;

// Função para realizar a troca entre dois elementos no vetor
void swapQuick(int *a, int *b, int *qSSwaps) {
    int t = *a;
    *a = *b;
    *b = t;
    (*qSSwaps)++;
}

// Função para particionar o vetor em torno de um pivô
int partition(int *array, int low, int high, int *qSComp, int *qSSwaps) {
    int pivot = array[high];    // Escolhe o último elemento como pivô
    int i = (low - 1);          // Índice do menor elemento

    // Loop para organizar os elementos em torno do pivô
    for (int j = low; j < high; j++) {
        (*qSComp)++;
        if (array[j] <= pivot) {
            i++;
            swapQuick(&array[i], &array[j], qSSwaps);
        }
    }

    swapQuick(&array[i + 1], &array[high], qSSwaps);
    return (i + 1);
}

// Função auxiliar recursiva para dividir e conquistar
void quickSortHelper(int *array, int low, int high, int *qSComp, int *qSSwaps) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(array, low, high, qSComp, qSSwaps);

        // Ordena os elementos antes e depois do pivô
        quickSortHelper(array, low, pi - 1, qSComp, qSSwaps);
        quickSortHelper(array, pi + 1, high, qSComp, qSSwaps);
    }
}

// Função principal para realizar a ordenação por quick 
void quickSort(int *array, int tamanho) {

    qSComp = 0;
    qSSwaps = 0;

    clock_t start, end;
    start = clock();

    quickSortHelper(array, 0, tamanho - 1, &qSComp, &qSSwaps);

    end = clock();
    qST = ((double)(end - start)) / CLOCKS_PER_SEC;
}
