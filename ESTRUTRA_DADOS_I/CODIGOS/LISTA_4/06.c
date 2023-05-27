#include <stdio.h>

//procurando indice referente a posicão do valor no vetor se existir
int busca(int valor, int *vetor)
{
    if(valor==*vetor)
    {
        return 0;
    }
    return 1 + busca(valor,vetor++);
}

int main(void)
{
    int valor=2, vetor[] = {1,2,3};

    printf("O valor %d esta na posicao %d", 2, busca(valor, vetor));

    return 0;
}