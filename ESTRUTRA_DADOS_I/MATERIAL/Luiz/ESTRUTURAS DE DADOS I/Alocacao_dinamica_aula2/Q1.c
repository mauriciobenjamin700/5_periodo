#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int x=0,*v=NULL,quant=0,soma=0;
    float media=0,variancia=0,desvio_padrao=0;

    for(int i=0; i != -1; i++){
        printf("Valor de X:");
        scanf("%d",&x);
        if(x == -1){
            break;
        }
        quant++;
        v = (int*) realloc(v, sizeof(int) * quant);
        if(v == NULL){
            exit(1);
        }      
        v[i] = x;
    }
    for(int i=0;i < quant; i++){
        soma += v[i];
    }
    media = soma/quant;
    for(int i=0;i < quant; i++){
        variancia += (pow((v[i] - media),2.0)/quant);
    }
    desvio_padrao = sqrt(variancia);
    printf("quant:%d\n", quant);
    printf("soma:%d\n", soma);
    printf("media:%.2f\n", media);
    printf("variancia:%.2f\n", variancia);
    printf("desvio padrao:%.2f\n", desvio_padrao);
    free(v);
    
    return 0;
}