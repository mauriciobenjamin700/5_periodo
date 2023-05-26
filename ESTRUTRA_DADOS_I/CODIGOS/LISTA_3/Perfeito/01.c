#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define SIZE 3

void imprimi_matriz(int ***matriz,int SIZE)
{
    int i,j,p;
        //percorrendo a matriz tridimensional para visualizala
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            for(p=0;p<SIZE;p++)
            {
                printf("%d ", matriz[i][j][p]);
            }
            printf("\n");
        }
    printf("\n");
    }

}

float calcula_raio (int SIZE)
{
    return SIZE/2.0;
}


float calcula_area_esfera(float raio)
{
    return 4 * 3.14 * pow(raio,2);
}
int main(void)
{
    int ***matriz;
    int i,j;
    int SIZE;

    printf("\nSIZE: ");
    scanf("%d", &SIZE);


    //alocando a primeira dimensao da matriz
    matriz = (int***) calloc(SIZE, sizeof(int**));

    //alocando a segunda dimensao da matriz
    for (i=0;i<SIZE;i++)
    {
        matriz[i] = (int**) calloc(SIZE, sizeof(int*));
    }
    //alocando a terceira dimensão
    for(i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            matriz[i][j] = (int*) calloc(SIZE,sizeof(int));
        }
    }

    //imprimi_matriz(matriz);

    float raio = calcula_raio(SIZE);

    //formula para calcular a area da esfera

    float area_esfera = calcula_area_esfera(raio);


    printf("\nArea da esfera: %.2f", area_esfera);


    // deve-se lembrar que sempre liberamos memoria até a segunda dimensão, a terceira dimensão são apenas valores normais
    //liberando a memoria da segunda dimensao
    for (i=0;i<SIZE;i++)
    {
        free(matriz[i]);
    }

    //liberando memoria da primeira dimensao
    free(matriz);

    return 0;
}