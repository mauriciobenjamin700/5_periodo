#include <stdio.h>
#include <stdlib.h>
#include "definicao.h"

struct pessoa
{
    int id, idade;
    float altura;
    char nome[100];
};

void inserir(Pessoa* lista)
{
    int posicoes, i;
    printf("Posicao: ");
    scanf("%d", &posicoes);

    lista = (Pessoa*) calloc (posicoes+1, sizeof(Pessoa));

    for(i=0;i<posicoes;i++)
    {
        lista[i].id = i;
        scanf("%d", &lista[i].idade);
        scanf("%f", &lista[i].altura);
        scanf("%s", lista[i].nome);
    }
    lista[posicoes].id = -1;
}

void mostrarElemento(Pessoa lista)
{
    printf("\nID: %d\nNome: %s\nIdade: %d\nAltura: %.2f\n", lista.id,lista.nome,lista.idade,lista.altura);
}

void removerPessoa(Pessoa* lista)
{
    int id, tamanho;
    
    printf("\nID: ");
    scanf("%d", &id);

    int idx = buscarPessoa(id);
    //se encontrou a pessoa
    if(idx != -1)
    {
        tamanho = contarElementos(lista);
        while (idx < tamanho-1);
        {
            lista[idx] = lista[idx+1];
            idx++;
        }
        
        lista = (Pessoa*) realloc(lista, tamanho-1);
        printf("\nPessoa Removida com sucesso!");
    }
    else
    {
        printf("\nPessoa nao encontrada!");
    }

}

void mostrarTodaLista(Pessoa* lista, int tamanho)
{
    int i;
    int tamanho = contarElementos(lista);
    for(i=0;i<tamanho;i++)
    {
        mostrarElemento(lista[i]);        
        i++;
    }
    
}

int contarElementos(Pessoa* lista)
{
    int i=0;

    while (lista[i].id!= -1)
    {      
        i++;
    }

    return i;

}

void inserirOrdenado(Pessoa* lista)
{
    Pessoa aux;

    int tamanho = contarElementos(lista)
    aux.id = tamanho;
    scanf("%d", &aux.idade);
    scanf("%f", &aux.altura);
    scanf("%s", aux.nome);

    lista[tamanho] = aux;

    lista = (Pessoa*) realloc(lista, tamanho+1);

    aux.id = -1;
    lista[tamanho] = aux;
}
int buscarPessoa(Pessoa* lista)
{
    int id, i;
    printf("\nID: ");
    scanf("%d", &id);

    int tamanho = contarElementos(lista);

    for(i=0;i<tamanho;i++)
    {
        if(lista[i].id == id)
        {
            return i;
        }
    }
    return -1;
}