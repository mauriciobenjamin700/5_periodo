#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função recursiva que calcule a soma de todos
os números compreendidos entre os valores A e B passados
por parâmetro.*/

int soma_valores(int A, int B){
    if (A > B)
        return 0;
    return A + soma_valores(A + 1, B);
}

int main(){
    printf("A soma dos valores eh: %d", soma_valores(2, 6));
    return 0;
}