#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM_CARROS 10  // Número de carros a serem gerados

int M=0; // Número de linhas do tabuleiro
int N=0; // Número de colunas do tabuleiro

typedef struct {
    int x;  // Posição x do carro
    int y;  // Posição y do carro
} Carro;

int verificarColisao(Carro* carros, int numCarros) {
    for (int i = 0; i < numCarros ; i++) {
        for (int j = 0; j < numCarros; j++) {
            // Verifica se há colisão entre os carros
            if (abs(carros[i].x - carros[j].x) < 2 || abs(carros[i].y - carros[j].y) < 2) {
                return 1;  // Colisão encontrada
            }
        }
    }
    return 0;  // Nenhuma colisão encontrada
}

void gerarCarros(Carro* carros, int numCarros, int linhas, int colunas) {

    int i;

    srand(time(NULL));

    for ( i = 0; i < numCarros; i++) {
        // Gera as posições x e y do carro aleatoriamente
        carros[i].x = rand() % (linhas);
        carros[i].y = rand() % (colunas);
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

int main() 
{
    
    Carro carros[NUM_CARROS];

    printf("\nNumero de linhas do tabuleiro: ");
    scanf("%d", &M);
    printf("\nNumero de colunas do tabuleiro: ");
    scanf("%d", &N);
    

    char sair = '1';
    while (sair != '0') {
        
        gerarCarros(carros, NUM_CARROS, M, N);

        printf("=== Tabuleiro ===\n");

        mostrarTabuleiro(carros, NUM_CARROS, M, N);

        int colisao = verificarColisao(carros, NUM_CARROS);
        
        if (colisao==1)
        {
            printf("\nEncontrei colisao\n");
        }
        else
        {
            printf("\nNao encontrei colisao\n");
            
        }

        printf("\nDigite 0 para sair: ");
        scanf("%c", &sair);
        printf("\n");

        printf("\nNumero de linhas do tabuleiro: ");
        scanf("%d", &M);
        printf("\nNumero de colunas do tabuleiro: ");
        scanf("%d", &N);
    }

    return 0;
}
