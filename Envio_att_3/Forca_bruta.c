#include <stdio.h>
#include <string.h>

#define TAMANHO_MAX_TEXTO 1000  // Defina o tamanho máximo do texto baseado no arquivo CSV
#define TAMANHO_MAX_PADRAO 100  // Ajuste se necessário

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
            printf("Padrão encontrado no índice %d\n", i);
            return comparacoes;
        }
    }

    printf("Padrão não encontrado.\n");
    return comparacoes;
}

int main() {
    char texto[TAMANHO_MAX_TEXTO] = "Seu texto estático do CSV aqui";  // Popule com o conteúdo do CSV
    char padrao[TAMANHO_MAX_PADRAO] = "padrao_para_buscar";

    int comparacoes = busca_forca_bruta(texto, padrao);
    printf("Total de comparações: %d\n", comparacoes);
    return 0;
}
