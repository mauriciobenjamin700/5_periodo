#include "definicao.h"
#include <stdio.h>
#include <stdlib.h>


struct pessoa
{
    char nome[50];
    int idade;
    float altura;
};


//0 para liberar memoria, 1 para alocar


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


void add_pessoa(Pessoa **vetor, int tamanho)
{
    Pessoa p;


    *vetor = (Pessoa*) realloc(vetor, (tamanho+1) * sizeof(Pessoa));

    printf("\n\nNome: ");
    fflush(stdin);
    scanf ("%s", p.nome);

    // Remover o caractere de nova linha (\n) do final da string

    printf("\nIdade: ");
    fflush(stdin);
    scanf("%d", &p.idade);

    printf("\nAltura: ");
    fflush(stdin);
    scanf("%f", &p.altura);

    *vetor[tamanho] = p;

    printf("\nPessoa adicionada com sucesso!\n");
}

int buscar_pessoa(float altura, Pessoa *vetor, int tamanho)
{
    int i;


    if (tamanho>0)
    {
    for (i=0;i<tamanho;i++)
    {
        if (vetor[i].altura == altura)
        {
            return i;
        }
    }
    }

    return -1;
}

int remover_pessoa(int indice,Pessoa **vetor, int tamanho)
{
    int sinal = 0;


    if (indice < tamanho)
    {
    int i;

    //Desloca os elementos à direita da posição uma posição para a esquerda
    for (i=indice;i<tamanho-1;i++)
    {
        *vetor[i] = *vetor[i+1];
    }


    *vetor = (Pessoa*) realloc(*vetor, (tamanho-1) * sizeof(Pessoa));
    sinal = 1;
    }
    return sinal;
}

void mostrar_pessoas(Pessoa *vetor, int tamanho)
{
    int i;


    if (tamanho>0)
    {

    for (i=0;i<tamanho;i++)
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
    int i;


    // se sinal continuar igual a 0 é pq não encontrou a altura no vetor
    int sinal = 0;

    if (tamanho>0)
    {

    

    for (i=0;i<tamanho;i++)
    {
        if (vetor[i].altura == altura)
        {
        printf("\nNome: %s\nIdade: %d \nAltura: %.2f\n", vetor[i].nome,vetor[i].idade,vetor[i].altura);
        sinal = 1;
        break;
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