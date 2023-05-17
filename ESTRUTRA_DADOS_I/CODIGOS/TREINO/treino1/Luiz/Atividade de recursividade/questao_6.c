#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função que faça a procura sequencial de um 
valor passado por parâmetro num vetor também passado por 
parâmetro*/

int procurar(int *vet, int n, int i){
    if (vet[i] == n){
        printf("achou o numero na posicao %d do vetor", i);
        return vet[i];
    }
    return procurar(vet, n, i + 1);
}

int main(){
    int n, i=0, vet[10] = {6, 8, 4, 2, 3, 1, 7, 9, 5, 0};
    printf("valor de n: ");
    scanf("%d", &n);
    printf("\nnumero procurado: %d\n",procurar(vet, n, i));
    return 0;
}