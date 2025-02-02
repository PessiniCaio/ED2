#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bucketsort.h"

// Variáveis globais para rastrear comparações, trocas e tempo
double bSTE;
long long int bSComp;
long long int bSSwaps;

// Estrutura de um nó usado para listas encadeadas nos buckets
struct Node {
    int data;
    struct Node *next;
};

// Protótipos das funções auxiliares
struct Node *InsertionSort(struct Node *list, long long int *bSComp, long long int *bSSwaps);
int getBucketIndex(int value, int interval);

// Função principal para realizar a ordenação por bucket 
void bucketSort(int *array, int tamanho) {
    printf("Executando bucket sort\n");
    if (tamanho <= 0) return;

    int i, j;
    int interval = 10; 
    int nBuckets = tamanho / 2;
    if (nBuckets <= 0) nBuckets = 1; 
    bSComp = 0;
    bSSwaps = 0;

    clock_t start, end;
    start = clock();

    // Alocando estaticamente os buckets
    struct Node *buckets[nBuckets];
    for (i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }

    struct Node nodes[tamanho];
    int nodeIndex = 0;

    // Distribui os elementos do vetor nos buckets correspondentes
    for (i = 0; i < tamanho; ++i) {
        int pos = getBucketIndex(array[i], interval);
        if (pos >= nBuckets) {
            pos = nBuckets - 1;
        }

        // Usa o próximo nó disponível no vetor
        struct Node *current = &nodes[nodeIndex++];
        current->data = array[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    // Ordena cada bucket usando Insertion Sort
    for (i = 0; i < nBuckets; ++i) {
        buckets[i] = InsertionSort(buckets[i], &bSComp, &bSSwaps);
    }

    // Reune os elementos ordenados de todos os buckets no vetor original
    for (j = 0, i = 0; i < nBuckets; ++i) {
        struct Node *node = buckets[i];
        while (node) {
            array[j++] = node->data;
            node = node->next;
        }
    }

    end = clock();
    bSTE = ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Função para ordenar uma lista encadeada usando ordenação por inserção direta (Insertion Sort)
struct Node *InsertionSort(struct Node *list, long long int *bSComp, long long int *bSSwaps) {
    if (!list || !list->next) return list;

    struct Node *sorted = NULL;
    struct Node *current = list;

    // Itera sobre os nós da lista
    while (current) {
        struct Node *next = current->next;
        if (!sorted || sorted->data >= current->data) {
            (*bSComp)++;
            current->next = sorted;
            sorted = current;
            (*bSSwaps)++;
        } else {
            struct Node *temp = sorted;
            // Encontra a posição correta para inserir o nó
            while (temp->next && temp->next->data < current->data) {
                (*bSComp)++;
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
            (*bSSwaps)++;
        }
        current = next;
    }

    return sorted;
}

// Função para calcular o índice do bucket de um valor
int getBucketIndex(int value, int interval) {
    return value / interval;
}
