#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

struct conta {
    int numConta;
    float saldo;
    char titular[100];
    Conta *proximo;
};

struct pilha {
    Conta *init;
};

Pilha *criarPilha(){
    Pilha *new = (Pilha *) malloc(sizeof(Pilha));
    new->init = NULL;
    return new;
}

Pilha *inserir(Pilha *pilha){
    Conta *new = (Conta *) malloc(sizeof(Conta));

    new->numConta = rand() % 100;
    printf("Insira o titular: "); scanf("%s", new->titular);
    printf("Insira o saldo: "); scanf("%f", &new->saldo);

    new->proximo = pilha->init;
    pilha->init = new;

    return pilha;
}

Pilha *remover(Pilha *pilha){
    Conta *aux;
    
    if(vazia(pilha)){
        printf("Nao ha o que remover!\n");

    }else{
        aux = pilha->init->proximo;
        free(pilha->init);
        pilha->init = aux;
    }

    return pilha;
}

int vazia(Pilha *pilha){
    return pilha->init == NULL ? 1 : 0;
}

void liberar(Pilha *pilha){
    Conta *aux = pilha->init;

    while(aux != NULL){
        aux = aux->proximo;
        free(pilha->init);
        pilha->init = aux;
    }

    printf("Liberada!\n");
}

void mostrarTopo(Pilha *pilha){
    printf("\nNumero: %d\n", pilha->init->numConta);
    printf("Titular: %s\n", pilha->init->titular);
    printf("Saldo: %.2f\n", pilha->init->saldo);
}

void mostrarTodaPilha(Pilha *pilha){
    Conta *aux = pilha->init;
    for(aux; aux != NULL; aux = aux->proximo){
        printf("\nNumero: %d\n", aux->numConta);
        printf("Titular: %s\n", aux->titular);
        printf("Saldo: %.2f\n", aux->saldo);
    }
}