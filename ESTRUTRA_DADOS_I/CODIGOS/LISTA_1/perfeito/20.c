#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N){
    int i,num_negativo=0;

    for(i=0; i<N; i++){
        if(*vet < 0){
            num_negativo++;
        }
        vet++;
    }
    return num_negativo;
};


int main(void) {
    int N = 10;
    float vet[10] = {-1,1,2,-1,-5,-25,0,-34,-111,-321};

    printf("\nTotal de negativos: %d\n",negativos(vet, N));

    return 0;
}