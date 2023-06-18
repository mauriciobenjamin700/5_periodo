#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(NULL));
    int *v, x, *vet2;
    printf("Valor de X:");
    scanf("%d",&x);
    v = (int*) calloc(x, sizeof(int));
    vet2 = (int*) realloc(v, sizeof(int) * x * 2);
    //v = (int*) calloc(x, sizeof(int));
    if((v == NULL) || (vet2 == NULL)){
        exit(1);
    }
    for(int i=0; i < x; i++){
        scanf("%d",&v[i]);
    }
    int menor = v[0];
    for(int i=1; i < x; i++){
        if(v[i] < menor){
            menor = v[i];
        }
    }
    printf("O menor eh:%d", menor);
    free(v);

    return 0;
}