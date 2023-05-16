#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int tamanho;

void imprime_array(int *array){
   
    int *ponteiro;
    for (ponteiro=array;ponteiro<array+tamanho;ponteiro++)
	{
        printf("%d\n", *ponteiro);
    }
}

int main(void){
    int vetor[SIZE],i;
    tamanho = sizeof(vetor)/sizeof(int);

    for(i=0;i<SIZE;i++)
	{
        vetor[i] = i;
    }

    imprime_array(vetor);

    return 0;
}
