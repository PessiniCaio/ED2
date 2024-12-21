#include "BolhaCParada.h"

void ordenaBolhaComParada(int *dados, int tamanho) {
    int mudou = 1;
    int n = tamanho - 1;
    int j, aux;

    while (mudou) {
        mudou = 0;
        for (j = 0; j < n; j++) {
            if (dados[j] > dados[j + 1]) {
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
                mudou = 1;
            }
        }
        n--;
    }
}
