#include "Menus.h"
#include "Utils.h"
#include "BinaryInsertionsort.h"
#include "BolhaCParada.h"
#include "BolhaSemParada.h"
#include "Bucketsort.h"
#include "Heapsort.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "QuickSortIni.h"
#include "QuickSortCentro.h"
#include "QuickSortMediana.h"
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
        printf("8. Quicksort Ini\n");
        printf("9. Quicksort Centro\n");
        printf("10. Quicksort Mediana\n");
        printf("11. Mergesort\n");
        printf("12. Radixsort\n");
        printf("13. Bucketsort\n");
        printf("14. Executar todos os algoritmos\n");
        printf("15. Voltar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            printf("Usando Bolha Sem Criterio de Parada...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double bSPT;
            extern long long int bSPComp;
            extern long long int bSPSwaps;
            bSPComp = 0;
            bSPSwaps = 0;
            bSPT = 0.0;

            ordenaBolhaSemParada(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Bolha sem parada", bSPComp, bSPSwaps, bSPT);
            free(dados_aux);

            break;
        }    
        case 2:
        {
            printf("Usando Bolha Com Criterio de Parada...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double bCPT;
            extern long long int bCPComp;
            extern long long int bCPSwaps;
            bCPComp = 0;
            bCPSwaps = 0;
            bCPT = 0.0;

            ordenaBolhaComParada(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Bolha com parada", bCPComp, bCPSwaps, bCPT);
            free(dados_aux);

            break;
        }
        case 3:
        {
            printf("Usando Insercao direta...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double iST;
            extern long long int iSComp;
            extern long long int iSSwaps;
            iSComp = 0;
            iSSwaps = 0;
            iST = 0.0;

            insertionSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Insercao direta", iSComp, iSSwaps, bCPT);
            free(dados_aux);

            break;
        }
        case 4:
        {
            printf("Usando Insercao binaria...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern long long int bIComp;
            extern long long int bISwaps;
            extern double bIST;
            bIComp = 0;
            bISwaps = 0;
            bIST = 0.0;

            binaryInsertionSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Insercao binaria", bIComp, bISwaps, bIST);
            free(dados_aux);

            break;
        }
        case 5:
        {
            printf("Usando Shellsort...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double sST;
            extern long long int sSComp;
            extern long long int sSSwaps;
            sSComp = 0;
            sSSwaps = 0;
            sST = 0.0;

            shellSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Shell sort", sSComp, sSSwaps, sST);
            free(dados_aux);

            break;
        }
        case 6:
        {
            printf("Usando Selecao direta...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double sSTE;
            extern long long int sSCompE;
            extern long long int sSSwapsE;
            sSCompE = 0;
            sSSwapsE = 0;
            sSTE = 0.0;

            selectionSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Selecao direta", sSCompE, sSSwapsE, sSTE);
            free(dados_aux);

            break;
        }
        case 7:
        {
            printf("Usando Heapsort...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double hST;
            extern long long int hSComp;
            extern long long int hSSwaps;
            hSComp = 0;
            hSSwaps = 0;
            hST = 0.0;

            heapSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Heap sort", hSComp, hSSwaps, hST);
            free(dados_aux);

            break;
        }
        case 8:
        {
            printf("Usando Quicksort Ini...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern long long int qSIComp;
            extern long long int qSISwaps;
            extern double qSIT;
            qSIComp = 0;
            qSISwaps = 0;
            qSIT = 0.0;

            quicksortIniWrapper(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Quicksort Ini", qSIComp, qSISwaps, qSIT);
            free(dados_aux);

            break;
        }
        case 9:
        {
            printf("Usando Quicksort Centro...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern long long int qSCComp;
            extern long long int qSCSwaps;
            extern double qSCT;
            qSCComp = 0;
            qSCSwaps = 0;
            qSCT = 0.0;

            quicksortCentroWrapper(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Quicksort Centro", qSCComp, qSCSwaps, qSCT);
            free(dados_aux);

            break;
        }
        case 10:
        {
            printf("Usando Quicksort Mediana...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern long long int qSMComp;
            extern long long int qSMSwaps;
            extern double qSMT;
            qSMComp = 0;
            qSMSwaps = 0;
            qSMT = 0.0;

            quicksortMedianaWrapper(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Quicksort Mediana", qSMComp, qSMSwaps, qSMT);
            free(dados_aux);

            break;
        }
        case 11:
        {
            printf("Usando Mergesort...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double mST;
            extern long long int mSComp;
            extern long long int mSSwaps;
            mSComp = 0;
            mSSwaps = 0;
            mST = 0.0;

            mergeSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Merge sort", mSComp, mSSwaps, mST);
            free(dados_aux);

            break;
        }
        case 12:
        {
            printf("Usando Radixsort...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double rST;
            extern long long int rSComp;
            extern long long int rSSwaps;
            rSComp = 0;
            rSSwaps = 0;
            rST = 0.0;

            radixSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Radix sort", rSComp, rSSwaps, rST);
            free(dados_aux);

            break;
        }
        case 13:
        {
            printf("Usando Bucketsort...\n");
            int *dados_aux = malloc(tamanho * sizeof(int));
            if (!dados_aux) {
                printf("Erro na alocacao da copia dos dados.\n");
                break;
            }
            memcpy(dados_aux, dados, tamanho * sizeof(int));

            extern double bSTE;
            extern long long int bSComp;
            extern long long int bSSwaps;
            bSComp = 0;
            bSSwaps = 0;
            bSTE = 0.0;

            bucketSort(dados_aux, tamanho);
            salvar_saida("saida.txt", dados_aux, tamanho, "Bucket sort", bSComp, bSSwaps, bSTE);
            free(dados_aux);

            break;
        }
        case 14:
        {
            printf("Executando todos os algoritmos...\n\n");

            const char *algoritmos[] = {
                "Bolha sem parada", "Bolha com parada", "Insercao direta", "Insercao binaria",
                "Shell sort", "Selecao direta", "Heap sort", "Quick sort Ini", "Quick sort Centro", "Quick sort Med", "Merge sort",
                "Radix sort", "Bucket sort"};
            long long int comparacoes[13] = {0};
            long long int trocas[13] = {0};
            double tempos[13] = {0};

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

            // Quicksort Ini

            memcpy(dados_copia, dados, tamanho * sizeof(int));
            quicksortIniWrapper(dados_copia, tamanho);
            comparacoes[7] = qSIComp;
            trocas[7] = qSISwaps;
            tempos[7] = qSIT;

            // Quicksort Centro

            memcpy(dados_copia, dados, tamanho * sizeof(int));
            quicksortCentroWrapper(dados_copia, tamanho);
            comparacoes[8] = qSCComp;
            trocas[8] = qSCSwaps;
            tempos[8] = qSCT;

            // Quicksort Mediana

            memcpy(dados_copia, dados, tamanho * sizeof(int));
            quicksortMedianaWrapper(dados_copia, tamanho);
            comparacoes[9] = qSMComp;
            trocas[9] = qSMSwaps;
            tempos[9] = qSMT;

            // Mergesort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            mergeSort(dados_copia, tamanho);
            comparacoes[10] = mSComp;
            trocas[10] = mSSwaps;
            tempos[10] = mST;

            // Radixsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            radixSort(dados_copia, tamanho);
            comparacoes[11] = rSComp;
            trocas[11] = rSSwaps;
            tempos[11] = rST;

            // Bucketsort
            memcpy(dados_copia, dados, tamanho * sizeof(int));
            bucketSort(dados_copia, tamanho);
            comparacoes[12] = bSComp;
            trocas[12] = bSSwaps;
            tempos[12] = bSTE;

            // Salvar os resultados no arquivo
            salvar_saida_todos("saida.txt", dados, tamanho, algoritmos, comparacoes, trocas, tempos, 13);

            // Libera a memória usada pela cópia
            free(dados_copia);
            break;
        }
        case 15:
            free(dados);
            return;
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (1);

    free(dados);
}