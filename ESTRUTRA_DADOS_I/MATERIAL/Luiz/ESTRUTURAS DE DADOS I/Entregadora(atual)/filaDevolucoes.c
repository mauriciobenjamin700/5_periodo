#include <stdio.h>
#include <stdlib.h>

#include "filaDevolucoes.h"

struct rotas{
    char cidade;
    int numero;
    char endereco;
    struct rotas *prox;
};

struct fila{
    struct rotas *inicio, *fim;
};


Fila * inserirFilaDevolucao(Fila * fila, struct rotas * aux){
    aux->prox = NULL;
    if(fila->fim == NULL){
          fila->inicio = aux;
     }else{
          fila->fim->prox = aux;
     }
     fila->fim = aux;
     return fila;
}


Fila * removerFilaDevolucao(Fila * fila, Rotas * aux){
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

void mostrarFilaDevolucao(Fila *fila, struct rotas * aux){
    
}