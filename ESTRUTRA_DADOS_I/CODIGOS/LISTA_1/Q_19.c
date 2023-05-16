#include <stdio.h>

#define Tamanho 10

void analisa_array(int *array,int *maior, int *quant)
{
    int i;
    for(i=0;i<Tamanho;i++)
	{
        if(*array>*maior)
		{
            *maior = *array;
            *quant = 1;
        }
		else if(*array == *maior)
		{
            *quant+=1;
        }
        array++;
    }
}


int main(void){
    int array[Tamanho]={5,2,15,3,7,15,8,6,15},maior=0,quant=0;

    analisa_array(array,&maior,&quant);

    printf("\nMaior valor: %d\nQuantidade de ocorrencias: %d\n",maior,quant);
    return 0;
}
