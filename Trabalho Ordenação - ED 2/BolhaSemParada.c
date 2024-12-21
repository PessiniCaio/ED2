#include "BolhaSemParada.h"

void ordenaBolhaSemParada(int *dados, int tamanho) {
    int i, j, aux;
    for (i = tamanho - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            if (dados[j] > dados[j + 1]) {
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
            }
        }
    }
}