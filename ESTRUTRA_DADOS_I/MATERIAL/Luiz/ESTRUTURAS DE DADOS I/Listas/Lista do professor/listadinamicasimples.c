#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = lista;
	return new;
}

void mostrarLista(Conta *lista){
	Conta *aux = lista;
	printf("\nPrint values \n");
	while(aux != NULL){
		printf("Nome: %s\nSaldo: %.2f\nNum conta %d\n ", aux->titular, aux->saldo, aux->num_conta);
		aux = aux->prox;
	}
}
