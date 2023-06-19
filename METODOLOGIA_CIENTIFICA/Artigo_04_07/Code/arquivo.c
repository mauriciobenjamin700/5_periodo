#include <stdio.h>

void criar(double array[], int tamanho, char nome[])
{
FILE *arquivo;
arquivo = fopen(nome, "w");
if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
}
else
{
    int i;
    for (i=0;i<tamanho;i++)
    {
        fprintf(arquivo, "%lf\n", array[i]);
    }
    
}

fclose(arquivo);
}
/*
int main(void)
{
    double array[] = {1,2,3,4};

    criar(array, 4, "teste.txt");
    return 0;
}
*/