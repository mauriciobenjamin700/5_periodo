#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no* proximo;
}No;

void inserir_no_inicio(No** lista, int num)
{
    No* novo = malloc(sizeof(No));

    if(novo)
    {
        

        if(*lista == NULL)
        {
            novo->valor = num;
            novo->proximo = *lista;
            *lista = novo;    
        }
    }
    else
    {
        printf("Erro ao alocar!");
    }

}

void inserir_no_fim(No** lista, int num)
{
    No* aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            
        }
    }
    else
    {
        printf("\nErro ao alocar!");
    }
    
}

int main(void)
{
    return 0;
}