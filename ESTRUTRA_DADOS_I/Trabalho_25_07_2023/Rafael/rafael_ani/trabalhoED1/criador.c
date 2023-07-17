#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"fazenda.h"
#include "criador.h"


struct criador{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	srand(time(NULL));
	int opcao = 0;
	Criador *aux_criador,*cad = (Criador*) malloc (sizeof(Criador));
	printf("\n");
	cad->id_criador = rand() % 100 + 10;
	printf("Digite o nome da Criador: ");
	scanf("%s", &cad->nome);
	printf("Digite o patrimonio: ");
	scanf("%f", &cad->patrimonio);
	printf("\n%d", cad->id_criador);
	cad->prox = NULL;
	cad->fazendas = NULL;
	while (opcao != 2){
		//printf("Entrou 1");
		printf("\nDeseja cadastrar uma fazenda?\n 1 - Sim\n 2 - Nao\n");
		scanf("%d", &opcao);
		if(opcao == 1){
			cad->fazendas = cadastrarFazenda(cad->fazendas, cad->id_criador);
		}
		else if(opcao == 2){
			break;
		}
		else {
			break;
		}
	}
	cad->prox = criadores;
	cad->ant = NULL;

	if (criadores != NULL){
		criadores->ant = cad;
	}
	//printf("Entrou 2");
	return cad;
}

Criador *removerCriador(Criador *criadores, int id){
	Criador *aux_remover = criadores;
	Criador *aux2_remover = criadores;
	while (aux_remover != NULL){
		if(aux_remover->id_criador= id){
			aux2_remover = aux_remover;
			aux_remover->ant->prox = aux_remover->prox;
			aux_remover->prox->ant = aux_remover->ant;
			free(aux2_remover);

		}
		aux_remover = aux_remover->prox;
	}
	
	return criadores;
}

int buscarCriador(Criador *criadores){
	int id;
	printf("Digite id criador:\n ");
	scanf("%d", &id);
	Criador *aux_busca = criadores;
	while (aux_busca != NULL){
		if (aux_busca->id_criador == id){
			return aux_busca->id_criador;
		}
		aux_busca = aux_busca->prox;
	}
		return 0;
	
}

void mostrarCriador(Criador *criadores){
	Criador *aux = criadores;
	do{
		printf("DADOS DO CRIADOR\n");
		printf("Nome: %s\n",aux->nome);
		printf("Patrimonio: %.2f\n",aux->patrimonio);
		printf("Id: %d\n",aux->id_criador);
		printf("\n");

		if(aux->fazendas == NULL)
		{
			printf("Esse Criador nao possui fazendas\n");
		}
		else
		{
			printf("\nDADOS DA FAZENDA\n");
			mostrarFz(aux->fazendas,aux->id_criador);
			printf("__________________________\n");
		}
		aux = aux->prox;
	}while (aux != NULL);
	
}

void liberarMemoria(Criador *criadores){
	Criador *aux = criadores;
	Criador *aux2;
	while (aux != NULL){
		aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
}

Criador *alterarFz(Criador *criadores, int id)
{
	printf("\nAlterar fazenda \n");
	int idfazenda;
	Criador *aux = criadores;
	printf("Digite o Id da fazenda: ");
	scanf("%d",&idfazenda);
	
	while(aux != NULL)
	{
		if(aux->id_criador == id)
		{
			aux->fazendas = alterarFazenda(aux->fazendas,idfazenda);
		}
		aux = aux->prox;
	}
	return criadores;
}

Criador *removerFz(Criador *criadores, int id)
{
	printf("\nRemover fazenda \n");
	int idfazenda;
	Criador *aux = criadores;
	printf("Digite o Id da fazenda: ");
	scanf("%d",&idfazenda);
	
	while(aux != NULL)
	{
		if(aux->id_criador == id)
		{
			aux->fazendas = removerFazenda(aux->fazendas,idfazenda);
		}
		aux = aux->prox;
	}
	return criadores;
}