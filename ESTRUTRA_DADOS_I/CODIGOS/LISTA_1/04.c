#include <stdio.h>
#include <stdlib.h>
/*
Fa�a um programa que leia 2 valores inteiros e chame uma funcao que receba
estas 2 variaveis e troque o seu conteudo, ou seja, esta funcao� e chamada
passando duas variaveis A e B por exemplo e, apos a execucao da func�ao,
A conter �o valor de B e B tera o valor de A
*/
int troca(int *a, int *b){
    int aux=*a;

    *a = *b;
    *b = aux;

    return 0;

}

int main(){

    int x,y;

    printf("\n informe um valor para x: ");
    scanf("%d", &x);

    printf("\ninforme um valor para y: ");
    scanf("%d", &y);

    if (troca(&x,&y) == 0){
        printf("\nTroquei o valor de 'X' para %d", x);
        printf("\nTroquei o valor de 'Y' para %d", y);
    }
    else{
    printf("\nErro na funcao");
    }




return 0;
}
