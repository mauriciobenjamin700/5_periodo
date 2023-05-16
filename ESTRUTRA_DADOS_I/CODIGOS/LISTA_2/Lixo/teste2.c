#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINHAS 100
#define COLUNAS 100

// Função para verificar se um ponto está dentro do círculo
int estaDentroDoCirculo(int centroX, int centroY, int raio, int x, int y) {
    int distanciaCentro = sqrt(pow(x - centroX, 2) + pow(y - centroY, 2));
    return distanciaCentro <= raio;
}

int main(void) {
    int matriz[LINHAS][COLUNAS] = {0};
    int i, j;

    // Preenchendo as dimensões do retângulo com 1
    int esquerda_x = LINHAS / 4;
    int direita_x = LINHAS - esquerda_x;

    int topo_y = COLUNAS / 4;
    int base_y = COLUNAS - topo_y;

    for (i = esquerda_x; i <= direita_x; i++) {
        for (j = topo_y; j <= base_y; j++) {
            matriz[i][j] = 1;
        }
    }

    // Calculando o centro geométrico do retângulo
    int centroX = (esquerda_x + direita_x) / 2;
    int centroY = (topo_y + base_y) / 2;

    // Criando o maior círculo inscrito no retângulo
    int raio = (direita_x - esquerda_x) / 2;
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if (estaDentroDoCirculo(centroX, centroY, raio, i, j)) {
                matriz[i][j] = 2;
            }
        }
    }

    // Imprimindo a matriz resultante
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
