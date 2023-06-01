#include "definicao.h"
#include <stdio.h>
#include <stdlib.h>


struct pessoa
{
    char nome[50];
    int idade;
    float altura;
};

void add_pessoa(Pessoa *vetor, int tamanho)
{
    Pessoa p;
    

    vetor = (Pessoa*) realloc(vetor, tamanho+1 * sizeof(Pessoa));

    printf("\nNome: ");
    fflush(stdin);
    scanf ("%s", p.nome);

    // Remover o caractere de nova linha (\n) do final da string

    printf("\nIdade: ");
    fflush(stdin);
    scanf("%d", &p.idade);

    printf("\nAltura: ");
    fflush(stdin);
    scanf("%f", &p.altura);

    vetor[tamanho] = p;
}

int buscar_pessoa(float altura, Pessoa *vetor, int tamanho)
{
    int i;
    
    for (i=0;i<tamanho;i++)
    {
        if (vetor[i].altura == altura)
        {
            return i;
        }
    }

    return -1;
}

int remover_pessoa(int indice, Pessoa *vetor, int tamanho)
{
    int sinal = 0;

    if (indice < tamanho)
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

void mostrar_pessoas(int tamanho, Pessoa *vetor)
{
    int i;

    for (i=0;i<tamanho;i++)
    {
        printf("\nNome: %s\nIdade: %d \nAltura: %.2f\n", vetor[i].nome,vetor[i].idade,vetor[i].altura);
    }

}

void mostrar_pessoa(float altura, Pessoa *vetor, int tamanho)
{
    int i;

    // se sinal continuar igual a 0 é pq não encontrou a altura no vetor
    int sinal = 0;

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