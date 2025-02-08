#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bucketsort.h"
#include "BolhaCParada.h"
#define NUMERO_BALDES 10

// Variáveis globais para rastrear comparações, trocas e tempo
double bSTE;
long long int bSComp;
long long int bSSwaps;

typedef struct {
    int balde[10];
    int topo;
} Balde;

void bucketSort(int* V, int tamanho) {
    clock_t start, end;
    start = clock();

    int maior = 0;
    for (int i = 0; i < tamanho; i++) {
        bSComp++;
        if (V[i] > maior) {
            maior = V[i];
        }
    }

    int numeroBaldes = (maior / 10) + 1;
    Balde baldes[numeroBaldes];

    for (int i = 0; i < numeroBaldes; i++) {
        baldes[i].topo = 0;
    }

    for (int i = 0; i < tamanho; i++) {
        bSComp++;
        int idx = V[i] / (maior / numeroBaldes + 1);
        
        if (baldes[idx].topo < 10) {
            baldes[idx].balde[baldes[idx].topo++] = V[i];
        }
    }

    for (int i = 0; i < numeroBaldes; i++) {
        if (baldes[i].topo > 0) {
            ordenaBolhaComParada(baldes[i].balde, baldes[i].topo);
            bSComp += bCPComp;
            bSSwaps += bCPSwaps;
        }
    }

    for (int i = 0, j = 0; j < numeroBaldes; j++) {
        for (int k = 0; k < baldes[j].topo; k++) {
            bSSwaps++;
            V[i++] = baldes[j].balde[k];
        }
    }

    end = clock();
    bSTE = ((double)(end - start)) / CLOCKS_PER_SEC;
}

