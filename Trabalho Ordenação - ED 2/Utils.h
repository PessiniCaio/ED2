#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ler_arquivo(const char *caminho, int *tamanho);
int comparar(const void *a, const void *b);
void salvar_saida(const char *caminho, int *dados, int tamanho, const char *algoritmo, int comparacoes, int trocas, double tempo);
void salvar_saida_todos(const char *caminho, int *dados, int tamanho, const char **algoritmos, int comparacoes[], int trocas[], double tempos[], int n);

#endif 
