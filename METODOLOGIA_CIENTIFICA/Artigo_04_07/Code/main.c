#include <stdio.h>
#include "ordenacao.c"
#include <stdlib.h>
#include <time.h>


#define SIZE 100

int main(void)
{
    int vetor[SIZE];

    // Inicializa a semente com o valor do relógio do sistema
    srand(time(NULL));

    int i=0;

    //clock_t start,end;

    while (i<SIZE)
    {
        vetor[i] = rand() % 10;  // Gera números aleatórios de 0 a 9
        i++;
    }
    
    imprimir(vetor,SIZE);

    // Mede o tempo de execução do Bubble Sort
    clock_t start = clock();
    //start = clock();
    printf("\nApos BubbleSort:");
    bubbleSort(vetor,SIZE);
    //end = clock();
    clock_t end = clock();

    //printf("\nApos InsertionSort:");
    //insertionSort(vetor,SIZE);

    //printf("\nApos SelectionSort:");
    //selectionSort(vetor, SIZE);

    imprimir(vetor,SIZE);
    

    // Calcula o tempo decorrido
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %lf segundos\n", time_taken);

    return 0;
}