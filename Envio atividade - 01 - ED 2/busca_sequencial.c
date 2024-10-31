#include <stdio.h>
#include <stdlib.h>

#define MAX 2500 // Definindo tamanho máximo do vetor

// Função para realizar a busca sequencial
void busca_sequencial(int vetor[], int tamanho, int chave) {
    int contador = 0;
    printf("Índices onde a chave %d foi encontrada: ", chave);
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == chave) {
            printf("%d ", i);
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhum elemento encontrado.");
    } else {
        printf("\nNúmero total de ocorrências: %d\n", contador);
    }
}

int main() {
    int vetor[MAX];
    int tamanho = 0, chave;

    // Abrindo o arquivo CSV para leitura dos dados
    FILE *arquivo = fopen("Entrada_busca_sequencial.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lendo os dados do arquivo para o vetor
    while (fscanf(arquivo, "%d", &vetor[tamanho]) != EOF && tamanho < MAX) {
        tamanho++;
    }
    fclose(arquivo);

    printf("Digite a chave a ser buscada: ");
    scanf("%d", &chave);

    // Realizando a busca sequencial
    busca_sequencial(vetor, tamanho, chave);

    return 0;
}
