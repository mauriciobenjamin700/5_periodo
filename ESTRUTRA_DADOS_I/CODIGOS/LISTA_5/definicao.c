#include "definicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pessoa
{
    char nome[50];
    int idade;
    float altura;
};


//0 para liberar memoria, 1 para alocar

/*
void servidor(int sinal, Pessoa **vetor)
{
    if(sinal==1)
    {
    *vetor = (Pessoa*) malloc(sizeof(Pessoa));
    }
    else
    {
        free(vetor);
    }
}
*/


Pessoa add_pessoa(char nome[], int idade, float altura)
{
    Pessoa p;

    
    strcpy(p.nome, nome);
    p.idade = idade;
    p.altura = altura;

    return p;

}

int buscar_pessoa(float altura, Pessoa *vetor, int tamanho)
{
    int i;


    if (tamanho>=0)
    {
    for (i=0;i<=tamanho;i++)
    {
        if (vetor[i].altura == altura)
        {
            return i;
        }
    }
    }

    return -1;
}

int remover_pessoa(int indice,Pessoa *vetor, int tamanho)
{
    int sinal = 0;


    if (indice <= tamanho)
    {
    int i;

    //Desloca os elementos à direita da posição uma posição para a esquerda
    for (i=indice;i<tamanho-1;i++)
    {
        vetor[i] = vetor[i+1];
    }


    vetor = (Pessoa*) realloc(vetor, (tamanho-1) * sizeof(Pessoa));
    sinal = 1;
    }
    return sinal;
}

void mostrar_pessoas(Pessoa *vetor, int tamanho)
{
    int i;


    if (tamanho>=0)
    {

    for (i=0;i<=tamanho;i++)
    {
        printf("\nNome: %s\nIdade: %d \nAltura: %.2f\n", vetor[i].nome,vetor[i].idade,vetor[i].altura);
    }
    }
    else
    {
        printf("\nNao ha pessoas cadastradas ainda!\n");
    }

}

void mostrar_pessoa(float altura, Pessoa *vetor, int tamanho)
{
    printf("\nEntrei na funcao\n");
    int i;


    // se sinal continuar igual a 0 é pq não encontrou a altura no vetor
    int sinal = 0;

    if (tamanho>=0)
    {

        printf("\nEntrei no if\n");
    
    
    for (i=0;i<=tamanho;i++)
    {
        printf("\nComecei o for\n");
        if (vetor[i].altura == altura)
        {
            printf("\nachei\n");
        printf("\nNome: %s\nIdade: %d \nAltura: %.2f\n", vetor[i].nome,vetor[i].idade,vetor[i].altura);
        sinal = 1;
        break;
        }
        else{
            printf("\nNao achei na posicao %d ", i);
        }

    }

    if (sinal != 0)
    {
        printf("\nAltura nao encontrada no vetor");
    }
    }
    else
    {
        printf("\nNao ha pessoas cadastradas ainda!\n");
    }
}