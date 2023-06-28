//lista encadeada 
#include <stdio.h>
#include <stdlib.h>
#include "encadeada.h"

struct pessoa
{
    int id, idade;
    char nome[100];
    float altura;
    // struct pessoa* prox;
    Pessoa* prox;
};
/*
void criarLista(Pessoa* lista)
{
    lista = NULL;
}
*/
Pessoa* inserirInicio(Pessoa *l)
{
    Pessoa *new = (Pessoa*) malloc (sizeof(Pessoa));

    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d", &new[0].idade);
    
    printf("\nID: ");
    setbuf(stdin,NULL);
    scanf("%d", &new->id);

    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s", new->nome);

    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f", &new->altura);
    
    new->prox = l;
    l = new;

    return l;
}

void mostrarPessoa(Pessoa p)
{
    printf("\nID: %d\nIdade: %d\nNome: %s\nAltura: %.2f\n", p.id,p.idade,p.nome,p.altura);
}

void mostrarTodasPessoas(Pessoa *lista)
{
    Pessoa* aux = lista;
    while(aux->prox != NULL) //aux[0].prox
    {
        mostrarPessoa(*aux); //aux[0]
    }
}




void inserirPessoaFim(Pessoa *lista)
{
    int tamanho = contrarPessoasNaLista(lista);
    //printf("\nTamanho: %d", tamanho);

    lista = (Pessoa*) realloc (lista,(tamanho+1)*sizeof(Pessoa)); //relocar o tamanho 2 para criar o novo fim de lista

    lista[tamanho].id = tamanho;
    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d", &lista[tamanho].idade);
    //printf("\nEntrou em idade: %d", lista[tamanho-1].idade);

    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f", &lista[tamanho].altura);
    //printf("\nEntrou em altura: %.2f", lista[tamanho-1].altura);

    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s", lista[tamanho].nome);
    //printf("\nEntrou em nome: %s", lista[tamanho-1].nome);

    //fim da lista
    lista[tamanho+1].id = -1;

}


void inserirPessoaOrdenado(Pessoa *lista)
{   
    Pessoa aux;
    int trocou, i, j;
    
    inserirPessoaFim(lista);
    //ordenando lista usando bubble sort
    int tamanho = contrarPessoasNaLista(lista);
    
    for ( i = 0; i < tamanho - 1; i++) {
        trocou = 0;

        for ( j = 0; j < tamanho - 1 - i; j++) {
            if ((lista[j]).idade > (lista[j + 1]).idade) 
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
                trocou = 1;
            }
        }

        if (trocou!=0) {
            // Se nenhuma troca ocorreu na passagem atual, o lista estÃ¡ ordenado
            break;
        }
    }
    
}




int contrarPessoasNaLista(Pessoa* lista, int t)
{
    // t deve receber zero
    //Pessoa* aux = lista;

    if (lista->prox != NULL)
    {      
        contrarPessoasNaLista(lista->prox, t++);
    }

    return t;

}


int buscarPessoa(Pessoa* lista)
{
    int id, i;
    printf("\nID: ");
    setbuf(stdin,NULL);
    scanf("%d", &id);

    int tamanho = contrarPessoasNaLista(lista);

    for(i=0;i<tamanho;i++)
    {
        if(lista[i].id == id)
        {
            mostrarPessoa(lista[i]);
            return i;
        }
    }
    return -1;
}

void removerPessoa(Pessoa* lista)
{
    int tamanho;

    int idx = buscarPessoa(lista);
    //se encontrou a pessoa
    if(idx != -1)
    {
        tamanho = contrarPessoasNaLista(lista);
        
        //jogando a ultima pessoa no lugar da pessoa que sera removida
        lista[idx] = lista[tamanho-1];
        //jogando o id == -1 no lugar da pessoa que estava no final
        lista[tamanho-1] = lista[tamanho];
        lista = (Pessoa*) realloc(lista, (tamanho)*sizeof(Pessoa));
        printf("\nPessoa Removida com sucesso!");
    }
    else
    {
        printf("\nPessoa nao encontrada!");
    }

}

void liberarMemoria(Pessoa *lista)
{
    free(lista);
    printf("\nMemoria liberada com sucesso!");
}

//implementando bubble sort
/*

void bubbleSort(Pessoa* lista, int tamanho) {

    int trocou, int aux;

    for (int i = 0; i < tamanho - 1; i++) {
        trocou = 0;

        for (int j = 0; j < tamanho - 1 - i; j++) {
            if ((lista[j]).idade > (lista[j + 1]).idade) 
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
                trocou = 1;
            }
        }

        if (!trocou) {
            // Se nenhuma troca ocorreu na passagem atual, o lista estÃ¡ ordenado
            break;
        }
    }
}
*/