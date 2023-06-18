#include <stdio.h>
#include <stdlib.h>

#include "pilhaDevolucoes.h"
#include "rotas.h"

struct rotas{
    char cidade;
    int numero;
    char endereco;
    struct rotas *prox;
};

struct pilha{
	struct rotas *topo;
};


Pilha * criarPilhaDevolucao(){
    Pilha *new = (Pilha*) malloc(sizeof(Pilha));
    new->topo= NULL;
    return new;
}

Pilha * inserirPIlhaDevolucao(Pilha * pilhas, Rotas *aux){
	aux->prox = pilhas->topo;
	pilhas->topo = aux;
	return pilhas;
}

Pilha * removerPilhaDevolucao(Pilha * pilhas, Rotas *aux){
	if(pilhas->topo == NULL){
		printf("Pilha vazia\n");
        return 0;
    }
	aux = pilhas->topo->prox;
    free(pilhas->topo);
    pilhas->topo = aux;
    return pilhas;
}

void mostrarPilhaDevolucao(Pilha *pilhas, Rotas *aux){
	aux = pilhas->topo;
	if(pilhas->topo == NULL){
		printf("Pilha vazia\n");
        return 0;
    }
	while(aux = NULL){
		printf("Cidade: %s", aux->cidade);
		printf("Numero: %s", aux->numero);
		printf("Endereco: %s", aux->endereco);
		aux = aux->prox;
	}

}

