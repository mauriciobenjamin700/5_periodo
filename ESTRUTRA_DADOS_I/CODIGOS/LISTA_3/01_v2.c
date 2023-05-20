#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Digite o tamanho da matriz tridimensional: ");
    scanf("%d", &tamanho);

    // Verificar se o tamanho é um número ímpar
    if (tamanho % 2 != 1) {
        printf("O tamanho da matriz deve ser um número ímpar.\n");
        return 1;
    }

    // Criar a matriz tridimensional preenchida com zeros
    int ***matriz = (int ***)malloc(tamanho * sizeof(int **));
    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int **)malloc(tamanho * sizeof(int *));
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = (int *)malloc(tamanho * sizeof(int));
            for (int k = 0; k < tamanho; k++) {
                matriz[i][j][k] = 0;
            }
        }
    }

    // Calcular o raio máximo possível
    int raioMaximo = tamanho / 2;

    // Verificar se a maior esfera inscrita pode ser formada em todos os pontos
    int raioAtual;
    for (raioAtual = raioMaximo; raioAtual > 0; raioAtual--) {
        int i, j, k;
        for (i = raioAtual; i < tamanho - raioAtual; i++) {
            for (j = raioAtual; j < tamanho - raioAtual; j++) {
                for (k = raioAtual; k < tamanho - raioAtual; k++) {
                    // Verificar se o ponto (i, j, k) está dentro da esfera
                    // Verifique as condições necessárias de acordo com a sua definição de "inscrito"
                    // Por exemplo, se o valor precisa ser igual a zero para considerar a esfera inscrita, use a seguinte condição:
                    // if (matriz[i][j][k] != 0) {
                    if (/* condição de verificação */) {
                        break;
                    }
                }
                if (k < tamanho - raioAtual) {
                    break;
                }
            }
            if (j < tamanho - raioAtual) {
                break;
            }
        }
        if (i == tamanho - raioAtual && j == tamanho - raioAtual && k == tamanho - raioAtual) {
            break;
        }
    }

    printf("O raio máximo da maior esfera inscrita é: %d\n", raioAtual);

    // Liberar memória da matriz
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
