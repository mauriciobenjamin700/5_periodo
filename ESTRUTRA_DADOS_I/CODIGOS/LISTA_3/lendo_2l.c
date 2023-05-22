#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int linha, coluna, teste, teste2;

    FILE *arquivo;

    arquivo = fopen("input.txt", "r");

    if(arquivo==NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        return 1;
    }


    fscanf(arquivo, "%d", &linha);
    fscanf(arquivo, "%d", &coluna);
    fscanf(arquivo, "%d", &teste);
    fscanf(arquivo, "%d", &teste2);

    printf("\nLinhas: %d", linha);
    printf("\nColunas: %d", coluna);
    printf("\n\nTeste: %d", teste);
    printf("\n\nTeste2: %d", teste2);
    return 0;
}