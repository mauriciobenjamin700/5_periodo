#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

// Função para imprimir a matriz
void imprimirMatriz(int **matriz) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **matriz;

    // Etapa a: Preencher a matriz com valores 0
    matriz = (int **)calloc(SIZE, sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        matriz[i] = (int *)calloc(SIZE, sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória\n");
            return 1;
        }
    }

    // Etapa b: Gerar o retângulo inscrito na matriz
    int retanguloTam = SIZE / 2;
    int retanguloInicio = (SIZE - retanguloTam) / 2;
    for (int i = retanguloInicio; i < retanguloInicio + retanguloTam; i++) {
        for (int j = retanguloInicio; j < retanguloInicio + retanguloTam; j++) {
            matriz[i][j] = 1;
        }
    }

    // Etapa c: Calcular o centro geométrico do retângulo
    int centroX = retanguloInicio + retanguloTam / 2;
    int centroY = retanguloInicio + retanguloTam / 2;

    // Etapa d: Criar o círculo inscrito no retângulo
    int raio = retanguloTam / 2;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int distanciaCentro = sqrt(pow(i - centroX, 2) + pow(j - centroY, 2));
            if (distanciaCentro <= raio) {
                matriz[i][j] = 2;
            }
        }
    }

    // Imprimir a matriz resultante
    imprimirMatriz(matriz);

    // Liberar a memória alocada
    for (int i = 0; i < SIZE; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
