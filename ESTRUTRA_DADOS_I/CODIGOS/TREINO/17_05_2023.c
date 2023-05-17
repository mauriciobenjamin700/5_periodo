/* Questão Xades com alocação dinâmica: Dado uma matriz N x M informadas pelo usuário, preencha essa matriz com valores de 1 a 6, onde cada valor representa:
    1 - Peão -> 1 ponto
    2 - Cavalo -> 2.5 pontos
    3 - Bispo -> 4.5 pontos
    4 - Torre - 6 pontos
    5 - Rainha - 8 pontos
    6 - Rei - 10 pontos

gere ao final um vetor alocado dinamicamente com a pontuação total para cada peça.

ex: teste usando N = 25, M = 15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_matriz(int **m, int l, int c){
    int i,j;
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}

void mostrar_vetor(int *v, int c)
{
    int i;
    printf("\n");
    for (i=0;i<c;i++)
    {
        printf("%d ", v[i]);
    }
}

void calcular_pontos(int *v)
{
    printf("\nTiveram %d peoes sorteados, totalizando %.2f pontos!", v[0], (float)v[0] * 1);
    printf("\nTiveram %d cavalos sorteados, totalizando %.2f pontos!", v[1], (float)v[1] * 2.5);
    printf("\nTiveram %d bispos sorteados, totalizando %.2f pontos!", v[2], (float)v[2] * 4.5);
    printf("\nTiveram %d torres sorteados, totalizando %.2f pontos!", v[3], (float)v[3] * 6);
    printf("\nTiveram %d rainhas sorteados, totalizando %.2f pontos!", v[4], (float)v[4] * 8);
    printf("\nTiveram %d reis sorteados, totalizando %.2f pontos!", v[5], (float)v[5] * 10);
}

int main(void)
{
    int **matriz;
    int i,j,l,c;
    int numero;
    
    int *vetor_resultado;

    // Inicializa a semente aleatória
    srand(time(NULL));
    
    printf("\nDigite o total de linhas da matriz: ");
    scanf("%d", &l);
    printf("\nDigite o total de colunas da matriz: ");
    scanf("%d", &c);

    //definindo as linhas da matriz
    matriz = (int**) malloc(l*sizeof(int*));

    //definindo as colunas da matriz
    for(i=0;i<c;i++)
    {
        matriz[i] = (int*) malloc(c*sizeof(int));
    }

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++){
            // Gera um número aleatório entre 1 e 6
            numero = rand() % 6 + 1;
            matriz[i][j] = numero;
        }
    }

    vetor_resultado = (int *) calloc(6,sizeof(int));
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++){
            vetor_resultado[matriz[i][j]-1] ++;
        }
    }

    mostrar_matriz(matriz,l,c);
    mostrar_vetor(vetor_resultado,6);
    calcular_pontos(vetor_resultado);


    return 0;
}
