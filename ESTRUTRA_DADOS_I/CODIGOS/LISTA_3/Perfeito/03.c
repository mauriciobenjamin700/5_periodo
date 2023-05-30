#include <stdio.h>
#include <stdlib.h>
<<<<<<< Updated upstream
=======
<<<<<<< HEAD

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
=======
>>>>>>> Stashed changes
#include <math.h>

#define MAX_SIZE 1000

struct SeedPoint {
    int x;
    int y;
    int label;
};

void ler_matriz(FILE* arquivo, int altura, int largura, int** matriz);

int diferenca(int x1, int y1, int x2, int y2);

void formar_grupos(int** matriz, int altura, int largura, struct SeedPoint seed);

void salvar_matriz(FILE* arquivo, int altura, int largura, int** matriz);

int main() 
{
    FILE* arquivoEntrada;

    arquivoEntrada = fopen("input.txt", "rt");

    printf("Linha 24\n");
    
    if (arquivoEntrada == NULL) 
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    int altura, largura;

    fscanf(arquivoEntrada, "%d", &altura);
    fscanf(arquivoEntrada, "%d", &largura);
    printf("%d\n%d\n", altura,largura);

    int **matriz;

    matriz = (int **) malloc(MAX_SIZE * sizeof(int*));

    ler_matriz(arquivoEntrada, altura, largura, matriz);

    fclose(arquivoEntrada);

    struct SeedPoint seed;
    seed.x = 690;
    seed.y = 440;
    seed.label = 255;

    formar_grupos(matriz, altura, largura, seed);

    FILE* arquivoSaida = fopen("output.txt", "w");

    if (arquivoSaida == NULL) 
    {
        printf("Erro ao criar o arquivo de saída.\n");

        return 1;
    }

    salvar_matriz(arquivoSaida, altura, largura, matriz);

    fclose(arquivoSaida);

    printf("Matriz atualizada salva em output.txt.\n");

    return 0;
}


void ler_matriz(FILE* arquivo, int altura, int largura, int** matriz) 
{
    int i, j;

    matriz = (int**) realloc(matriz, sizeof(int) * altura);
    for (i = 0; i < altura; i++) 
    {
            matriz[i] = (int*) malloc(largura * sizeof(int));
    }
    for (i = 0; i < altura; i++) 
    {
        for (j = 0; j < largura; j++) 
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }
}

int diferenca(int x1, int y1, int x2, int y2) 
{
    return abs(abs(x1 - y1) - abs(x2 - y2));
}

void formar_grupos(int** matriz, int altura, int largura, struct SeedPoint seed) 
{
    int valorSemente = seed.label,i,j;
    printf("%d < 100\n",diferenca(1, 1, seed.x, seed.y));
    for (i = 0; i < altura; i++) 
    {
        for (j = 0; j < largura; j++) 
        {
            if (diferenca(j, i, seed.x, seed.y) < 100) 
            {
                matriz[i][j] = valorSemente;
            } else 
            {
                matriz[i][j] = 0;
            }
        }
    }
}

void salvar_matriz(FILE* arquivo, int altura, int largura, int** matriz) 
{
    int i,j;
    fprintf(arquivo, "%d\n", altura);
    fprintf(arquivo, "%d\n", largura);

    for (i = 0; i < altura; i++) 
    {
        for (j = 0; j < largura; j++) 
        {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
<<<<<<< Updated upstream
=======
>>>>>>> 2543042f9ef4f10f9024d5da307cb25672fd2750
>>>>>>> Stashed changes
}