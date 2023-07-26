#include <stdio.h>
#include <stdlib.h>
#include "criador.h"
#include "fazenda.h"

struct criador
{
    int id;
    char nome[100];
    Fazenda *fazendas;
    float patrimonio;

    Criador *prox;
    Criador *ant;
};

Criador *criarListaDuplaCriadores()
{
    return NULL;
}

Criador *cadastrarCriador(Criador *criadores)
{
    Criador *new, *aux;
    aux = criadores;
    new = (Criador *)malloc(sizeof(Criador));

    new->id = rand() % 100;

    printf("\n\nNome do Criador: ");
    setbuf(stdin, NULL);
    scanf("%s", new->nome);

    printf("\n\nID do criador: %d\n", new->id);

    new->patrimonio = 0;

    new->fazendas = NULL;

    new->prox = NULL;
    new->ant = NULL;

    if (criadores == NULL)
    {
        return new;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
        aux->prox = new;
        new->ant = aux;
    }

    return criadores;
}

void mostrarTodos(Criador *criadores)
{
    Criador *aux;
    

    for (aux = criadores; aux != NULL; aux = aux->prox)
    {
        mostarCriador(aux);
        
        if(aux->fazendas != NULL)
        {
            mostrarFazenda(aux->fazendas);
        }
        
    }
}

void mostarCriador(Criador* criador)
{
    if(criador!= NULL)
    {
        printf("\n\n--------------------CRIADOR--------------------");
        printf("\n\n%d\n", criador->id);
        printf("%s\n", criador->nome);
        printf("%.2f\n", criador->patrimonio);
        printf("-----------------------------------");
    }
    else
    {
        printf("\n\nCRIADOR NAO ENCONTRADO!");
    }
}


void removerCriador(Criador** criadores)
{   

    Criador* aux =  buscarCriador(*criadores);
    Criador* temp;

    //se achei algum criador
    if (aux != NULL)
    {   
        //se esse criador nao tiver uma fazenda
        if (aux->fazendas == NULL)
        {
            //se ele for o primeiro da lista
            if (aux->ant == NULL)
            {
                if(aux->prox == NULL)
                {
                    free(aux);
                    *criadores=NULL;
                }
                else
                {
                    //aux->prox->ant
                    temp = aux;
                    aux->prox->ant = NULL;
                    *criadores = aux->prox;
                    free(temp);
                }
                
            }
            //caso ele esteja o ultimo
            else if (aux->prox == NULL)
            {
                aux->ant->prox = NULL;
                free(aux);
            }
            
            else
            {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
            }
        }
        else
        {
            printf("\n\nCRIADOR POSSUI FAZENDA\nNAO PODE REMOVER!");
        }
    }
    else
    printf("\n\nCRIADOR NAO ENCONTRADO!");

}


Criador* buscarCriador(Criador *criadores)
{
    Criador *aux;
    

    int id;

    printf("\n\nID do Criador: ");
    setbuf(stdin,NULL);
    scanf("%d", &id);

    for (aux = criadores; aux != NULL ; aux = aux->prox)
    {

        if (aux->id == id)
        {
            return aux; 
        }
    }

    return NULL;

    return 0;
}

void liberarMemoria(Criador *criadores)
{
    if (criadores != NULL)
    {
        liberarMemoria(criadores->prox);
        // liberarMemoriaCircular(criadores->fazendas);
        free(criadores);
    }
}