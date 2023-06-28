#include <stdio.h>
#include <stdlib.h>
//programando seu futuro, aula 243, lista simplesmente encadeada

typedef struct no
{
    int valor;
    struct no *proximo;
}No;

void inserirInicio(No **lista, int num)
{
    No* novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

void inserirFim(No **lista, int num)
{
    No* novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

int main(void)
{

    return 0;
}