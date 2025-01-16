#include "Utils.h"

// Função de comparação para ser usada com qsort
int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Função para ler um arquivo contendo dados e armazená-los em um vetor
int *ler_arquivo(const char *caminho, int *tamanho)
{
    FILE *file = fopen(caminho, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo %s\n", caminho);
        exit(1);
    }

    *tamanho = 0;

    // Contar o número de linhas no arquivo para determinar o tamanho
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        (*tamanho)++;
    }

    // Verificar se o tamanho é válido
    if (*tamanho <= 0) {
        printf("Erro: Tamanho invalido (%d) no arquivo %s\n", *tamanho, caminho);
        fclose(file);
        return NULL;
    }

    // Alocar memória para os dados
    int *dados = malloc((*tamanho) * sizeof(int));
    if (!dados) {
        printf("Erro ao alocar memoria.\n");
        fclose(file);
        return NULL;
    }

    // Retornar ao início do arquivo para ler os números
    rewind(file);
    for (int i = 0; i < *tamanho; i++) {
        if (fscanf(file, "%d", &dados[i]) != 1) {
            printf("Erro ao ler os dados no arquivo %s\n", caminho);
            free(dados);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return dados;
}

// Função para salvar os resultados de um algoritmo de ordenação em um arquivo
void salvar_saida(const char *caminho, int *dados, int tamanho, const char *algoritmo, long long int comparacoes, long long int trocas, double tempo)
{
    FILE *file = fopen("saida.txt", "a");
    if (!file)
    {
        printf("Erro ao criar o arquivo %s\n", caminho);
        exit(1);
    }

    // Escreve as informações do algoritmo no arquivo
    fprintf(file, "Algoritmo: %s\n", algoritmo);
    fprintf(file, "Comparacoes: %I64d\n", comparacoes);
    fprintf(file, "Trocas: %I64d\n", trocas);
    fprintf(file, "Tempo: %.14f segundos\n", tempo);
    fprintf(file, "Dados ordenados:\n");

    // Escreve os dados ordenados no arquivo
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(file, "%d\n", dados[i]);
    }

    fprintf(file, "\n");
    fclose(file);
}

// Função para salvar os resultados de todos os algoritmos em um único arquivo
void salvar_saida_todos(const char *caminho, int *dados, int tamanho, const char **algoritmos, long long int comparacoes[], long long int trocas[], double tempos[], int n)
{
    FILE *file = fopen("saida.txt", "w");
    if (!file)
    {
        printf("Erro ao criar o arquivo %s\n", caminho);
        exit(1);
    }

    // Aloca memória para armazenar os dados ordenados
    int *dados_ordenados = malloc(tamanho * sizeof(int));
    if (!dados_ordenados)
    {
        perror("Erro ao alocar memoria");
        fclose(file);
        return;
    }

    // Copia os dados originais para o vetor de dados ordenados
    memcpy(dados_ordenados, dados, tamanho * sizeof(int));
    qsort(dados_ordenados, tamanho, sizeof(int), comparar);

    // Escreve os resultados de todos os algoritmos no arquivo
    fprintf(file, "Resultados de todos os algoritmos:\n\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "Algoritmo: %s\n", algoritmos[i]);
        fprintf(file, "Comparacoes: %I64d\n", comparacoes[i]);
        fprintf(file, "Trocas: %I64d\n", trocas[i]);
        fprintf(file, "Tempo: %.14f segundos\n\n", tempos[i]);
    }

    // Escreve os dados ordenados no arquivo
    fprintf(file, "Dados ordenados:\n");
    for (int j = 0; j < tamanho; j++)
    {
        fprintf(file, "%d\n", dados_ordenados[j]);
    }

    free(dados_ordenados);
    fclose(file);
}