// some os valores de um array de forma recursiva
#include <stdio.h>

int soma(int *array, int tamanho)
{
    if (tamanho > 0)
    {
        return array[tamanho-1] + soma(array,tamanho-1);
    }
    return 0;
}

int main(void)
{
    int vetor[] = {1,2,4,5};
    int tamanho = 2;

    printf("%d",soma(vetor, tamanho));

    return 0;
}