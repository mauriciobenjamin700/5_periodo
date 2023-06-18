#include <stdio.h>
#include <stdlib.h>

#include "rotas.h"

struct rotas{
    char cidade;
    int numero;
    char endereco;
    struct rotas *prox;
};

struct fila{
    struct rotas *inicio, *fim;
};

Fila *CriarFiladeRotas(Fila * fila){
    fila->fim = NULL; 
    fila->inicio = NULL;
    return fila;
}

Fila *fila_insereRotas(Fila * fila){
     Rotas *novaRota = (Rotas*)malloc(sizeof(Rotas));
     printf("Cidade\n");
     scanf("%s",novaRota->cidade);
     printf("Numero\n");
     scanf("%d",&novaRota->numero);
     printf("Endereco\n");
     scanf("%s",novaRota->endereco);
     novaRota->prox = NULL;
     if(fila->fim == NULL){
          fila->inicio = novaRota;
     }else{
          fila->fim->prox = novaRota;
     }
     fila->fim = novaRota;
     return fila;
}

Fila *fila_RemoverRota(Fila* fila, Rotas *aux){
     if(fila == NULL)
          return 0;
     if(fila->inicio == NULL)
          return 0;
     aux = fila->inicio;
     fila->inicio = fila->inicio->prox;
     if(fila->inicio == NULL)
          fila->fim = NULL;
     free(aux);
     return fila;
}

void mostrarRotas(Fila *fila){
     Rotas * aux = fila->inicio;
     if(fila == NULL)
          return 0;
     while(aux != NULL){
        printf("Cidade:%.2f\n", aux->cidade);
        printf("Numero:%.2d\n",aux->numero);
        printf("Endereco:%s\n", aux->endereco);
        aux = aux->prox;
     }
}

