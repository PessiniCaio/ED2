#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para a busca sequencial
int busca_sequencial(int *arr, int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave) {
            return i;  // Retorna o índice do elemento encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrado
}

// Função para carregar os dados do CSV
int* carregar_arquivo(char *nome_arquivo, int *tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int *dados = (int *)malloc(100 * sizeof(int));  // Alocação inicial
    *tamanho = 0;
    while (fscanf(arquivo, "%d,", &dados[*tamanho]) != EOF) {
        (*tamanho)++;
    }

    fclose(arquivo);
    return dados;
}

int main() {
    int tamanho;
    int *dados = carregar_arquivo("Entrada_busca.csv", &tamanho);

    int chave;
    printf("Digite a chave para busca sequencial: ");
    scanf("%d", &chave);

    int indice = busca_sequencial(dados, tamanho, chave);
    if (indice != -1) {
        printf("Chave %d encontrada no índice %d.\n", chave, indice);
    } else {
        printf("Chave %d não encontrada.\n", chave);
    }

    free(dados);
    return 0;
}
