#ifndef QUICKSORTCENTRO_H
#define QUICKSORTCENTRO_H

extern long long int qSCComp;
extern long long int qSCSwaps;
extern double qSCT;

void quicksortCentro(int *array, int low, int high);
void quicksortCentroWrapper(int *array, int tamanho);

#endif // QUICKSORTCENTRO_H
