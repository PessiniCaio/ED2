#include <stdio.h>
#include <stdlib.h>

#define MAX 2500

// Função de busca binária tradicional
int busca_binaria_tradicional(int vetor[], int tamanho, int chave) {
    int esquerda = 0, direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == chave) {
            return meio;  // Retorna o índice encontrado
        } else if (vetor[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;  // Elemento não encontrado
}

// Função de busca binária recursiva
int busca_binaria_recursiva(int vetor[], int esquerda, int direita, int chave) {
    if (esquerda > direita) {
        return -1;
    }
    int meio = (esquerda + direita) / 2;
    if (vetor[meio] == chave) {
        return meio;
    } else if (vetor[meio] < chave) {
        return busca_binaria_recursiva(vetor, meio + 1, direita, chave);
    } else {
        return busca_binaria_recursiva(vetor, esquerda, meio - 1, chave);
    }
}

int main() {
    int vetor[MAX];
    int tamanho = 0, chave;

    // Abrindo o arquivo TXT para leitura dos dados
    FILE *arquivo = fopen("C:\\Users\\Pichau\\Desktop\\Envio_att_ED2\\Entrada_busca_binaria.txt", "r");
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

    // Busca tradicional
    int resultado_tradicional = busca_binaria_tradicional(vetor, tamanho, chave);
    if (resultado_tradicional != -1) {
        printf("Elemento encontrado na posicao %d (tradicional).\n", resultado_tradicional);
    } else {
        printf("Elemento nao encontrado (tradicional).\n");
    }

    // Busca recursiva
    int resultado_recursivo = busca_binaria_recursiva(vetor, 0, tamanho - 1, chave);
    if (resultado_recursivo != -1) {
        printf("Elemento encontrado na posicao %d (recursiva).\n", resultado_recursivo);
    } else {
        printf("Elemento nao encontrado (recursiva).\n");
    }

    return 0;
}

