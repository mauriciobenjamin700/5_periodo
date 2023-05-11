#include <stdio.h>
#include <stdlib.h>

/*
2. Escreva um programa que contenha duas variaveis inteiras. Compare seus endereços e exiba o maior endereço.
*/

int main(void){
    int x,y;

    printf("\nEndereco de X == %p, em decimal = %d \nEndereco de Y == %p, em decimal = %d", &x,&x,&y,&y);

    if (&x>&y){
        printf("\n\nX possui um maior endereco de memoria!\n\n");
    }
    else{
        printf("\\nnY possui um maior endereço de memoria!\n\n");
    }


    return 0;
}
