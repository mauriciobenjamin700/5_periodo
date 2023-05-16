#include <stdio.h>
#include <stdlib.h>

int tamanho;

void verifica(int array[], int *max, int *min)
{
    int i;
    for(i=0;i<tamanho;i++)
	{
        if(array[i]>*max)
		{
            *max = array[i];
        }
        if(array[i]<*min)
		{
            *min = array[i];
        }
    }
}


int main(void)
{
    int array[5] =  {1,2,3,4,5}, min=array[0],max=array[0];

    tamanho = sizeof(array)/sizeof(array[0]);

    verifica(array,&max,&min);

    printf("\nValor Maximo: %d\nValor Minimo: %d\n",max,min);
    return 0;
}