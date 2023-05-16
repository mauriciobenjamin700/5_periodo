#include <stdio.h>

int main(void) {
    int array[5] = {0,1,2,3,4},*ponteiro,i,tam;
    ponteiro = array;
    tam = sizeof(array)/sizeof(array[0]);
    for(i=0;i<tam;i++){
        *ponteiro += 1;
        printf("%d ",*ponteiro);
        ponteiro++;
    }
    return 0;
}