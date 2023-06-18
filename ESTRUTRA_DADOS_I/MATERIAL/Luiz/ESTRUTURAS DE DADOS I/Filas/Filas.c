#include<stdio.h>
#include<stdlib.h>
#include"Filas.h"



struct conta{
     float saldo;
     int num_conta;
     char titular[100];
     struct conta *prox;
};

struct fila{
     struct conta *inicio, *fim;
};


Fila * fila_cria(Fila * fila){
    fila->fim = NULL; 
    fila->inicio = NULL;
    return fila;
}


Fila * fila_insereFila(Fila * fila){
     srand(time(NULL));
     Conta *new = (Conta*)malloc(sizeof(Conta));
     new->num_conta = rand() %100 + 10;
     printf("Saldo\n");
     scanf("%f",&new->saldo);
     printf("Titular\n");
     scanf("%s",new->titular);
     new->prox = NULL;
     if(fila->fim == NULL){
          fila->inicio = new;
     }else{
          fila->fim->prox = new;
     }
     fila->fim = new;
     return fila;
}


Fila* fila_retiraFila(Fila* fila){
     if(fila == NULL)
          return 0;
     if(fila->inicio == NULL)
          return 0;
     Conta * aux = fila->inicio;
     fila->inicio = fila->inicio->prox;
     if(fila->inicio == NULL)
          fila->fim = NULL;
     free(aux);
     return fila;
}

int fila_vazia (Fila* fila){
     if(fila == NULL)
          return 1;
     if(fila->inicio == NULL)
          return 1;
     return 0;
}

void LiberarFila(Fila * fila){
     Conta *aux;
     if(fila != NULL){
          while(fila->inicio != NULL){
               aux = fila->inicio;
               fila->inicio = fila->inicio->prox;
               free(aux);
          }
          free(fila);
     }

}

void mostrar_inicio(Fila *fila){
     Fila * aux = fila;
     printf("Inicio da Fila:\n");
     printf("Saldo:%.2f\n", aux->inicio->saldo);
     printf("Numero da conta:%.2d\n",aux->inicio->num_conta);
     printf("Titular:%s\n", aux->inicio->titular);
}

void mostrar_fim(Fila *fila){
     Fila * aux = fila;
     printf("Fila de contas:\n");
     printf("Saldo:%.2f\n", aux->fim->saldo);
     printf("Numero da conta:%.2d\n",aux->fim->num_conta);
     printf("Titular:%s\n", aux->fim->titular);
}

void mostrar_todos_elementos_fila(Fila *fila){
     Conta * aux = fila->inicio;
     printf("Inicio da Fila:\n");
     while(aux != NULL){
        printf("Saldo:%.2f\n", aux->saldo);
        printf("Numero da conta:%.2d\n",aux->num_conta);
        printf("Titular:%s\n", aux->titular);
        aux = aux->prox;
     }
     printf("Fim da lista\n");
}