#include <stdio.h>
#include <stdlib.h>

/*existe a necessidade de testar a colisão entre carros. Os carros estão dispostos em um Tabuleiro de tamanho M (linhas) - N (colunas). 
Sortear Aleatoriamente 10 carros. Cada carro NAO pode ficar a menos de 50% da menor dimensão do Tabuleiro. Gerar várias iterações, 
até que o usuário saia informando um critério de saída. A cada iteração, gerar novos carros, testar as colisões e mostrar ao usuário 
o resultado. */

#define M 30
#define N 20
#define C 10

struct carros{
    //X e Y são as posiçoes e colisão tem valor de 0 ou 1, que 0 indica que não teve colisão e 1 que ocorreu colisão
    int x,y,colisao;
};

int main(void){
    int **base,*tabuleiro;

    base =  (int**) calloc(M,sizeof(int*));
    tabuleiro = (int*) calloc(N,sizeof(int));

    


    return 0;
}