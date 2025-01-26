#include "BinaryInsertionsort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Variáveis globais para rastrear comparações, trocas e tempo
long long int bIComp;
long long int bISwaps;
double bIST;

// Função para realizar busca binária
int binarySearch(int a[], int item, 
				int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? 
				(low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, 
							mid + 1, high);
	return binarySearch(a, item, low, 
						mid - 1);
}

// Função para realizar ordenação por inserção binária
void binaryInsertionSort(int *array, int tamanho)
{
    printf("Executando insercao binaria\n");
    int i, loc, j, selected;
    bIComp = 0;
    bISwaps = 0;

    clock_t start, end;
    start = clock();

    for (i = 1; i < tamanho; ++i) 
    {
        j = i - 1;
        selected = array[i];

        loc = binarySearch(array, selected, 0, j);

        bIComp += j - loc + 1;

        while (j >= loc) 
        {
            array[j + 1] = array[j];
            j--;
            bISwaps++;
        }
        array[j + 1] = selected;
    }

    end = clock();

    bIST = ((double)(end - start)) / CLOCKS_PER_SEC;

}