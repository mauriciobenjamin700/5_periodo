#include <stdio.h>

#define TAMANHO 10

void analisa_array(int *array,int *maior, int *quantidade)
{
    int i;
    for(i=0;i<TAMANHO;i++)
	{
        if(*array>*maior)
		{
            *maior = *array;
            *quantidade = 1;
        }
		else if(*array == *maior)
		{
            *quantidade+=1;
        }
        array++;
    }
}


int main(void)
{
    int array[TAMANHO]={5,2,15,3,7,15,8,6,15},maior=0,quantidade=0;

    analisa_array(array,&maior,&quantidade);

    printf("\nMaior valor: %d\nQuantidade de ocorrencias: %d\n",maior,quantidade);
    return 0;
}