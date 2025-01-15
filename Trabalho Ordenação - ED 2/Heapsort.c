#include <stdio.h>
#include <time.h>
#include "Heapsort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double hST;
long long int hSComp;
long long int hSSwaps;

// Função para ajustar o heap para manter a propriedade de heap
void heapify(int *array, int tamanho, int i, long long int *hSComp, long long int *hSSwaps) {
    int largest = i;
    int l = 2 * i + 1;          // Índice do filho à esquerda
    int r = 2 * i + 2;          // Índice do filho à direita

    if (l < tamanho) {
        (*hSComp)++;
        if (array[l] > array[largest]) {
            largest = l;
        }
    }


    if (r < tamanho) {
        (*hSComp)++;
        if (array[r] > array[largest]) {
            largest = r;
        }
    }

    // Se o maior não for o nó atual, troca os elementos e continua a ajustar
    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        (*hSSwaps)++;

        // Recursivamente ajusta a subárvore afetada
        heapify(array, tamanho, largest, hSComp, hSSwaps);
    }
}

// Função principal para realizar a ordenação por heap 
void heapSort(int *array, int tamanho) {

    hSComp = 0;
    hSSwaps = 0;

    clock_t start, end;
    start = clock();


    // Constrói o heap maximizador (heapify em todos os nós não-folha)
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(array, tamanho, i, &hSComp, &hSSwaps);
    }

    // Extrai elementos do heap um por um
    for (int i = tamanho - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0, &hSComp, &hSSwaps);
    }

    end = clock();
    hST = ((double)(end - start)) / CLOCKS_PER_SEC;

}