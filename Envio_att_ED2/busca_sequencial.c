#include <stdio.h>
#include <stdlib.h>

#define MAX 2500

// Função para realizar a busca sequencial
void busca_sequencial(int vetor[], int tamanho, int chave) {
    int contador = 0;
    printf("Indices onde a chave %d foi encontrada: ", chave);
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == chave) {
            printf("%d ", i);
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhum elemento encontrado.");
    } else {
        printf("\nNumero total de ocorrencias: %d\n", contador);
    }
}

int main() {
    int vetor[MAX];
    int tamanho = 0, chave;

    
    // Abrindo o arquivo TXT para leitura dos dados
    // Tive que passar o diretório direto pois o programa não estava reconhecendo o diretório do arquivo em .txt
    FILE *arquivo = fopen("C:\\Users\\Pichau\\Desktop\\Envio_att_ED2\\Entrada_busca_sequencial.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
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