#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função recursiva que escreva na tela todos os
números inteiros positivos desde um valor K informado pelo
usuário até 0.*/

void mostrar_valores(k){
    if (k >= 0)
        printf("%d,", k);
    return mostrar_valores(k -1);    
}

int main(){
    int k;
    printf("informe o vvalor de K: ");
    scanf("%d", &k);
    mostrar_valores(k);
    return 0;
}

