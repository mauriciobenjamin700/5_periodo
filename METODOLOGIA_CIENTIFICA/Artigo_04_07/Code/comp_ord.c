#include <stdio.h>
#include "comp_ord.h"

struct retorno 
{
    int comparacao;
    int movimentaca;
};


Retorno bubbleSort(int array[], int size)
{
    int i, j;
    int temp;
    Retorno r;
    r.comparacao = 0;
    r.movimentaca = 0;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            r.comparacao++; //contando as comparações
            if (array[j] > array[j + 1]) 
            {
                // Troca os elementos
                r.movimentaca ++;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return r;
}


Retorno insertionSort(int array[], int size) {
    int i, key, j;
    Retorno r;
    r.comparacao = 0;
    r.movimentaca = 0;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return r;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Retorno selectionSort(int array[], int size) {
    int i, j, min_idx;
    Retorno r;
    r.comparacao = 0;
    r.movimentaca = 0;
    
    // Percorre a lista
    for (i = 0; i < size - 1; i++) {
        min_idx = i; // Assume que o elemento atual é o mínimo

        // Procura o mínimo na parte não ordenada
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        // Troca o mínimo com o primeiro elemento da parte não ordenada
        swap(&array[min_idx], &array[i]);
    }
    return r;
}

void imprimir(int* vetor, int size)
{
    int i=0;
    while (i<size)
    {
        printf("\nPosicao %d = %d", i, vetor[i]);
        i++;
    }
    

}