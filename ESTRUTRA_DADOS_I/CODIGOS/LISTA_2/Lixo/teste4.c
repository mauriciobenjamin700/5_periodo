#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define LINHAS  100
#define COLUNAS  100

// Definição das cores
#define COR_PADRAO 7 // Branco
#define COR_ZERO 9 // Azul
#define COR_UM 0 // Preto
#define COR_DOIS 6 // Amarelo

int main(void){
    // letra a: Preenchendo a matriz com Zeros
    int matriz[LINHAS][COLUNAS] = {0};
    int i,j;
    
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
    for (i=0;i<LINHAS;i++){
        for (j=0;j<COLUNAS;j++){
            double distancia = sqrt(pow(i - centro_x, 2) + pow(j - centro_y, 2));
            if (distancia <= raio_maximo){
                matriz[i][j] = 2;
            }
        }
    }

    // Imprimir a matriz resultante com cores
    for (i=0;i<LINHAS;i++){
        for (j=0;j<COLUNAS;j++){
            switch (matriz[i][j]){
                case 0:
                    textcolor(COR_ZERO);
                    printf("%d", matriz[i][j]);
                    break;
                case 1:
                    textcolor(COR_UM);
                    printf("%d", matriz[i][j]);
                    break;
                case 2:
                    textcolor(COR_DOIS);
                    printf("%d", matriz[i][j]);
                    break;
                default:
                    printf("%d", matriz[i][j]);
                    break;
            }
        }
        printf("\n");
    }

    // Restaurar a cor padrão
    textcolor(COR_PADRAO);

    return 0;
}
