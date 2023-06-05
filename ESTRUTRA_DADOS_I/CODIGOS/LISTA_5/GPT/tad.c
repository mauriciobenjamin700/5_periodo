#include "tad.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

Pessoa *vetor = NULL;
int tamanho = 0; // Variável para armazenar o tamanho atual do vetor

Pessoa* criar_vetor()
{
    vetor = (Pessoa*) malloc(sizeof(Pessoa));
    return vetor;
}

void servidor(int sinal)
{
    if (sinal == 1)
    {
        if (vetor == NULL)
        {
            vetor = criar_vetor();
        }
        else
        {
            printf("O vetor já foi alocado.\n");
        }
    }
    else if (sinal == 0)
    {
        if (vetor != NULL)
        {
            free(vetor);
            vetor = NULL;
            tamanho = 0; // Redefine o tamanho do vetor para zero
        }
        else
        {
            printf("O vetor ainda não foi alocado.\n");
        }
    }
    else
    {
        printf("Sinal inválido.\n");
    }
}

void add_pessoa()
{
    Pessoa p;

    tamanho++;
    vetor = (Pessoa*) realloc(vetor, tamanho * sizeof(Pessoa));

    printf("\n\nNome: ");
    scanf("%s", p.nome);

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Altura: ");
    scanf("%f", &p.altura);

    vetor[tamanho-1] = p;

    printf("Pessoa adicionada com sucesso!\n");
}

int buscar_pessoa(float altura)
{
    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (vetor[i].altura == altura)
            {
                return i;
            }
        }
    }

    return -1;
}

int remover_pessoa(int indice)
{
    if (indice < tamanho)
    {
        for (int i = indice; i < tamanho-1; i++)
        {
            vetor[i] = vetor[i+1];
        }

        tamanho--;
        vetor = (Pessoa*) realloc(vetor, tamanho * sizeof(Pessoa));

        return 1;
    }

    return 0;
}

void mostrar_pessoas()
{
    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            printf("\nNome: %s\nIdade: %d\nAltura: %.2f\n", vetor[i].nome, vetor[i].idade, vetor[i].altura);
        }
    }
    else
    {
        printf("\nNao ha pessoas cadastradas ainda!\n");
    }
}

void mostrar_pessoa(float altura)
{
    if (tamanho > 0)
    {
        int sinal = 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (vetor[i].altura == altura)
            {
                printf("\nNome: %s\nIdade: %d\nAltura: %.2f\n", vetor[i].nome, vetor[i].idade, vetor[i].altura);
                sinal = 1;
                break;
            }
        }

        if (sinal == 0)
        {
            printf("\nAltura nao encontrada no vetor.\n");
        }
    }
    else
    {
        printf("\nNao ha pessoas cadastradas ainda!\n");
    }
}
