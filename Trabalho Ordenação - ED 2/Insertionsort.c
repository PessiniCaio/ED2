#include <stdio.h>
#include <time.h>
#include "Insertionsort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double iST;
long long int iSComp;
long long int iSSwaps;

// Função para realizar a ordenação por inserção direta
void insertionSort(int *array, int tamanho) {

    printf("Executando insercao direta\n");

    iSComp = 0;
    iSSwaps = 0;

    clock_t start, end;
    start = clock();


    // Percorre o vetor a partir do segundo elemento
    for (int i = 1; i < tamanho; i++) {
        int key = array[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição para a direita
        while (j >= 0) {
            iSComp++;
            if (array[j] > key) {
                array[j + 1] = array[j];
                j--;
                iSSwaps++;
            } else {
                break;
            }
        }

        if (j != i - 1) {
            array[j + 1] = key;
        }

    }

    end = clock();
    iST = ((double)(end - start)) / CLOCKS_PER_SEC;

}
