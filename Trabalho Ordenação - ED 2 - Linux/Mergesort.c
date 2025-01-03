#include <stdio.h>
#include <time.h>
#include "Mergesort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double mST;
int mSComp;
int mSSwaps;

// Função para mesclar (merge) duas sublistas ordenadas
void merge(int *array, int left, int mid, int right, int *mSComp, int *mSSwaps) {
    int i, j, k;
    int n1 = mid - left + 1;    // Tamanho da sublista esquerda
    int n2 = right - mid;       // Tamanho da sublista direita

    int L[n1], R[n2];   // Vetores temporários para as sublistas

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Índices iniciais das sublistas e do vetor principal
    i = 0;
    j = 0;
    k = left;

    // Mescla as duas sublistas em ordem
    while (i < n1 && j < n2) {
        (*mSComp)++;
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        (*mSSwaps)++;
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        (*mSSwaps)++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        (*mSSwaps)++;
    }
}

// Função recursiva para dividir o vetor e realizar a mescla das listas
void mergeSortHelper(int *array, int left, int right, int *mSComp, int *mSSwaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSortHelper(array, left, mid, mSComp, mSSwaps);

        // Ordena a metade direita
        mergeSortHelper(array, mid + 1, right, mSComp, mSSwaps);

        // Mescla as duas metades ordenadas
        merge(array, left, mid, right, mSComp, mSSwaps);
    }
}

// Função principal para realizar a ordenação por merge 
void mergeSort(int *array, int tamanho) {

    mSComp = 0;
    mSSwaps = 0;

    clock_t start, end;
    start = clock();

    mergeSortHelper(array, 0, tamanho - 1, &mSComp, &mSSwaps);

    end = clock();
    mST = ((double)(end - start)) / CLOCKS_PER_SEC;
}
