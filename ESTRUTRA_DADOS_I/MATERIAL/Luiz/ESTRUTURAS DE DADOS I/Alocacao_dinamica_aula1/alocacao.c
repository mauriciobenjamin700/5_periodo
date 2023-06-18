#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main(){
    srand(time(NULL));
    int *vet1, *vet2, m, x, i;
    printf("Tamanho do vetor:");
    scanf("%d",&m);
    printf("Valor de X:");
    scanf("%d",&x);
    vet1 = (int*) calloc(m, sizeof(int));
    vet2 = (int*) calloc(x, sizeof(int));
    if(vet1 == NULL && vet2 == NULL){
        printf("Memória insuficiente!");
    }
    printf("entrou no for 1\n");
    for(i=0; i < m; i++){
        vet1[i] = rand() % x;
    } 
    
    for(i=0; i < m; i++){
        printf("Vetor 1: %d\n", vet1[i]);
    } 
    printf("entrou no for 2\n");
    for(i=0; i < m; i++){
        vet2[vet1[i]]++;
    }
    for(i=0; i < x; i++){
        printf("O numero %d apareceu %d vezes.\n", i, vet2[i]);
    }
    return 0;
}
