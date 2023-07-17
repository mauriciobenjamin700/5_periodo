#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux_fazenda, *cadFazenda = (Fazenda*) malloc (sizeof(Fazenda));
	cadFazenda->id_fazenda = rand() % 100 + 10;
	printf("Digite o nome da Fazenda: ");
	scanf(" %[^\n]s",cadFazenda->nome);
	cadFazenda->id_criador = id;
	printf("Valor da fazenda: ");
	scanf("%f", &cadFazenda->valor_fazenda);
	printf("Digite a cidade: ");
	scanf(" %s", cadFazenda->localizacao.cidade);
	printf("Digite o estado: ");
	scanf(" %s", cadFazenda->localizacao.estado);
	printf("Digite o logradouro: ");
	scanf(" %s", cadFazenda->localizacao.logradouro);
	printf("\n%d\n", cadFazenda->id_fazenda);

	int opcao = 0;
	while(opcao != 2)
	{
		printf("Deseja cadastrar um animal?\n1 - Sim\n2 - Nao\n");
		scanf("%d", &opcao);
		if(opcao == 1)
		{
			cadFazenda->rebanho = cadastrarAn(cadFazenda->rebanho, cadFazenda->id_fazenda);
		}
		else
		{
			break;
		}

	}
	if (fazendas == NULL){
		fazendas = cadFazenda;
		cadFazenda->prox = cadFazenda;
	}
	else{
		aux_fazenda = fazendas;
		while (aux_fazenda->prox != fazendas){
			aux_fazenda = aux_fazenda->prox;
		}
		aux_fazenda->prox = cadFazenda;
		cadFazenda->prox = fazendas;
	}
	return fazendas;

}

Fazenda *removerFazenda(Fazenda *fazendas, int id){
	printf("\nRemover fazenda \n");
	Fazenda *aux2,*aux3, *aux = fazendas;

	if (fazendas == NULL){
		return NULL;
	}

	else if (aux->id_fazenda == id){
		aux2 = aux->prox;
		while (aux->prox != fazendas){
			aux = aux->prox;
		}
		free(aux->prox);
		aux->prox = aux2;
		aux2 = fazendas;

		return aux2;
	}
	
	do{
		if (aux->prox->id_fazenda == id){
			aux2 = aux->prox;
			aux->prox = aux->prox->prox;
			free(aux2);
			return fazendas;
		} 
		
		aux = aux->prox;
	} while (aux != fazendas);
	
	return fazendas;
	
}


Fazenda *alterarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
	printf("\nAlterar fazenda \n");
	do{
		if (aux->id_fazenda == id)
		{
			aux->id_fazenda = rand() % 100 + 10;
			printf("Digite o nome da Fazenda: ");
			scanf(" %[^\n]s",aux->nome);
			printf("Valor da fazenda: ");
			scanf("%f", &aux->valor_fazenda);
			printf("Digite a cidade: ");
			scanf(" %s", aux->localizacao.cidade);
			printf("Digite o estado: ");
			scanf(" %s", aux->localizacao.estado);
			printf("Digite o logradouro: ");
			scanf(" %s", aux->localizacao.logradouro);
			return aux;
		}
		aux = aux->prox;
	}while (aux != fazendas);
	return aux;
}

int buscarFazenda(Fazenda *fazendas){
	Fazenda *aux = fazendas;
	int id = 0;
	printf("Digete o id da fazenda para busca: ");
	scanf("%d", &id);
	do {
		if (aux->id_fazenda == id){
			return aux->id_fazenda;
		}
		aux = aux->prox;
	} while(aux != fazendas);
	return 0;
}

void liberarMemoriaCircular(Fazenda *fazendas){
	Fazenda *atual = fazendas;
	Fazenda *prox = atual->prox;
	while (prox != fazendas) {
		free(atual);
		atual = prox;
		prox = atual->prox;
	}
	free(atual);
}

void mostrarFz(Fazenda *fazendas,int id){
	Fazenda *aux_fazenda = fazendas;
	int mas = 0, fem = 0;
	float peso;
		do
		{
			if (aux_fazenda->id_criador == id)
			{
				printf("Nome da fazenda: %s\n",aux_fazenda->nome);
				
				//peso = calcularpeso(aux_fazenda->rebanho,10);
				//printf("peso por arroba: %.2f",peso);
				printf("\n");
			}
			
		aux_fazenda = aux_fazenda->prox;
		}while (aux_fazenda != fazendas);
	
}