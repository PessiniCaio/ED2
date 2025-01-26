#include "BolhaCParada.h"
#include <stdio.h>
#include <time.h>

// Variáveis globais para rastrear comparações, trocas e tempo
double bCPT;
long long int bCPComp;
long long int bCPSwaps;

// Função para realizar a ordenação por bolha com parada
void ordenaBolhaComParada(int *dados, int tamanho) {
    printf("Executando bolha com parada\n");
    int mudou = 1;
    int n = tamanho - 1;
    int j, aux;
    bCPComp = 0;
    bCPSwaps = 0;

    clock_t start, end;
    start = clock();

    while (mudou) {
        mudou = 0;
        for (j = 0; j < n; j++) {
            bCPComp++;
            if (dados[j] > dados[j + 1]) {
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
                bCPSwaps++;
                mudou = 1;
            }
        }
        n--;
    }

    end = clock();
    bCPT = ((double)(end - start)) / CLOCKS_PER_SEC;

}
