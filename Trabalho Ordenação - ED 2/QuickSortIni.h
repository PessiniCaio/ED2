#ifndef QUICKSORTINI_H
#define QUICKSORTINI_H

extern long long int qSIComp;
extern long long int qSISwaps;
extern double qSIT;

int particionar(int *array, int low, int high, long long int *num_comparacoes, long long int *num_trocas);
void quicksortIni(int *array, int low, int high, long long int *num_comparacoes, long long int *num_trocas);
void quicksortIniWrapper(int *array, int tamanho);

#endif // QUICKSORTINI_H
