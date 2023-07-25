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
        printf("%d\n", aux->id);
        printf("%s\n", aux->nome);
        printf("%.2f\n", aux->patrimonio);
        
        if(aux->fazendas != NULL)
        {
            mostrarFazenda(aux->fazendas);
        }
        
    }
}

Criador *removerCriador(Criador *criadores, int id)
{
    Criador *aux;
    aux = criadores;
    for (aux = criadores; aux != NULL && aux->id != id; aux = aux->prox)
    {

    if (aux != NULL)
    {
        if (aux->fazendas == NULL)
        {
            if (aux->ant != NULL)
            {
                aux->ant->prox = aux->prox;
            }
            else
            {
                criadores = aux->prox;
            }

            if (aux->prox != NULL)
            {
                aux->prox->ant = aux->ant;
            }

            if (aux->ant == NULL && aux->prox == NULL)
            {
                criadores = NULL;
            }

            free(aux);
        }
        else
        {
            printf("\n\nremovido com sucesso");
        }
    }
    }

    return criadores;
}


int buscarCriador(Criador *criadores)
{
    Criador *aux;
    

    int id;

    printf("\n\nID do Criador: ");
    setbuf(stdin,NULL);
    scanf("%d", &id);

    for (aux = criadores; aux != NULL && aux->id != id; aux = aux->prox)
    {

        if (aux != NULL)
        {
            printf("%d", id);
        }
        else
        {
            return -1;
        }
    }
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