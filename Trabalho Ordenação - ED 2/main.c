
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BolhaCParada.h"
#include "BolhaSemParada.h"

#define PATH_MAX 260

void menu_principal();
void menu_ordem(int base_opcao);
void menu_ordenacao(const char *caminho);
int *ler_arquivo(const char *caminho, int *tamanho);

int main() {
    menu_principal();
    return 0;
}

void menu_principal() {
    int opcao;

    do {
        printf("Base de Dados\n");
        printf("Selecione uma das opcoes abaixo:\n");
        printf("1. Numeros de 0 a 999\n");
        printf("2. Numeros de 0 a 9999\n");
        printf("3. Numeros de 0 a 99999\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            case 2:
            case 3:
                menu_ordem(opcao);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (1);
}

void menu_ordem(int base_opcao) {
    int opcao;
    char base_path[PATH_MAX];

    do {
        printf("\nSelecione a ordem dos dados:\n");
        printf("1. Ordem Crescente\n");
        printf("2. Ordem Decrescente\n");
        printf("3. Ordem Aleatoria\n");
        printf("4. Voltar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 4) {
            return;
        }

        switch (base_opcao) {
            case 1:
                if (opcao == 1)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/1000/Ordem crescente/numeros_crescentes_999.txt");
                else if (opcao == 2)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/1000/Ordem decrescente/numeros_decrescentes_999.txt");
                else if (opcao == 3)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/1000/Ordem aleatoria/numeros_aleatorios_999.txt");
                break;
            case 2:
                if (opcao == 1)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/10000/Ordem crescente/numeros_crescentes_9999.txt");
                else if (opcao == 2)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/10000/Ordem decrescente/numeros_decrescentes_9999.txt");
                else if (opcao == 3)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/10000/Ordem aleatoria/numeros_aleatorios_9999.txt");
                break;
            case 3:
                if (opcao == 1)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/100000/Ordem crescente/numeros_crescentes_99999.txt");
                else if (opcao == 2)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/100000/Ordem decrescente/numeros_decrescentes_99999.txt");
                else if (opcao == 3)
                    snprintf(base_path, sizeof(base_path), "Base de Dados/100000/Ordem aleatoria/numeros_aleatorios_99999.txt");
                break;
        }

        if (opcao >= 1 && opcao <= 3) {
            menu_ordenacao(base_path);
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (1);
}

void menu_ordenacao(const char *caminho) {
    int opcao;
    int *dados = NULL;
    int tamanho = 0;

    // Ler os dados do arquivo
    dados = ler_arquivo(caminho, &tamanho);
    if (dados == NULL) {
        printf("Erro ao carregar os dados. Certifique-se de que o arquivo existe.\n");
        return;
    }

    do {
        printf("\nAlgoritmos de Ordenacao\n");
        printf("Base: %s\n", caminho);
        printf("Selecione uma opcao:\n");
        printf("1. Bolha\n");
        printf("2. Bolha Com Criterio de Parada\n");
        printf("3. Insercao direta\n");
        printf("4. Insercao binaria\n");
        printf("5. Shellsort\n");
        printf("6. Selecao direta\n");
        printf("7. Heapsort\n");
        printf("8. Quicksort\n");
        printf("9. Mergesort\n");
        printf("10. Radixsort\n");
        printf("11. Bucketsort\n");
        printf("12. Executar todos os algoritmos\n");
        printf("13. Voltar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
            printf("Usando Bolha Sem Criterio de Parada...\n");
            ordenaBolhaSemParada(dados, tamanho);
            break;

            case 2:
            printf("Usando Bolha Com Criterio de Parada...\n");
            ordenaBolhaComParada(dados, tamanho);
            break;

            case 3:
            printf("Usando Insercao direta...\n");
            break;

            case 4:
            printf("Usando Insercao binaria...\n");
            break;

            case 5:
            printf("Usando Shellsort...\n");
            break;

            case 6:
            printf("Usando Selecao direta...\n");
            break;

            case 7:
            printf("Usando Heapsort...\n");
            break;

            case 8:
            printf("Usando Quicksort...\n");
            break;

            case 9:
            printf("Usando Mergesort...\n");
            break;

            case 10:
            printf("Usando Radixsort...\n");
            break;

            case 11:
            printf("Usando Bucketsort...\n");
            break;

            case 12:
            printf("Executando todos os algoritmos...\n\n");
            break;

            case 13:
            free(dados);
            return;
            break;

            default:
            printf("Opcao invalida! Tente novamente.\n");

        }

    } while (1);

    free(dados);
}

int *ler_arquivo(const char *caminho, int *tamanho) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", caminho);
        return NULL;
    }

    // Contar a quantidade de numeros no arquivo
    int count = 0;
    int num;
    while (fscanf(arquivo, "%d", &num) != EOF) {
        count++;
    }

    // Alocar memória e voltar ao início do arquivo
    int *dados = (int *)malloc(count * sizeof(int));
    if (dados == NULL) {
        printf("Erro ao alocar memoria\n");
        fclose(arquivo);
        return NULL;
    }

    rewind(arquivo);

    // Ler os numeros para o array
    int i = 0;
    while (fscanf(arquivo, "%d", &num) != EOF) {
        dados[i++] = num;
    }

    *tamanho = count;
    fclose(arquivo);
    return dados;
}