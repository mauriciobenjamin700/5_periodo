#include <stdio.h>

int maior(int array[], int tamanho)
{
    int maior = 0,i;

    for(i=0;i<tamanho;i++)
    {
        if(array[i] > maior)
        {
            maior = array[i];
        }
    }
    return maior;
}

int main(void) 
{
    int N,i,k;

    printf("\nInforme o tamanho do Array: ");
    scanf("%d", &N);

    int Array[N],*ponteiro;

    ponteiro = Array;

    for(i=0;i<N;i++)
    {
        scanf("%d", &Array[i]);
    }

    printf("Deseja visualizar quantos numeros por linha: ");
    scanf("%d", &k);

    while(N != 0)
    {
        N -= k;

        if(N < 0)
        {
            N += k;
            
            for(i=0;i<N;i++)
            {
                printf("%d ", *ponteiro);
                ponteiro++;
            }
            break;
        }

        for(i=0;i<k;i++)
        {
            printf("%d ", *ponteiro);
            ponteiro++;
        }
        printf("\n");   
    }

    printf("\nMaior valor: %d",maior(Array,sizeof(Array)/sizeof(Array[0])));

    return 0;
}


