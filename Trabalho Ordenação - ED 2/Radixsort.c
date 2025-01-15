#include <stdio.h>
#include <time.h>
#include "Radixsort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double rST;
long long int rSComp;
long long int rSSwaps;

// Função para encontrar o maior elemento no vetor
int getMax(int *array, int tamanho) {
    int max = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função Counting Sort para um dígito específico
void countingSort(int *array, int tamanho, int place, long long int *rSComp, long long int *rSSwaps) {
    int output[tamanho];    // Vetor para armazenar os resultados ordenados
    int count[10] = {0};    // Contador para armazenar a frequência dos dígitos

    // Conta a ocorrência de cada dígito no lugar atual (unidade, dezena, etc.)
    for (int i = 0; i < tamanho; i++) {
        int index = (array[i] / place) % 10;    // Obtém o dígito no lugar atual
        count[index]++;
    }

    // Calcula os índices acumulados para os dígitos
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o vetor de saída
    for (int i = tamanho - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
        (*rSSwaps)++;
    }

    // Copia os elementos do vetor de saída de volta para o array original
    for (int i = 0; i < tamanho; i++) {
        array[i] = output[i];
        (*rSComp)++;
    }
}

// Função principal para realizar a ordenação por radix 
void radixSort(int *array, int tamanho) {

    rSComp = 0;
    rSSwaps = 0;

    clock_t start, end;
    start = clock();

    int maxElement = getMax(array, tamanho);

    // Aplica Counting Sort para cada dígito (unidade, dezena, centena, etc.)
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSort(array, tamanho, place, &rSComp, &rSSwaps);
    }

    end = clock();
    rST = ((double)(end - start)) / CLOCKS_PER_SEC;

}
