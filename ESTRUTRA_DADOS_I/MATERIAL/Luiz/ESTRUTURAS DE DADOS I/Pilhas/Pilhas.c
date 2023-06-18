#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Pilhas.h"

struct conta{
     float saldo;
     int num_conta;
     char titular[100];
     Conta *prox;
};

struct pilha{
    Conta *inicio;
};


Pilha * criarPilha(){
    Pilha *new = (Pilha*) malloc(sizeof(Pilha));
    new->inicio = NULL;
    return new;
}

Pilha * inserirPilha(Pilha * p){
    srand(time(NULL));
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);
    new->prox = p->inicio;
    p->inicio = new;
    return p;
}

Pilha * removerPilha(Pilha * p){
    Conta *aux;
    if(pilhaVazia(p))
        printf("Pilha vazia\n");
    aux = p->inicio->prox;
    free(p->inicio);
    p->inicio = aux;
    return p;
}

int pilhaVazia(Pilha * p){
    if(p->inicio == NULL){
        return 1;
    }
    return 0;
}

void liberarPilha(Pilha * p){
    Conta * aux = p->inicio;
    while(aux != NULL){
        aux = aux->prox;
        free(aux);
    }
    free(p);
}

void mostrarTodaPilha(Pilha * p){
    Conta * aux = p->inicio;
    if(pilhaVazia(p))
        printf("Pilha vazia\n");
    printf("Pilha de contas:\n");
    while(aux != NULL){
        printf("Saldo:%.2f\n", aux->saldo);
        printf("Numero da conta:%.2d\n",aux->num_conta);
        printf("Titular:%s\n", aux->titular);
        aux = aux->prox;
    }
}

void mostrarTopoPilha(Pilha * p){
    Pilha * aux = p;
    if(pilhaVazia(p))
        printf("Pilha vazia\n");
    printf("Topo da Pilha de contas:\n");
    printf("Saldo:%.2f\n", p->inicio->saldo);
    printf("Numero da conta:%.2d\n",p->inicio->num_conta);
    printf("Titular:%s\n", p->inicio->titular);
}