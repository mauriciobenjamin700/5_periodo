#include <stdio.h>

//procurando índice referente à posição do valor no vetor se existir
int busca(int valor, int *vetor, int tamanho, int indice)
{
    if (indice == tamanho) 
    {
        return -1; // valor não encontrado, retorna -1
    }

    else if (valor == vetor[indice]) 
    {
        return indice; // valor encontrado, retorna o índice
    }
    else
    {
    return busca(valor, vetor, tamanho, indice + 1); // continuar procurando
    }
}

int main(void)
{
    int valor = 3, vetor[] = {1, 2, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int posicao = busca(valor, vetor, tamanho, 0);
    if (posicao == -1) {
        printf("O valor %d nao foi encontrado no vetor.\n", valor);
    } else {
        printf("O valor %d esta na posicao %d do vetor.\n", valor, posicao);
    }

    return 0;
}
