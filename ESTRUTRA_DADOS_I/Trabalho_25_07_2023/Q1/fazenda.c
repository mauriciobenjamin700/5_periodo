#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco
{
	char cidade[50], estado[5], logradouro[200];
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda; // lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho;	 // ponteiro para uma lista (verificar no .h do animal que lista é)
	// ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas()
{
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas)
{
	Fazenda *cad_Fazenda = (Fazenda *)malloc(sizeof(Fazenda));
	Fazenda* ultimo;

	cad_Fazenda->id_fazenda = rand() % 100;
	int id;

	printf("\n\nId da fazenda: %d\n", cad_Fazenda->id_fazenda);

	printf("\n\nID do criador: ");
	scanf("%d", &id);

	setbuf(stdin, NULL);

	printf("\n\nNome da Fazenda: ");
	fgets(cad_Fazenda->nome, 100, stdin);

	printf("\n\nInforme o Valor da Fazenda: ");
	setbuf(stdin, NULL);
	scanf("%f", &cad_Fazenda->valor_fazenda);

	setbuf(stdin, NULL);

	printf("\n\nInforme a cidade: ");
	fgets(cad_Fazenda->localizacao.cidade, 50, stdin);

	setbuf(stdin, NULL);

	printf("\n\nInforme o estado em sigla: ");
	fgets(cad_Fazenda->localizacao.estado, 5, stdin);

	setbuf(stdin, NULL);

	printf("\n\nInforme o logradouro: ");
	fgets(cad_Fazenda->localizacao.logradouro, 200, stdin);

	setbuf(stdin, NULL);


	cad_Fazenda->prox = cad_Fazenda;

	if (fazendas == NULL)
	{
		fazendas = cad_Fazenda;
	}
	else
	{
		ultimo = fazendas;
		while (ultimo->prox != fazendas)
		{
			ultimo = ultimo->prox;
		}
		cad_Fazenda->prox = fazendas;
		ultimo->prox = cad_Fazenda;
	}
	return fazendas;
}

Fazenda *removerFazenda(Fazenda *fazendas, int id)
{

	Fazenda* aux_fazenda;
	Fazenda* aux;

	aux = fazendas;

	if (fazendas == NULL)
	{
		printf("\n\nA lista de fazendas esta vazia. Nao ha o que remover!");
		return NULL;
	}
	else if (aux->id_fazenda == id)
	{

		aux_fazenda = aux->prox;

		while (aux->prox != fazendas)
		{
			aux = aux->prox;
		}
		if (fazendas->rebanho != NULL)
		{
			printf("A fazenda possui animais cadastrados. Nao e possivel remover\n");
			return fazendas;
		}
		else
		{
			free(aux->prox);
			aux->prox = aux_fazenda;
			aux_fazenda = fazendas;

			return aux_fazenda;
		}
	}
	do
	{
		if (aux->prox->id_fazenda == id)
		{
			aux_fazenda = aux->prox;
			aux->prox = aux->prox->prox;

			if (fazendas->rebanho != NULL)
			{
				printf("A fazenda possui animais cadastrados. Nao e possivel remover\n");
				return fazendas;
			}
			else
			{
				free(aux_fazenda);
				return fazendas;
			}
		}

		aux = aux->prox;

	} while (aux != fazendas);
	return fazendas;
}

int buscarFazenda(Fazenda *fazendas)
{

	Fazenda *aux_fazenda = fazendas;
	int id;

	printf("\n\nID d0a fazenda: ");
	scanf("%d", &id);

	if (fazendas == NULL)
	{
		printf("A lista de fazendas esta vazia. Nao ha o que buscar\n");
		return 0;
	}
	do
	{
		if (aux_fazenda->id_fazenda == id)
		{
		
			printf("\n\nNome da Fazenda: %s", aux_fazenda->nome);
			return 1;
		}

		aux_fazenda = aux_fazenda->prox;

	} while (aux_fazenda != fazendas);

	printf("\n\nFazenda nao encontrada\n");
	return 0;
}

void liberarMemoriaF(Fazenda *fazendas)
{

	Fazenda *atual = fazendas;
	Fazenda *prox = atual->prox;

	while (prox != fazendas)
	{
		free(atual);
		atual = prox;
		prox = atual->prox;
	}

	free(atual);
}

void mostrarFazenda(Fazenda *fazendas)
{

	Fazenda *aux = fazendas;

	aux = fazendas;

	do
	{
		mostrar(aux);
		aux = aux->prox;
	} while (aux->prox != aux);
}

void mostrar(Fazenda* f)
{
	printf("\n\nID Fazenda: %d\n", f->id_fazenda);
	printf("\n\nID Criador: %d\n", f->id_criador);
	printf("\nNome Fazenda: %s\n", f->nome);
	printf("\nPatrimonio: %.2f", f->valor_fazenda);
	printf("\nLocalizacao: \n\tCidade: %s \n\tEstado: %s \n\tLogradouro: %s",f->localizacao.cidade, f->localizacao.estado,f->localizacao.logradouro);

}