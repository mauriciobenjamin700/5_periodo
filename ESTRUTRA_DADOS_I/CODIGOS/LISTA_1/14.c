#include <stdio.h>
#include <stdlib.h>

void preenche_array(int *array, int *valor, int tamanho){
   

    int *ponteiro;

    for (ponteiro=array; ponteiro < array + tamanho; ponteiro++){

        *ponteiro = *valor;

    }


}

int main(void){

    int array[5], valor=6,i;

    int tamanho = sizeof(array)/sizeof(valor);

    preenche_array(array,&valor,tamanho);

    for(i=0;i<tamanho;i++){
        printf("%d\n", array[i]);
    }


    return 0;

}