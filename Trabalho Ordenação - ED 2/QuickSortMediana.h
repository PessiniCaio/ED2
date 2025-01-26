#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H

extern long long int qSMComp;
extern long long int qSMSwaps;
extern double qSMT;

void quicksortMediana(int *array, int low, int high);
void quicksortMedianaWrapper(int *array, int tamanho);

#endif // QUICKSORTMEDIANA_H
