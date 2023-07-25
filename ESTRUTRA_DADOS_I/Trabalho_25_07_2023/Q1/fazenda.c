#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco{
	char cidade[50], estado[5], logradouro[200];
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


Fazenda *cadastrarFazenda(Fazenda *fazendas){
	Fazenda *cad_Fazenda = (Fazenda*) malloc (sizeof(Fazenda));
	cad_Fazenda -> id_fazenda = rand() % 100 ;
	int id;
	printf("\n\nId da fazenda: %d\n", cad_Fazenda -> id_fazenda);

	printf("\n\nDigite o ID do criador");
	scanf("%d", &id);

	setbuf(stdin, NULL);

	
	printf("Informe o nome da Fazenda: ");
	fgets(cad_Fazenda -> nome,100,stdin);

	

	printf("Informe o Valor da Fazenda: ");
	setbuf(stdin, NULL);
	scanf("%f", &cad_Fazenda->valor_fazenda);

	setbuf(stdin, NULL);

	printf("Informe a cidade: ");
	fgets(cad_Fazenda -> localizacao.cidade, 50,stdin);

	setbuf(stdin, NULL);

	printf("Informe o estado em sigla: ");
	fgets(cad_Fazenda -> localizacao.estado, 5,stdin);

	setbuf(stdin, NULL);

	printf("Informe o logradouro: ");
	fgets(cad_Fazenda -> localizacao.logradouro, 200,stdin);

	setbuf(stdin, NULL);

	int opcao = 0;
	while (opcao != 2)
	{
		printf("Deseja cadastrar um animal?\n1 - Sim\n2 - Nao\n");
		scanf("%d", &opcao);
		if(opcao == 1)
		{
			cad_Fazenda->rebanho = cadastrar_animal(cad_Fazenda ->rebanho);//função de cadastro de animais
		} else if(opcao == 2){
			cad_Fazenda->rebanho = NULL;
			break;
		}
	}
	if(cad_Fazenda == NULL){
		printf("error ao alocar memoria!");
		return fazendas;
	}

	cad_Fazenda->prox = cad_Fazenda;

	if(fazendas == NULL){
		fazendas = cad_Fazenda;
	}
	else{
		Fazenda *ultimo = fazendas;
		while(ultimo->prox != fazendas){
			ultimo = ultimo->prox;
		}
		ultimo->prox = cad_Fazenda;
	}
	return fazendas;
}


	Fazenda *removerFazenda(Fazenda *fazendas, int id){
		
        Fazenda *aux_fazenda, *aux;
		aux = fazendas;

        if (fazendas == NULL)
		    {
			    printf("A lista de fazendas esta vazia. Nao ha o que remover\n");
			    return NULL;
		    }
        else if(aux -> id_fazenda == id){
			printf("Entrou");

            aux_fazenda = aux -> prox;

            while (aux -> prox != fazendas)
            {
                aux = aux -> prox;
            }
            if (fazendas->rebanho != NULL)
            {
                printf("A fazenda possui animais cadastrados. Nao e possivel remover\n");
				return fazendas;
            }
            else{
                free(aux -> prox);
                aux -> prox = aux_fazenda;
                aux_fazenda = fazendas;

                return aux_fazenda;
            }
        }
        do
        {
			printf("Entrou2");
            if(aux -> prox -> id_fazenda == id){
                aux_fazenda = aux -> prox;
                aux -> prox = aux -> prox -> prox;

                if (fazendas->rebanho != NULL)
                {
                    printf("A fazenda possui animais cadastrados. Nao e possivel remover\n");
                return fazendas;
            }
            else{
                free(aux_fazenda);
                return fazendas;
            }
            }

            aux = aux -> prox;

        } while (aux != fazendas);
        return fazendas;
}

int buscarFazenda(Fazenda *fazendas){

    Fazenda *aux_fazenda = fazendas;
    int id;

    printf("Informe o id da fazenda que deseja buscar: ");
    scanf("%d", &id);

    if (fazendas == NULL)
    {
        printf("A lista de fazendas esta vazia. Nao ha o que buscar\n");
        return 0;
    }

    do
    {
        if(aux_fazenda -> id_fazenda == id){
            printf("Fazenda encontrada\n");
			printf("%s", fazendas->nome);
            return 1;
        }

        aux_fazenda = aux_fazenda -> prox;

    } while (aux_fazenda != fazendas);

    printf("Fazenda nao encontrada\n");
    return 0;
}


void liberarMemoriaF(Fazenda *fazendas){

    Fazenda *atual = fazendas;
	Fazenda *prox = atual->prox;

	while (prox != fazendas){
		free(atual);
		atual = prox;
		prox = atual->prox;
	}

	free(atual);
}


void mostrarFazenda(Fazenda *fazendas){

    Fazenda *aux = fazendas;

	aux = fazendas;

    do{
		printf("%d\n", aux->id_fazenda);
		printf("%s\n", aux->nome);
		

		aux = aux->prox;
	}while(aux->prox != aux);
}