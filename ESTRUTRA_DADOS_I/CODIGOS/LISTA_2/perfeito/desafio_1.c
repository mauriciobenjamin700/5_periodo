#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINHAS  100
#define COLUNAS  100

int main(void){
    // letra a: Preenchendo a matriz com Zeros
    int **matriz;

    int i,j;

    matriz = (int **) calloc(100, sizeof(int *)); // Aloca 100 linhas
    for (i = 0; i < 100; i++) {
        matriz[i] = (int *) calloc(100, sizeof(int)); // Aloca 100 colunas para cada linha
    }
    
    // letra b: Preenchendo as dimensões do retangulo com 1 (começa no 25 e vai até 75)
    int esquerda_x = (LINHAS/2)/2;
    int direita_x = LINHAS - esquerda_x;

    int topo_y = (COLUNAS/2)/2;
    int base_y = COLUNAS - topo_y;

    for (i=esquerda_x;i<=direita_x;i++){
        for(j=topo_y;j<=base_y;j++){
            matriz[i][j] = 1;
        }
    }

    // letra c: Calcular o centro geométrico do retângulo
    int centro_x = (esquerda_x + direita_x) / 2;
    int centro_y = (topo_y + base_y) / 2;

    // letra d: Calcular o maior círculo inscrito ao retângulo e marcar os pontos internos com 2
    int raio_maximo = fmin(direita_x - centro_x, base_y - centro_y);
    for (i=0;i<=LINHAS;i++){
        for (j=0;j<=COLUNAS;j++){
            double distancia = sqrt(pow(i - centro_x, 2) + pow(j - centro_y, 2));
            if (distancia <= raio_maximo){
                matriz[i][j] = 2;
            }
        }
    }

    // Imprimir a matriz resultante
    for (i=0;i<LINHAS;i++){
        for (j=0;j<COLUNAS;j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Deseja encerrar? :");
    
    //para previnir que o usuário feche a matris tentando visualizar, tem um scan ali em baixo, até ele digitar algo e dar enter, a matriz fica na tela
    int sinal;
    scanf("%d", &sinal);
    if(sinal){
        free(matriz);
    }
   
    return 0;
}
