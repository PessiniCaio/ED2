#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_TEXTO 1000
#define TAMANHO_MAX_PADRAO 100

// Função de busca por força bruta
int busca_forca_bruta(const char texto[], const char padrao[]) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int comparacoes = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
            comparacoes++;
        }
        if (j == m) {
            printf("Padrao encontrado no indice %d\n", i);
            return comparacoes;
        }
    }

    printf("Padrao nao encontrado.\n");
    return comparacoes;
}

int main() {
    char texto[TAMANHO_MAX_TEXTO];
    char padrao[TAMANHO_MAX_PADRAO] = "padrao_para_buscar";
    
    // Abrindo o arquivo CSV
    FILE *arquivo = fopen("texto_carac_1000.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lendo o conteúdo do arquivo CSV
    if (fgets(texto, TAMANHO_MAX_TEXTO, arquivo) == NULL) {
        printf("Erro ao ler o conteudo do arquivo.\n");
        fclose(arquivo);
        return 1;
    }

    fclose(arquivo);

    int comparacoes = busca_forca_bruta(texto, padrao);
    printf("Total de comparacoes: %d\n", comparacoes);

    return 0;
}
