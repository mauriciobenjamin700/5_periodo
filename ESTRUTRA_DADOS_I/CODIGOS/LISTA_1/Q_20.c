#include <stdio.h>

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
    float vet[10] = {-1,4,6,-18,-5,-2,12,-34,-11,-19};

    printf("%d\n",negativos(vet, N));

    return 0;
}