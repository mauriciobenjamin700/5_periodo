#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int obtem_produtos_zerados(int *codigo, int *estoque,int *cod_prod_zerados,int quantidade_produtos)
{
    int i,quantidade_fora_estoque=0;

    cod_prod_zerados = (int*) realloc(cod_prod_zerados,quantidade_produtos * sizeof(int));

    for(i=0;i<quantidade_produtos;i++)
    {
        if(*estoque == 0)
        {
            *cod_prod_zerados = *codigo;
            quantidade_fora_estoque++;
            cod_prod_zerados++;
        }
        estoque++;
        codigo++;
    }

    return quantidade_fora_estoque;
}


int main(void)
{

    int codigo[TAMANHO] = {1,2,3,4,5}, estoque[TAMANHO] = {5,0,9,0,0},*cod_prod_zerados,quantidade_fora_estoque,quantidade_produtos,i;

    cod_prod_zerados = (int*) malloc(1*sizeof(int));

    quantidade_produtos = sizeof(codigo)/sizeof(codigo[0]);

    quantidade_fora_estoque = obtem_produtos_zerados(codigo,estoque,cod_prod_zerados,quantidade_produtos);

    printf("Numero de  produtos fora de estoque: %d\n",quantidade_fora_estoque);

    for(i=0;i<quantidade_fora_estoque;i++)
    {
        printf("\nCodigo do do produto com estoque zerado: %d",*cod_prod_zerados);
        cod_prod_zerados++;
    }

    free(cod_prod_zerados);

    return 0;
}
