#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função recursiva para a busca binária
int busca_binaria(int *arr, int esquerda, int direita, int chave) {
    if (esquerda > direita) {
        return -1;  // Não encontrado
    }

    int meio = (esquerda + direita) / 2;
    if (arr[meio] == chave) {
        return meio;  // Elemento encontrado
    } else if (arr[meio] > chave) {
        return busca_binaria(arr, esquerda, meio - 1, chave);
    } else {
        return busca_binaria(arr, meio + 1, direita, chave);
    }
}

// Função para carregar os dados do CSV
int* carregar_arquivo(char *nome_arquivo, int *tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int *dados = (int *)malloc(100 * sizeof(int));
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
    printf("Digite a chave para busca binária: ");
    scanf("%d", &chave);

    int indice = busca_binaria(dados, 0, tamanho - 1, chave);
    if (indice != -1) {
        printf("Chave %d encontrada no índice %d.\n", chave, indice);
    } else {
        printf("Chave %d não encontrada.\n", chave);
    }

    free(dados);
    return 0;
}
