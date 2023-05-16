#include <stdio.h>
#include <stdlib.h>


int main(void){

    int vetor[10];

    printf("O vetor tem %d bytes: ", sizeof(vetor));
    printf("O vetor tem tamanho %d : ", sizeof(vetor)/sizeof(int));

    return 0;


}