#include <stdio.h>
#include <stdlib.h>

void imprimi_matriz(int linhas, int colunas,int **ponteiro)
{
    int i,j;

    for (i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            printf("%d ", ponteiro[i][j]);
        }
        printf("\n");
    }
}


int main(void)
{
    FILE *arquivo;
    int **matriz;

    int linhas , colunas;
    int i,j;

    //arquivo = fopen("C:\\Users\\Notebook\\Documents\\GitHub\5_periodo\\ESTRUTRA_DADOS_I\\CODIGOS\\LISTA_3\\input.txt","r");
    arquivo = fopen("input.txt", "r");

    if ( arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo");
        return 1;
    }

    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);    

    //gerando matriz
    matriz = (int**) calloc(linhas,sizeof(int*));

    for(i=0;i<linhas;i++)
    {
        matriz[i] = (int*) calloc(colunas, sizeof(int));
    }


    for (i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            //printf("Escaniei a posicao [%d] [%d]", i,j);
            fscanf(arquivo, "%d", &matriz[i][j]);
            printf("conteudo posicao [%d][%d] == %d", i,j, &matriz[i][j]);
        }

    }

    imprimi_matriz(linhas, colunas, matriz);

    //liberando memoria
    for(i=0;i<linhas;i++)
    {  
        free(matriz[i]);

    }
    free(matriz);


    fclose(arquivo);

    return 0;
}