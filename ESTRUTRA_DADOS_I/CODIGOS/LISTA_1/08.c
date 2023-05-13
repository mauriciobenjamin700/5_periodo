#include <stdio.h>
#include <stdlib.h>

int main(void){

    float array[10];

    int i;

    for (i=0;i<10;i++){

        printf("Endereco de memoria da posicao %d == %p\n",i,&array[i]);

    }

    return 0;
}