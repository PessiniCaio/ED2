#include "Menus.h"
#include "Utils.h"
#include "BinaryInsertionsort.h"
#include "BolhaCParada.h"
#include "BolhaSemParada.h"
#include "Bucketsort.h"
#include "Heapsort.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "Quicksort.h"
#include "Radixsort.h"
#include "Selectionsort.h"
#include "Shellsort.h"

#define PATH_MAX 260

// Função principal do menu
void menu_principal()
{
    int opcao;

    do
    {
        // Exibe o menu principal para seleção do tamanho da base de dados
        printf("Base de Dados\n");
        printf("Selecione uma das opcoes abaixo:\n");
        printf("1. Numeros de 0 a 999\n");
        printf("2. Numeros de 0 a 9999\n");
        printf("3. Numeros de 0 a 99999\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_ordem(1000);
            break;
        case 2:
            menu_ordem(10000);
            break;
        case 3:
            menu_ordem(100000);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
}

// Função para selecionar a ordem dos números
void menu_ordem(int base_opcao)
{
    int opcao;
    char caminho[PATH_MAX];

    // Exibe o menu para selecionar a ordem dos números
    printf("Selecione a ordem dos numeros:\n");
    printf("1. Ordem Aleatoria\n");
    printf("2. Ordem Crescente\n");
    printf("3. Ordem Decrescente\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        sprintf(caminho, "Base de Dados/%d/Ordem aleatoria/numeros_aleatorios_%d.txt", base_opcao, base_opcao - 1);
        break;
    case 2:
        sprintf(caminho, "Base de Dados/%d/Ordem crescente/numeros_crescentes_%d.txt", base_opcao, base_opcao - 1);
        break;
    case 3:
        sprintf(caminho, "Base de Dados/%d/Ordem decrescente/numeros_decrescentes_%d.txt", base_opcao, base_opcao - 1);
        break;
    default:
        printf("Opcao invalida!\n");
        return;
    }

    FILE *file = fopen(caminho, "r");
    if (!file)
    {
        printf("Erro: Arquivo %s nao encontrado. Certifique-se de que ele existe.\n", caminho);
        return;
    }
    fclose(file);

    menu_ordenacao(caminho);
}

// Função para selecionar e executar os algoritmos de ordenação
void menu_ordenacao(const char *caminho)
{
    int opcao, tamanho;
    int *dados = ler_arquivo(caminho, &tamanho);

    if (dados == NULL)
    {
        printf("Erro ao carregar os dados. Certifique-se de que o arquivo existe.\n");
        return;
    }

    do
    {
        // Exibe o menu para selecionar o algoritmo de ordenação
        printf("\nAlgoritmos de Ordenacao\n");
        printf("Base: %s\n", caminho);
        printf("Selecione uma opcao:\n");
        printf("1. Bolha sem criterio de parada\n");
        printf("2. Bolha com criterio de parada\n");
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

        switch (opcao)
        {
        case 1:
            printf("Usando Bolha Sem Criterio de Parada...\n");

            extern double bSPT;
            extern long long int bSPComp;
            extern long long int bSPSwaps;

            bSPComp = 0;
            bSPSwaps = 0;
            bSPT = 0.0;

            ordenaBolhaSemParada(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Bolha sem parada", bSPComp, bSPSwaps, bSPT);

            break;

        case 2:
            printf("Usando Bolha Com Criterio de Parada...\n");

            extern double bCPT;
            extern long long int bCPComp;
            extern long long int bCPSwaps;

            bCPComp = 0;
            bCPSwaps = 0;
            bCPT = 0.0;

            ordenaBolhaComParada(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Bolha com parada", bCPComp, bCPSwaps, bCPT);

            break;

        case 3:
            printf("Usando Insercao direta...\n");

            extern double iST;
            extern long long int iSComp;
            extern long long int iSSwaps;

            iSComp = 0;
            iSSwaps = 0;
            iST = 0.0;

            insertionSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Insercao direta", iSComp, bCPSwaps, bCPT);

            break;

        case 4:
            printf("Usando Insercao binaria...\n");

            extern long long int bIComp;
            extern long long int bISwaps;
            extern double bIST;

            bIComp = 0;
            bISwaps = 0;
            bIST = 0.0;

            binaryInsertionSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Insercao binaria", bIComp, bISwaps, bIST);

            break;

        case 5:
            printf("Usando Shellsort...\n");

            extern double sST;
            extern long long int sSComp;
            extern long long int sSSwaps;

            sSComp = 0;
            sSSwaps = 0;
            sST = 0.0;

            shellSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Shell sort", sSComp, sSSwaps, sST);

            break;

        case 6:
            printf("Usando Selecao direta...\n");

            extern double sSTE;
            extern long long int sSCompE;
            extern long long int sSSwapsE;

            sSCompE = 0;
            sSSwapsE = 0;
            sSTE = 0.0;

            selectionSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Selecao direta", sSCompE, sSSwapsE, sSTE);

            break;

        case 7:
            printf("Usando Heapsort...\n");

            extern double hST;
            extern long long int hSComp;
            extern long long int hSSwaps;

            hSComp = 0;
            hSSwaps = 0;
            hST = 0.0;

            heapSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Heap sort", hSComp, hSSwaps, hST);

            break;

        case 8:
            printf("Usando Quicksort...\n");

            extern double qST;
            extern long long int qSComp;
            extern long long int qSSwaps;

            qSComp = 0;
            qSSwaps = 0;
            qST = 0.0;

            quickSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Quick sort", qSComp, qSSwaps, qST);

            break;

        case 9:
            printf("Usando Mergesort...\n");

            extern double mST;
            extern long long int mSComp;
            extern long long int mSSwaps;

            mSComp = 0;
            mSSwaps = 0;
            mST = 0.0;

            mergeSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Merge sort", mSComp, mSSwaps, mST);

            break;

        case 10:
            printf("Usando Radixsort...\n");

            extern double rST;
            extern long long int rSComp;
            extern long long int rSSwaps;

            rSComp = 0;
            rSSwaps = 0;
            rST = 0.0;

            radixSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Radix sort", rSComp, rSSwaps, rST);

            break;

        case 11:
            printf("Usando Bucketsort...\n");

            extern double bSTE;
            extern long long int bSComp;
            extern long long int bSSwaps;

            bSComp = 0;
            bSSwaps = 0;
            bSTE = 0.0;

            bucketSort(dados, tamanho);
            salvar_saida("saida.txt", dados, tamanho, "Bucket sort", bSComp, bSSwaps, bSTE);

            break;

        case 12:
            printf("Executando todos os algoritmos...\n\n");

            const char *algoritmos[] = {
                "Bolha sem parada", "Bolha com parada", "Insercao direta", "Insercao binaria",
                "Shell sort", "Selecao direta", "Heap sort", "Quick sort", "Merge sort",
                "Radix sort", "Bucket sort"};
            long long int comparacoes[11] = {0};
            long long int trocas[11] = {0};
            double tempos[11] = {0};

            // Cria uma cópia dos dados para cada algoritmo
            int *dados_copia = malloc(tamanho * sizeof(int));
            if (!dados_copia)
            {
                printf("Erro ao alocar memoria para dados_copia.\n");
                free(dados);
                return;
            }

            // Bolha sem parada
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            ordenaBolhaSemParada(dados_copia, tamanho);
            comparacoes[0] = bSPComp;
            trocas[0] = bSPSwaps;
            tempos[0] = bSPT;

            // Bolha com parada
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            ordenaBolhaComParada(dados_copia, tamanho);
            comparacoes[1] = bCPComp;
            trocas[1] = bCPSwaps;
            tempos[1] = bCPT;

            // Inserção direta
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            insertionSort(dados_copia, tamanho);
            comparacoes[2] = iSComp;
            trocas[2] = iSSwaps;
            tempos[2] = iST;

            // Inserção binária
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            binaryInsertionSort(dados_copia, tamanho);
            comparacoes[3] = bIComp;
            trocas[3] = bISwaps;
            tempos[3] = bIST;

            // Shellsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            shellSort(dados_copia, tamanho);
            comparacoes[4] = sSComp;
            trocas[4] = sSSwaps;
            tempos[4] = sST;

            // Seleção direta
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            selectionSort(dados_copia, tamanho);
            comparacoes[5] = sSCompE;
            trocas[5] = sSSwapsE;
            tempos[5] = sSTE;

            // Heapsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            heapSort(dados_copia, tamanho);
            comparacoes[6] = hSComp;
            trocas[6] = hSSwaps;
            tempos[6] = hST;

            // Quicksort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            quickSort(dados_copia, tamanho);
            comparacoes[7] = qSComp;
            trocas[7] = qSSwaps;
            tempos[7] = qST;

            // Mergesort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            mergeSort(dados_copia, tamanho);
            comparacoes[8] = mSComp;
            trocas[8] = mSSwaps;
            tempos[8] = mST;

            // Radixsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            radixSort(dados_copia, tamanho);
            comparacoes[9] = rSComp;
            trocas[9] = rSSwaps;
            tempos[9] = rST;

            // Bucketsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            bucketSort(dados_copia, tamanho);
            comparacoes[10] = bSComp;
            trocas[10] = bSSwaps;
            tempos[10] = bSTE;

            // Salvar os resultados no arquivo
            salvar_saida_todos("saida.txt", dados, tamanho, algoritmos, comparacoes, trocas, tempos, 11);

            // Libera a memória usada pela cópia
            free(dados_copia);
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