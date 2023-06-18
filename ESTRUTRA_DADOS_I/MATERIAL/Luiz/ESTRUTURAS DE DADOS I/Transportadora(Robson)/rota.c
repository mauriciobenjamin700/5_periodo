#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pontuacao.h"
#include "endereco.h"
#include "rota.h"

struct rota{
	int id_produto;
    char descricao[200];
    Endereco *remetente, *destinatario;
    struct rota *prox;
};

Rota *criarRotas(){
    return NULL;
}

Rota *inserirRota(Rota *rotas, Endereco *remetente, Endereco *destinatario, int prioridade){
    Rota *aux, *novo = (Rota*) malloc(sizeof(Rota));
    
	getchar();
    printf("Descricao: ");
    scanf("%[^\n]s", novo->descricao);
    novo->remetente = remetente;
    novo->destinatario = destinatario;
	novo->id_produto = rand() % 10000;
	novo->prox = NULL;
	
    if(!estaVaziaRotas(rotas)){
    	if(compararEnderecos(rotas->destinatario, destinatario)){
    		novo->prox = rotas->prox;
			rotas->prox = novo;
		} else {
			if(prioridade)
	    		for(aux = rotas; aux->prox && !compararEnderecos(aux->prox->destinatario, destinatario); aux = aux->prox);
	    	else
	    		for(aux = rotas; aux->prox; aux = aux->prox);
	    	
	    	if(aux->prox && aux->prox->prox)
	    		novo->prox = aux->prox->prox;
	    	else if(aux->prox)
	    		aux->prox->prox = novo;
	    	
	    	aux->prox = novo;
		}
		
    	return rotas;
	}
	
	return novo;
}

Rota *removerRota(Rota *rotas, Rota *aux){
    Rota *remover;
	
	if(!estaVaziaRotas(rotas)){
    	remover = rotas;
    	rotas = remover->prox;
    	
    	if(aux)
    		*aux = *remover;
    		
    	free(remover);
	}
	
	return rotas;
}

Rota *inserirPilhaRota(Rota *pilha, Rota *aux){
	Rota *novo = (Rota*) malloc(sizeof(Rota));
	
	*novo = *aux;
	novo->prox = pilha;
	return novo;
}

Rota *removerPilhaRota(Rota *pilha, Rota *aux){
	Rota *remover;
	
	if(!estaVaziaRotas(pilha)){
		remover = pilha;
		*aux = *remover;
		pilha = remover->prox;
		free(remover);
	}
	
	return pilha;
}

Rota * inserirFilaDevolucao(Rota * fila, Rota * aux){
    aux->prox = NULL;
    if(fila->fim == NULL){
          fila->inicio = aux;
     }else{
          fila->fim->prox = aux;
     }
     fila->fim = aux;
     return fila;
}

void mostrarRota(Rota r){
	mostrarEndereco(r.remetente, 1);
	mostrarEndereco(r.destinatario, 2);
	printf("Descricao: %s\n", r.descricao);
}

void mostrarRotas(Rota *rotas){
    Rota *aux;
    
	cabecalhoEndereco(1);
	
	for(aux = rotas; aux; aux = aux->prox)
		mostrarRota(*aux);
	
	printf("\n");
}

int estaVaziaRotas(Rota *rotas){
	if(rotas)
		return 0;
	
	return 1;
}

