#include <stdio.h>
#include <stdlib.h>

int tamanho;

void verifica(int A[], int *max, int *min)
{
    int i;
    for(i=0;i<tamanho;i++)
	{
        if(A[i]>*max)
		{
            *max = A[i];
        }
        if(A[i]<*min)
		{
            *min = A[i];
        }
    }
}


int main(void)
{
    int A[5] =  {1,2,3,4,5}, min=A[0],max=A[0];

    tamanho = sizeof(A)/sizeof(A[0]);

    verifica(A,&max,&min);

    printf("\nValor Maximo: %d\nValor Minimo: %d\n",max,min);
    return 0;
}
