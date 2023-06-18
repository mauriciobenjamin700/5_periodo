#include<stdio.h>
#include<stdlib.h>
#include"Transportadora.h"

struct cliente{
    char nome;
    int telefone;
    char cidade;
    char endereco;
    struct cliente *prox;
};

struct rotas{
    char cidade;
    int numero;
    char endereco;
    struct rotas *prox;
};

struct fila{
    struct rotas *inicio, *fim;
};


Cliente *criarListadeCliente(){
    return NULL;
}


Cliente *cadastrarCliente(Cliente *clientes){
    Cliente *aux;
    Cliente *novoCliente = (Cliente*)malloc(sizeof(Cliente));
    printf("Cadastro de um cliente:\n");
    printf("Nome: ");
    scanf("%s", novoCliente->nome);
    printf("Telefone: ");
    scanf("%d", &novoCliente->telefone);
    printf("Cidade: ");
    scanf("%s", novoCliente->cidade);
    printf("endereco: ");
    scanf("%s", novoCliente->endereco);

    novoCliente->prox = NULL;
    if(clientes == NULL)
        return novoCliente;
    aux = clientes;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novoCliente;
    return clientes;
}

void liberarListadeClientes(Cliente *clientes){
    Cliente *aux;
    while(clientes != NULL){
        aux = clientes;
        clientes = clientes->prox;
        free(aux);
    }
    free(clientes);
}

void mostrarListadeClientes(Cliente *clientes){
    Cliente *aux = clientes;
    printf("Lista de clientes:\n");
    while(aux != NULL){
    printf("Nome: %s\n", aux->nome);
    printf("Telefone: %d\n", aux->telefone);
    printf("Cidade: %s\n", aux->cidade);
    printf("Endereco: %s\n", aux->endereco);
    aux = aux->prox;
    }
    printf("Nao printa\n");
}

Fila * CriarFiladeRotas(Fila * fila){
    fila->fim = NULL; 
    fila->inicio = NULL;
    return fila;
}

Fila *fila_insereRotas(Fila * fila){
     Rotas *novaRota = (Rotas*)malloc(sizeof(Rotas));
     printf("Cidade\n");
     scanf("%s",novaRota->cidade);
     printf("Numero\n");
     scanf("%d",&novaRota->numero);
     printf("Endereco\n");
     scanf("%s",novaRota->endereco);
     novaRota->prox = NULL;
     if(fila->fim == NULL){
          fila->inicio = novaRota;
     }else{
          fila->fim->prox = novaRota;
     }
     fila->fim = novaRota;
     return fila;
}

Fila* fila_RemoverRota(Fila* fila){
     if(fila == NULL)
          return 0;
     if(fila->inicio == NULL)
          return 0;
     Rotas * aux = fila->inicio;
     fila->inicio = fila->inicio->prox;
     if(fila->inicio == NULL)
          fila->fim = NULL;
     free(aux);
     return fila;
}
