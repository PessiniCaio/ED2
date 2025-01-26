#include "BolhaSemParada.h"
#include <stdio.h>
#include <time.h>

// Variáveis globais para rastrear comparações, trocas e tempo
double bSPT;
long long int bSPComp;
long long int bSPSwaps;

// Função para realizar a ordenação por bolha sem parada
void ordenaBolhaSemParada(int *dados, int tamanho) {
    printf("Executando bolha sem parada\n");
    int i, j, aux;
    bSPComp = 0;
    bSPSwaps = 0;

    clock_t start, end;
    start = clock();

    for (i = tamanho - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            bSPComp++;
            if (dados[j] > dados[j + 1]) {
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
                bSPSwaps++;
            }
        }
    }

    end = clock();
    bSPT = ((double)(end - start)) / CLOCKS_PER_SEC;

}