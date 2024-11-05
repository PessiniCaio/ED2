#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o prefixo do KMP
void calcula_prefixo_kmp(const char padrao[], int m, int prefixo[]) {
    int comprimento = 0;
    prefixo[0] = 0;

    for (int i = 1; i < m; i++) {
        while (comprimento > 0 && padrao[i] != padrao[comprimento]) {
            comprimento = prefixo[comprimento - 1];
        }
        if (padrao[i] == padrao[comprimento]) {
            comprimento++;
        }
        prefixo[i] = comprimento;
    }
}

// Função de busca KMP
int busca_kmp(const char texto[], const char padrao[]) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int prefixo[TAMANHO_MAX_PADRAO];
    int comparacoes = 0;

    calcula_prefixo_kmp(padrao, m, prefixo);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && texto[i] != padrao[j]) {
            j = prefixo[j - 1];
            comparacoes++;
        }
        if (texto[i] == padrao[j]) {
            j++;
        }
        if (j == m) {
            printf("Padrão encontrado no índice %d\n", i - m + 1);
            return comparacoes;
        }
    }

    printf("Padrão não encontrado.\n");
    return comparacoes;
}

int main() {
    char texto[TAMANHO_MAX_TEXTO] = "Seu texto estático do CSV aqui";
    char padrao[TAMANHO_MAX_PADRAO] = "padrao_para_buscar";

    int comparacoes = busca_kmp(texto, padrao);
    printf("Total de comparações: %d\n", comparacoes);
    return 0;
}
