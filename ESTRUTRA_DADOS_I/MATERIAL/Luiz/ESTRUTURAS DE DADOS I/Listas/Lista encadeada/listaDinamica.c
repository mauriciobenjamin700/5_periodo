#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"listaDinamica.h"



struct conta{
     float saldo;
     int num_conta;
     char titular[100];
     struct conta *prox;
};


Conta * criarLista(){
    return NULL;
}



Conta * inserir_no_inicio(Conta *l){
    srand(time(NULL));
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);
    new->prox = l;
    return new;
}

Conta * inserir_no_final(Conta *lista){
    srand(time(NULL));
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f", &new->saldo);
    printf("Titular\n");
    scanf(" %s", new->titular);
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

Conta *inserirOrdenado(Conta *lista){
    srand(time(NULL));
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f", &new->saldo);
    printf("Titular\n");
    scanf(" %s", new->titular);
    if(lista == NULL){// insere no inicio
        return new;
    }else{// procura onde inserir
        Conta * ant, *atual = lista;
        while(atual != NULL && atual->num_conta < new->num_conta){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == lista){// insere inicio
            aux->prox = lista;
            lista = aux;
        }else{
            aux->prox = ant->prox;
            ant->prox = aux;
        }
        return lista;
    }
}

Conta *remover(Conta *lista, int valor){
    Conta *ant, *aux = lista;
    while(aux != NULL && aux->num_conta != valor){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Conta nao encontrada!");
        return 0;
    }
    if(aux == lista){// remover o primeiro
        lista = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    free(aux);
    return lista;
}

Conta *buscar(Conta *lista, int valor){
    Conta *aux = lista;
    if(lista == NULL){
        printf("Lista vazia");
        return 0;
    }
    while(aux != NULL && aux->num_conta != valor){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Conta nao encontrada!");
        return 0;
    }
    return aux;

}

Conta *alterar(Conta *lista, int oldValue, int newValue){
    Conta *aux;
    if(lista == NULL){
        printf("Lista vazia");
        return 0;
    }
    aux = buscar(lista, oldValue);
    if(aux != NULL){
        aux->saldo == newValue;
    }
    return aux;
}

int listaVazia(Conta *lista){
    if (lista == NULL){
        printf("Lista vazia\n");
        return 1;
    }
    return 0;
}

void mostrarLista(Conta *l){
    Conta *aux = l;
    printf("Lista de contas:\n");
    while(aux != NULL){
        printf("Saldo:%.2f\n", aux->saldo);
        printf("Numero da conta:%.2d\n",aux->num_conta);
        printf("Titular:%s\n", aux->titular);
        aux = aux->prox;
    }
}

void liberarLista(Conta *l){
    Conta *aux;
    while(l != NULL){
        aux = l;
        l = l->prox;
        free(aux);
    }
    free(l);
}

