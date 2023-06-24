#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaestatica.h"


struct conta
{
	float saldo;
	int num_conta;
	char nome[100];
	
};
Conta *criarListaContasEstatica(int tam){
	Conta *listaContas = (Conta*) calloc(sizeof(Conta), tam);
	return listaContas;
}
void inserirElemento(Conta *lista, int p, int t){
	srand(time(NULL));
	if (p < t)
	{
		scanf("%f", &lista[p].saldo);
		scanf("%s", lista[p].nome);
		lista[p].num_conta = rand() % 100 + 10;
	}
}

void mostrarElemento(Conta elemento){
	printf("\nSaldo: %.2f\nNome: %s\nNumero da Conta: %d\n", elemento.saldo, elemento.nome, elemento.num_conta);
}
void mostrarTodosElementos(Conta *lista, int t){
	for (int i = 0; i < t; ++i)
	{
		mostrarElemento(lista[i]);
	}
}

/*
void removerElemento(Conta *lista, int t); //remover pelo numero da conta
int buscarElemento(Conta *lista, int tam, int num_conta);
void liberarMemoria(Conta *listaContas);
void mostrarSaldo(Conta *lista, int num_conta, int tamanho);
*/