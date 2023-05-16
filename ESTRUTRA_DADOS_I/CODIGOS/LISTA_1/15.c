#include <stdio.h>
#include <stdlib.h>


void imprime_array(int *array, int tamanho){
   
    int *ponteiro;
    for (ponteiro=array;ponteiro<array+tamanho;ponteiro++){
        printf("%d\n", *ponteiro);
    }


}

int main(void){
    int vetor[5],i;
    int tamanho = sizeof(vetor)/sizeof(int);

    for(i=0;i<5;i++){
        vetor[i] = i;
    }

    imprime_array(vetor, tamanho);


    return 0;
}
