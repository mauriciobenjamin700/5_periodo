#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10  // Número de linhas do tabuleiro
#define N 10  // Número de colunas do tabuleiro
#define NUM_CARROS 10  // Número de carros a serem gerados

typedef struct {
    int x;  // Posição x do carro
    int y;  // Posição y do carro
} Carro;

int verificarColisao(Carro* carros, int numCarros) {
    for (int i = 0; i < numCarros ; i++) {
        for (int j = 0; j < numCarros; j++) {
            // Verifica se há colisão entre os carros
            if (abs(carros[i].x - carros[j].x) == 1 || abs(carros[i].y - carros[j].y) == 1) {
                return 1;  // Colisão encontrada
            }
        }
    }
    return 0;  // Nenhuma colisão encontrada
}

void gerarCarros(Carro* carros, int numCarros, int linhas, int colunas) {
    for (int i = 0; i < numCarros; i++) {
        // Gera as posições x e y do carro aleatoriamente
        carros[i].x = rand() % (linhas);
        carros[i].y = rand() % (colunas);
    }
}

void mostrarTabuleiro(Carro* carros, int numCarros, int linhas, int colunas) {
    char matriz_xy[M][N];
    int i,j,k;
    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {

            // Verifica se há um carro na posição atual
            for ( k = 0; k < numCarros; k++) 
            {
                if (carros[k].x == i && carros[k].y == j) 
                {
                    matriz_xy[i][j] = 'C';
                }
                else
                {
                    matriz_xy[i][j] = '.';
                }
            }
        }
    }
    // Mostra o caractere correspondente ao estado da posição
    for(i=0;i<linhas;i++)
    {
        for(j=0;i<colunas;j++)
        {
            printf("%c ", matriz_xy[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    srand(time(NULL));

    Carro carros[NUM_CARROS];

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

        printf("Digite 0 para sair: ");
        scanf("%c", &sair);
        printf("\n");
    }

    return 0;
}
