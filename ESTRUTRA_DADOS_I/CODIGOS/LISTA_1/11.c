#include <stdio.h>
#include <stdlib.h>



int main(void){
    int SIZE = 5,array[SIZE];
    int *ponteiro;

    for (ponteiro=array;    ponteiro < array + SIZE; ponteiro++){
        scanf("%d", ponteiro);
    }

    for (ponteiro=array;    ponteiro <array + SIZE; ponteiro++){
        if ((*ponteiro%2)==0){
            printf("\no numero %d eh par, logo seu endereco e %p", *ponteiro, ponteiro);
        }
    }


    return 0;
}
