#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10  // Número de linhas do tabuleiro
#define N 10  // Número de colunas do tabuleiro
#define NUM_CARROS 10  // Número de carros a serem gerados

#define MIN_DIST 0.5  // Distância mínima como porcentagem da menor dimensão

typedef struct {
    int x;  // Posição x do carro
    int y;  // Posição y do carro
} Carro;

int verificarColisao(Carro* carros, int numCarros) {
    for (int i = 0; i < numCarros - 1; i++) {
        for (int j = i + 1; j < numCarros; j++) {
            // Verifica se há colisão entre os carros
            if (abs(carros[i].x - carros[j].x) < 2 && abs(carros[i].y - carros[j].y) < 2) {
                return 1;  // Colisão encontrada
            }
        }
    }
    return 0;  // Nenhuma colisão encontrada
}

void gerarCarros(Carro* carros, int numCarros, int linhas, int colunas) {
    for (int i = 0; i < numCarros; i++) {
        // Gera as posições x e y do carro aleatoriamente
        carros[i].x = rand() % linhas;
        carros[i].y = rand() % colunas;
    }
}

void mostrarTabuleiro(Carro* carros, int numCarros, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int carroPresente = 0;

            // Verifica se há um carro na posição atual
            for (int k = 0; k < numCarros; k++) {
                if (carros[k].x == i && carros[k].y == j) {
                    carroPresente = 1;
                    break;
                }
            }

            // Mostra o caractere correspondente ao estado da posição
            if (carroPresente)
                printf("C ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Carro carros[NUM_CARROS];

    int sair = 0;
    while (!sair) {
        gerarCarros(carros, NUM_CARROS, M, N);
        int colisao = verificarColisao(carros, NUM_CARROS);

        printf("=== Tabuleiro ===\n");
        mostrarTabuleiro(carros, NUM_CARROS, M, N);
        printf("Colisão: %s\n", colisao ? "Sim" : "Não");

        printf("Digite 1 para continuar ou 0 para sair: ");
        scanf("%d", &sair);
        printf("\n");
    }

    return 0;
}
