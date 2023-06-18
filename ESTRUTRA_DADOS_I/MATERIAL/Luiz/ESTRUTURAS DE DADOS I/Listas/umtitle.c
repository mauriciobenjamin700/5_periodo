#include<stdio.h>
#include<stdlib.h>
#include"listaDinamica.h"

// struct conta{
//     float saldo;
//     int num_conta;
//     char titular[100];
//     struct conta *prox;
// };


Conta * criarLista(){
    return NULL;
}

Conta * inserir(Conta *l){
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->saldo = 899;
    new->num_conta = 111;
    scanf("%s",new->titular);
    new->prox = l;
    return new;
}

void mostrarLista(Conta *l){
    Conta *aux = l;
    while(aux != NULL){
        printf("Saldo:%f", aux->saldo);
        printf("Numero da conta:%d",aux->num_conta);
        printf("Titular:%s", aux->titular);
    }
}

Conta * inserir_no_final(Conta *lista){
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    scanf("%f", &new->saldo);
    scanf("%d", &new->num_conta);
    scanf(" %s", &new->titular);
    new->prox = NULL;
    if(lista == NULL)
        return new;
    aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = new;
    return lista;
}




