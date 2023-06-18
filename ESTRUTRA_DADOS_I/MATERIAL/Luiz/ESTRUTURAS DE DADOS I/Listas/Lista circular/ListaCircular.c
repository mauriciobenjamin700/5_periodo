#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "ListaCicular.h"

struct conta{
     float saldo;
     int num_conta;
     char titular[100];
     struct conta *prox;
};

Conta * criarLista(){
    return NULL;
}

Conta *inserir(Conta * lista){
    srand(time(NULL));
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);
 
    if(lista == NULL){
        new->prox = new;
    }else{
        aux = lista;
        while(aux->prox != lista){
            aux = aux->prox;
        }
        aux->prox = new;
        new->prox = lista;
    }
    return new;
}

Conta *inserirFim(Conta *lista){
    srand(time(NULL));
    Conta *aux;
    Conta *new = (Conta*)malloc(sizeof(Conta));
    new->num_conta = rand() %100 + 10;
    printf("Saldo\n");
    scanf("%f",&new->saldo);
    printf("Titular\n");
    scanf("%s",new->titular);

    if(lista == NULL){
        new->prox = new;
        return new;
    }else{
        aux = lista;
        while(aux->prox != lista){
            aux = aux->prox;
        }
        aux->prox = new;
        new->prox = lista;
    }
    return aux;
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
        new->prox = new;
        return new;
    }else{
        if(lista->num_conta > new->num_conta){
            aux = lista;
            while(aux->prox != lista){                
                aux = aux->prox;
                new->prox = lista;
                aux->prox = new;
                lista = new;
                return aux;
            }
        }
        Conta *ant = lista, *atual = lista->prox;
        while(atual != lista && atual->num_conta < new->num_conta){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = new;
        new->prox = atual;
    }
}

Conta *remover(Conta *lista, int valor){
    Conta *aux = lista;
    Conta *ant;
    if(aux->num_conta == valor){
        printf("O valor e igual");
        if(aux == aux->prox){
            free(aux);
            lista = NULL;
            printf("Removeu");
            return lista;
        }else{
            Conta *ultimo = lista;
            while(ultimo->prox != lista){
                ultimo = ultimo->prox;
            }
            ultimo->prox = lista->prox;
            lista = lista->prox;
            free(aux);
            printf("Removeu");
            return lista;
        }
    }
    ant = aux;
    aux = aux->prox;
    while(aux != lista && aux->num_conta != valor){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == lista){
        printf("Conta nao encontrada\n");
        return 0;
    }
    ant->prox = aux->prox;
    free(aux);
    return lista;
    
}

Conta *buscar(Conta *lista, int valor){
    Conta *aux = lista;
    while(aux->prox != lista && aux->num_conta != valor){
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
    }else{
        return 0;
    }

}

void mostrarLista(Conta* l){
    Conta * aux = l;
    if(aux){
        printf("------------------\n");
        printf("Dados da conta:\n");
        printf("------------------\n");
        do{
            printf("Numero da conta: %d\n",aux->num_conta);
            printf("Saldo: %.2f\n",aux->saldo);
            printf("Titular: %s\n",aux->titular);
            printf("----------------------\n");
            aux = aux->prox;
        }while(aux!=l);
    } 
}

void liberarLista(Conta *l){
    Conta* aux;
    Conta* Lista;
    Lista = l;
    while(l != Lista->prox){
        aux = Lista;
        Lista = Lista->prox;
        free(aux);
    }
    free(Lista);
    free(l);
}