//void gerenciadorRotas(Rota **filaEntregas, Rota **pilhaProcessamento, Rota **filaDevolucoes, Endereco **listaEnderecos, Endereco **listaEnderecos, Endereco **listaEnderecos){
void gerenciadorRotas(Pontuacao **score, Rota **filaEntregas, Rota **pilhaProcessamento, Rota **filaDevolucoes, Endereco **listaEnderecos){
	Endereco *destinatario, *remetente;
	Rota aux;
	char nome[50];
	int opc;
	
	printf("[Menu Rotas]\n\n\n\n");
	opcoesRotas();
	scanf("%d", &opc);
	system("cls");
	
	while(opc){
		switch(opc){
			case 1:
				if(!estaVaziaRotas(*filaEntregas)){
					mostrarRotas(*filaEntregas);
					system("pause");
					system("cls");
					printf("[Menu Rotas]\n\n\n\n");
				} else
					printf("[Menu Rotas]\n\nLista Vazia.\n\n");
				
				break;
			case 2:
				if(!estaVaziaEnderecos(*listaEnderecos)){
					mostrarListaEnderecos(*listaEnderecos);
					
					do{
						printf("Nome do Remetente: ");
						scanf("%s", nome);
						remetente = buscarEnderecos(*listaEnderecos, nome, 0);
					} while(!remetente);
					
					do{
						printf("Nome do Destinatario: ");
						scanf("%s", nome);
						destinatario = buscarEnderecos(*listaEnderecos, nome, 0);
					} while(!destinatario);
					
					*filaEntregas = inserirRota(*filaEntregas, remetente, destinatario, 1);
					system("cls");
					printf("[Menu Rotas]\n\nRota Cadastrada.\n\n");
				}
				
				break;
			case 3:
				if(!estaVaziaRotas(*filaEntregas)){
					mostrarRotas(*filaEntregas);
					printf("Realizar primeira entrega? (1 - Sim/0 - Nao): ");
					scanf("%d", &opc);
					
					if(opc){
						printf("A entrega foi bem sucedida? (1 - Sim/0 - Nao): ");
						scanf("%d", &opc);
						system("cls");
						
						if(opc){
							*filaEntregas = removerRota(*filaEntregas, NULL);
							alterarEscore(score, 5);
							printf("[Menu Rotas]\n\nEntrega Concluida!\n\n");
						} else {
							*filaEntregas = removerRota(*filaEntregas, &aux);
							*pilhaProcessamento = inserirPilhaRota(*pilhaProcessamento, &aux);
							printf("[Menu Rotas]\n\nEntrega enviada para a Pilha de Processamento.\n\n");
						}
					} else {
						system("cls");
						printf("[Menu Rotas]\n\nOperacao Cancelada.\n\n");
					}
				} else {
					system("cls");
					printf("[Menu Rotas]\n\nLista Vazia.\n\n");
				}
				
				break;
			case 4:
				if(!estaVaziaRotas(*pilhaProcessamento)){
					mostrarRotas(*pilhaProcessamento);
					printf("Realizar a segunda entrega? (1 - Sim/0 - Nao): ");
					scanf("%d", &opc);
					
					if(opc){
						printf("A entrega foi bem sucedida? (1 - Sim/0 - Nao): ");
						scanf("%d", &opc);
						system("cls");
						
						if(opc){
							pilhaProcessamento = removerPilhaRota(*pilhaProcessamento, &aux);
							alterarEscore(score, 3);
							printf("[Menu Rotas]\n\nEntrega Concluida!\n\n");
						}else{
							printf("Realizar a terceira entrega? (1 - Sim/0 - Nao): ");
							scanf("%d", &opc);
					
							if(opc){
								printf("A entrega foi bem sucedida? (1 - Sim/0 - Nao): ");
								scanf("%d", &opc);
								system("cls");
						
								if(opc){
									pilhaProcessamento = removerPilhaRota(*pilhaProcessamento, &aux);
									alterarEscore(score, 2);
									printf("[Menu Rotas]\n\nEntrega Concluida!\n\n");
								}else{
									pilhaProcessamento = removerPilhaRota(*pilhaProcessamento, &aux);
									filaDevolucoes = inserirFilaDevolucao(*filaDevolucoes, &aux);
									alterarEscore(score, 0.8);
									printf("[Menu Rotas]\n\nEntrega enviada para a fila de devolução.\n\n");
								}

							}
						}
					}
					system("pause");
					system("cls");
					printf("[Menu Rotas]\n\n\n\n");
				} else
					printf("[Menu Rotas]\n\nSem entregas a processar.\n\n");
				
				break;
			case 5:
				if(!estaVaziaRotas(*filaDevolucoes)){
					mostrarRotas(*filaDevolucoes);
					system("pause");
					system("cls");
					printf("[Menu Rotas]\n\n\n\n");
				} else
					printf("[Menu Rotas]\n\nSem entregas a processar.\n\n");
					
				break;
			case 6:
				imprimirEscore(score);
				system("pause");
				system("cls");
				printf("[Menu Rotas]\n\n\n\n");
				break;
			default:
				printf("Opcao nao disponivel.");
		}
		
		opcoesRotas();
		scanf("%d", &opc);
		system("cls");
	}
}

void opcoesRotas(){
	printf("1 - Listar Rotas\n"
		   "2 - Cadastrar Rota\n"
		   "3 - Realizar Entrega\n"
		   "4 - Listar Entregas em Processamento\n"
		   "5 - Listar Entregas nao realizadas\n"
		   "6 - Mostrar Pontuacao\n"
		   "0 - Sair\n\n");
}

