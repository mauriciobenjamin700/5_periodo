#include <stdio.h>
#include <stdlib.h>

int obtem_produtos_zerados(int codigo[], int estoque[],int numero_produtos,int *ponteiro)
{
    int produtos_estoque_zerado[numero_produtos];//deve conter apenas o codigo dos produtos zerados no estoque
    int i;

    for(i=0;i<numero_produtos;i++)
    {
        if (estoque[i]==0)
        {
            produtos_estoque_zerado[i] = codigo[i]; // adaptar para alocar dinamicamente

        }
        else
        {
            produtos[i] = 0;
        }
    }

    *ponteiro = sizeof(produtos_estoque_zerado)/sizeof(int);

    return produtos_estoque_zerado;
}


int main(void)
{
    // tamanhos ficticios, adaptar depois
    int codigo[3] = {1,2,3},estoque[3] = {4,6,0},numero_produtos, n_est_zerado;
    int *ponteiro_vetor;
    int i;

    numero_produtos = sizeof(codigo)/sizeof(int);

    ponteiro_vetor = obtem_produtos_zerados(codigo,estoque,numero_produtos,&n_est_zerado);

    printf("\nTotal de produtos fora de estoque == %d", n_est_zerado);

    for(i=0;i<numero_produtos;i++)
    {
        printf("\nVetor[%d], codigo do do produto com estoque zerado %d", i,ponteiro_vetor[i]);
    }

    return 0;
}