#include <stdio.h>
#include <stdlib.h>

/*Escreva um algoritmo recursivo que escreva na tela a soma
de todos os números inteiros positivos de K até 0.*/

int soma(k){
    if(k < 0)
        return 0;
    return k + soma(k-1);
}

int main(){
    int k;
    printf("Informe o valor de K: ");
    scanf("%d", &k);
    printf("A soma dos valores eh: %d", soma(k));
    return 0;
}