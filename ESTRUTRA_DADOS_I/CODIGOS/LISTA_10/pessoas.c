#include "pessoas.h"
#include <stdlib.h>
#include <stdio.h>

struct pessoa 
{
    char nome[30];
    float altura;
    int idade,id;
    struct pessoa *prox;
};


Pessoa* criarLista()
{
    Pessoa* lista;
    lista = NULL;
    return lista;
}

Pessoa *inserirPessoaInicio(Pessoa* lista)
{
    Pessoa *new = (Pessoa *) malloc(sizeof(Pessoa));

    new->id = contrarPessoasNaLista(lista);

    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s",new->nome);

    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f",&new->altura);

    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d",&new->idade);

    new->prox = lista;
    lista = new;
    lista->prox = NULL;
    return lista;
}

Pessoa* inserirPessoaOrdenado(Pessoa* lista)
{

    Pessoa* aux;
    Pessoa* new = (Pessoa*) malloc(sizeof(Pessoa));

    new->id = contrarPessoasNaLista(lista);

    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s",new->nome);

    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f",&new->altura);

    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d",&new->idade);

    if(lista == NULL || new->idade <= lista->idade)
    {
        new->prox = lista;
        lista = new;
        lista->prox = NULL;
        return lista;
    }
    else
    {
        aux = lista;

        while(aux->prox != NULL &&  new->idade > aux->idade)
        {
            aux = aux->prox;
        }

        new->prox = aux->prox;

        aux->prox = new;

    }
    return lista;
} 

Pessoa* inserirPessoaFim(Pessoa* lista){
    Pessoa *aux,*new;

    new = (Pessoa*) malloc(sizeof(Pessoa));

    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s",new->nome);

    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f",&new->altura);

    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d",&new->idade);

    new->prox = NULL;
    aux = lista;
    
    //Caso a lista esteja vazia
    if(aux == NULL)
    {
        aux = new;
    }
    else // 
    {
        while (aux != NULL)
        {
            aux = aux->prox;
        }
        aux = new;
    }

    return lista;
}
void mostrarTodasPessoas(Pessoa *lista)
{
    Pessoa* aux = lista;

    if(aux != NULL)
    {
        mostrarPessoa(*aux);
        mostrarTodasPessoas(aux->prox);
    }
}

void mostrarPessoa(Pessoa p){
    printf("ID: %d\nNome: %s\nAltura: %.2f\nIdade: %d\n\n",p.id,p.nome,p.altura,p.idade);
}

int buscarPessoa(Pessoa *lista){
    int id, i=-1;

    Pessoa* aux = lista;

    printf("\nID: ");
    setbuf(stdin,NULL);
    scanf("%d", &id);

    while (aux->prox != NULL)
    {
        i++;
        if(aux->id == id)
        {   
            mostrarPessoa(*aux);
            return i;
        }
    }
    return i;
}

void removerPessoa(Pessoa *lista)
{
    int id;
    Pessoa* aux = lista;
    Pessoa* ant;

    printf("\nID: ");
    setbuf(stdin,NULL);
    scanf("%d", &id);

    if(id == aux->id)
    {
        lista = aux->prox;
        free(aux);
    }
    else
    {
        ant = aux;
        aux = aux->prox;
        while (aux != NULL)
        {
            if(aux->id == id)
            {   
                ant->prox = aux->prox;
                free(aux);
            }
            ant = aux;
            aux = aux->prox;
        }
    }
    
}

int contrarPessoasNaLista(Pessoa *lista)
{
    Pessoa* aux = lista;

    if(aux != NULL)
    {
        return 1 + contrarPessoasNaLista(aux->prox);
    }
    return 0;
}

void liberarMemoria(Pessoa *lista)
{
    if(lista != NULL)
    {
        liberarMemoria(lista->prox);
        free(lista);
    }
}