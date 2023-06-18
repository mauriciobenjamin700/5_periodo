#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "listaDuplamenteEncadeada.h"


struct conta{
     float saldo;
     int num_conta;
     char titular[100];
     struct conta *prox;
     struct conta *ant;
};


Conta * criarLista(){
    return NULL;
}

Conta * inserirInicio(Conta * lista){
    srand(time(NULL));
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);

    new->prox = lista;
    new->ant = NULL;
    if(lista != NULL)
        lista->ant = new;
    return new;
}


Conta *inserirFim(Conta *lista){
    srand(time(NULL));
    Conta *aux, *ant;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);

    new->prox = NULL;
    if(lista == NULL){
        new->ant = NULL;
        lista = new;
    }else{
        aux = lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = new;
        new->ant = aux;
    }
    return lista;
}

Conta *inserirOrdenado(Conta *lista){
    srand(time(NULL));
    Conta *aux, *ant;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);

    if(lista == NULL){
        new->prox = NULL;
        new->ant = NULL;
        lista = new;
        return new;
    }else{
        aux = lista;
        while(aux->prox != NULL && aux->num_conta < new->num_conta){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == lista){
            new->prox = lista;
            new->ant = NULL;
            lista = new;
        }else{
            new->prox = ant->prox;
            new->ant = ant;
            ant->prox = new;
            if(aux != NULL){
                aux->ant = new;
            }
        }
        return lista;
    }

}

Conta *remover(Conta *lista, int valor){
    Conta *aux = lista;
    while(aux != NULL && aux->num_conta != valor){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Conta nao encontrada!");
        return 0;
    }
    if(aux->ant == NULL){// remover o primeiro
        lista = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    if(aux->prox != NULL){
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return lista;

}

Conta *buscar(Conta* li, int valor){
    Conta *aux = li;
    while(aux == NULL && aux->num_conta != valor){
        aux = aux->prox;
    }
    if(aux->num_conta == valor){
        printf("Encontrou\n");
        return aux;
    }else{
        printf("Conta nao encontrada\n");
        return 0;
    }
}

Conta *alterar(Conta *lista, int oldValue, int newValue){
    Conta *aux;
    if(lista == NULL){
        printf("Lista vazia");
        return 0;
    }
    aux = buscar(lista, oldValue);
    aux->num_conta = newValue;
    printf("Alterou\n");
    return lista;
}

int listaVazia(Conta *lista){
    if(lista == NULL){
        printf("Lista vazia\n");
        return 1;
    }
    return 0;
}


void mostrarLista(Conta* l){
    Conta * aux = l;
    if(aux){
        printf("-----------------\n");
        printf("Dados da conta:\n");
        printf("-----------------\n");
        do{
            printf("Numero da conta: %d\n",aux->num_conta);
            printf("Saldo: %.2f\n",aux->saldo);
            printf("Titular: %s\n",aux->titular);
            printf("-----------------\n");
            aux = aux->prox;
        }while(aux!=NULL);
    } 
}

void liberarLista(Conta* l){
    Conta *aux;
    if(l != NULL){
        while(l != NULL){
            aux = l;
            l = l->prox;
            free(aux);
        }
        free(l);
    }
}