#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

float escore = 0.0;
float cont = 0.0;
int id = 0;

struct cliente{
    int id;
    char nome[100];
    Endereco local;
    Produto *produtos;
    struct cliente *prox;
};

struct endereco{
    int cep;
	char cidade[50], estado[2], logradouro[50];
};

struct rota{
    Cliente *clientes;
    Produto *produtos;
    struct rota *prox;
};

struct produto{
    int id;
    char nome[50];
    Produto *prox;
};

struct devolucao{
    Rota *rota;
    struct devolucao *prox;
};

struct pilha{
    Cliente *clientes;
    struct pilha *prox;
};

Cliente *criarListaCliente(){
    return NULL;
}

Rota *criarRota(){
    return NULL;
}

int vazio(Cliente *clientes){ 
    if(clientes) return 1;
    return 0;
}

Cliente *inserirCliente(Cliente *clientes){
    Cliente *new = (Cliente *) malloc(sizeof(Cliente)), *aux = clientes;
	id += 1;
    new->id = id;

     new->produtos = NULL;

	printf("Nome do cliente: ");
	scanf(" %s", new->nome);

    printf("CEP: ");
	scanf("%d", &new->local.cep);
	printf("Cidade: ");
	scanf(" %s", new->local.cidade);
	printf("Sigla do estado: ");
	scanf(" %s", new->local.estado);
	printf("Logradouro: ");
	scanf(" %s", new->local.logradouro);

    new->prox = NULL;

	if(!vazio(clientes)) {
        return new;
    } 
    else if(new->local.cep <= clientes->local.cep){ 
        new->prox = clientes;
        return new;
    }else{
        while(aux->prox != NULL && aux->prox->local.cep < new->local.cep){
            aux = aux->prox; 
        }
        new->prox = aux->prox; 
        aux->prox = new; 
        return clientes;
    }
}

Cliente *liberarClientes(Cliente *clientes){
    Cliente *temp = clientes;
    while(temp){
        clientes = temp->prox; //clientes é atualizada para o próximo nó na lista, ou seja, temp->prox.
        free(temp); //A memória alocada para o nó atual, representada por temp, é liberada com a função free.
        temp = clientes; //A variável temp é atualizada para o próximo nó, ou seja, clientes.
    }
    return NULL; //O endereço cliente não aponta para nenhum endereço da memória válido.
}

Cliente *buscarCliente(Cliente *clientes, int id){ 
    Cliente *aux = clientes;

    while(aux->prox){
        if(aux->id == id) return aux;
        aux = aux->prox;
    }

    if(aux->id == id) return aux;
    return NULL;
}

void mostrarCliente(Cliente *clientes){
    Cliente *aux = clientes;

    printf("Id: %d\nNome: %s\nCidade: %s\nEstado: %s\nLogradouro: %s\nCep: %d\n\n", aux->id, aux->nome, aux->local.cidade, aux->local.estado, aux->local.logradouro, aux->local.cep);
    if(aux->produtos) {
        mostrarProduto(aux->produtos);
    }
}

void mostrarTodos(Cliente *clientes){ 
    Cliente *aux = clientes;
    while(aux != NULL){
        mostrarCliente(aux);
        aux = aux->prox;
    }
}


Rota *adiconarProdutos(Cliente *clientes, Rota *rotas){ 
    Produto *newProduto = (Produto*) malloc(sizeof(Produto));
    Cliente *aux;
    int id;

    printf("Id cliente: ");
    scanf("%d", &id);
    aux = buscarCliente(clientes, id);
    if(aux != NULL){ 
        newProduto->id = rand() % 100 + 10;
        printf("Produto: ");
        scanf(" %s", &newProduto->nome);
        if(aux->produtos){ 
            newProduto->prox = aux->produtos;
            aux->produtos = newProduto;
        }else{ 
            newProduto->prox = NULL;
            aux->produtos = newProduto;
            rotas = inserirRota(rotas, aux);
        }
    }
    return rotas;
}

Produto *liberarProdutos(Produto *produtos){
    Produto *aux = produtos;
    do{
        produtos = aux->prox;
        free(aux);
        aux = produtos;
    }while(aux);
    return NULL;
}

