#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bucketsort.h"

double bSTE;
int bSComp;
int bSSwaps;

struct Node {
    int data;
    struct Node *next;
};

struct Node *InsertionSort(struct Node *list, int *bSComp, int *bSSwaps);
int getBucketIndex(int value, int interval);

void bucketSort(int *array, int tamanho) {
    if (tamanho <= 0) return;

    int i, j;
    int interval = 10; // Definindo o intervalo para os buckets
    int nBuckets = tamanho / 2; // Número de buckets proporcional ao tamanho
    bSComp = 0;
    bSSwaps = 0;

    clock_t start, end;
    start = clock();

    struct Node **buckets = (struct Node **)malloc(sizeof(struct Node *) * nBuckets);

    for (i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }

    for (i = 0; i < tamanho; ++i) {
        int pos = getBucketIndex(array[i], interval);
        struct Node *current = (struct Node *)malloc(sizeof(struct Node));
        current->data = array[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    for (i = 0; i < nBuckets; ++i) {
        buckets[i] = InsertionSort(buckets[i], &bSComp, &bSSwaps);
    }

    for (j = 0, i = 0; i < nBuckets; ++i) {
        struct Node *node = buckets[i];
        while (node) {
            array[j++] = node->data;
            struct Node *temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(buckets);

    end = clock();
    bSTE = ((double)(end - start)) / CLOCKS_PER_SEC;
}

struct Node *InsertionSort(struct Node *list, int *bSComp, int *bSSwaps) {
    if (!list || !list->next) return list;

    struct Node *sorted = NULL;
    struct Node *current = list;

    while (current) {
        struct Node *next = current->next;
        if (!sorted || sorted->data >= current->data) {
            (*bSComp)++;
            current->next = sorted;
            sorted = current;
        } else {
            struct Node *temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                (*bSComp)++;
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        (*bSSwaps)++;
        current = next;
    }

    return sorted;
}

int getBucketIndex(int value, int interval) {
    return value / interval;
}