void mostrarProduto(Produto *produtos){ 
    Produto *aux = produtos;
    while(aux){
        printf("Produto: %s\nId: %d\n\n", aux->nome, aux->id);
        aux = aux->prox;
    }
}

Rota *inserirRota(Rota *rotas, Cliente *clientes){
    Rota *newRota = (Rota *) malloc(sizeof(Rota)), *aux = rotas;
    newRota->clientes = clientes;
    newRota->produtos = clientes->produtos;
    newRota->prox = NULL;

    if(!rotas){ 
        rotas = newRota;
    }else{
        while(aux->prox) aux = aux->prox;
        aux->prox = newRota; 
    }
    return rotas;
}

void mostrarRotas(Rota *rotas){
    Rota *aux = rotas;
    if(rotas){
        while(aux){
            if(aux->clientes) mostrarCliente(aux->clientes);
            if(aux->prox == NULL) break;
            aux = aux->prox;
        }
    }
}


Rota *entregarFila(Rota *rotas, Pilha *pilhas){
    // Fazer entrega na primeira rota presente na fila
    int entregou = 0;
    int op = 0;
    if(rotas != NULL){
        cont += 1;
        printf("Os produtos do cliente %s de id %d foram entregues? \n(1 - sim; 2 - nao): ", rotas->clientes->nome, rotas->clientes->id);
        scanf("%d", &entregou);

        switch (entregou){
            case 1:
                rotas = liberarRota(rotas); 
                escore += 5;
                printf("Entrega efetuada!\n");
                return rotas;
                break;
            case 2:
                inserirPilha(rotas, pilhas);
                rotas = liberarRota(rotas);
                printf("1- Segunda tentativa\n2- Terceira tentativa\n3- Nao efetuada\nOpcao: ");
                scanf("%d", &op);
                switch(op){
                    case 1:
                    // vai remover o produto na pilha 
                        removerPilha(pilhas);
                        escore += 3;
                        printf("Entrega nao efetuada!\n");
                        return rotas;
                        break;

                    case 2:
                    // vai remover o produto na pilha 
                        removerPilha(pilhas);
                        escore += 2;
                        printf("Entrega nao efetuada!\n");
                        return rotas;
                        break;

                    case 3:
                        printf("Entrega movida para a Fila de Devolução de Produtos!\n");
                        escore += 0.8;
                        break;

                    default:
                        break;
                }
                
            default:
                break;
        }
    }else{
        printf("Nenhuma rota cadastrada!\n");
        return NULL;
    }
}


void imprimirEscore(){
    printf("Total escore: %.2f\n", escore/cont);
}

Pilha *criarPilha(){
    return NULL;
}

void inserirPilha(Rota *rotas, Pilha *pilhas){

    if(!pilhas){
        Pilha *pilhas = (Pilha*)malloc(sizeof(Pilha));
        printf("Entrei1\n");
        pilhas->clientes = rotas->clientes;
        pilhas->prox = NULL;
        rotas = rotas->prox;   
    }else{
        Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
        printf("Entrei2\n");
        aux->clientes = rotas->clientes;
        aux->prox = pilhas;    
        rotas = rotas->prox;   
    } 
}

void removerPilha(Pilha *pilhas){
    Pilha *aux2, *aux = pilhas;
    if(aux){
        while (aux->prox != NULL){
            aux2 = aux;
            aux = aux->prox;
        }
        aux2 = aux->prox;
        free(aux);
    }
}

void mostrarPilha(Pilha *pilhas){
    if(pilhas->clientes) mostrarTodos(pilhas->clientes);
}


Rota *liberarRota(Rota *rotas){
    if(rotas){
        liberarProdutos(rotas->produtos);
        liberarClientes(rotas->clientes);
        return rotas->prox;
    }
    return rotas;
}

Cliente *liberarClienteRota(Cliente *clientes){
    Cliente *aux = clientes->prox;
    clientes->prox = NULL;
    return clientes;
}

Devolucao *criarFilaDevolucao(){
    return NULL;
}


Devolucao *filaDevolucao(Devolucao *devolucao, Rota *rota){
    Devolucao *newDev = (Devolucao*) malloc (sizeof(Devolucao));
    //O tempo não foi suficiente para completar :(
}