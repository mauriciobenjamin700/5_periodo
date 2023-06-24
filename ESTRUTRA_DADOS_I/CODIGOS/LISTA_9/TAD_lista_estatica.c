#include <stdio.h>
#include <stdlib.h>
#include "TAD_lista_estatica.h"

struct pessoa
{
    int id;
    int idade;
    float altura;
    char nome[100];
};
/*
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
*/

void inserirPessoaInicio(Pessoa *lista)
{
    Pessoa aux;
    //salvando o valor do inicio na variavel aux
    aux = lista[0];
    int tamanho = contrarPessoasNaLista(lista);

    lista = (Pessoa*) realloc (lista,tamanho+1); //relocar o tamanho para criar o novo fim de lista



    //posicao inicial recebe novo valor
    
    lista[0].id = tamanho;
    printf("\nIdade: ");
    scanf("%d", &lista[0].idade);
    printf("\nAltura: ");
    scanf("%f", &lista[0].altura);
    printf("\nNome: ");
    scanf("%s", lista[0].nome);

    //salvando o valor da primeira posicao no final
    lista[tamanho] = aux;

    //novo fim da lista
    lista[tamanho+1].id = -1;
}

void inserirPessoaFim(Pessoa *lista)
{
    int tamanho = contrarPessoasNaLista(lista);

    lista = (Pessoa*) realloc (lista,tamanho+1); //relocar o tamanho 2 para criar o novo fim de lista

    lista[tamanho].id = tamanho;
    printf("\nIdade: ");
    scanf("%d", &lista[tamanho].idade);
    printf("\nAltura: ");
    scanf("%f", &lista[tamanho].altura);
    printf("\nNome: ");
    scanf("%s", lista[tamanho].nome);

    //fim da lista
    lista[tamanho+1].id = -1;

}

/*
void inserirPessoaOrdenado(Pessoa *lista)
{

    
    inserirPessoaFim(lista);
    
    //quicksort para ordenação
    bubbleSort(lista, contrarPessoasNaLista(lista));
    
}
*/

void mostrarPessoa(Pessoa lista)
{
    printf("\nID: %d\nNome: %s\nIdade: %d\nAltura: %.2f\n", lista.id,lista.nome,lista.idade,lista.altura);
}

void mostrarTodasPessoas(Pessoa* lista)
{
    int i;
    int tamanho = contrarPessoasNaLista(lista);
    for(i=0;i<tamanho;i++)
    {
        mostrarPessoa(lista[i]);        
        i++;
    }
    
}

int contrarPessoasNaLista(Pessoa* lista)
{
    int i=0;

    while (lista[i].id!= -1)
    {      
        i++;
    }

    return i;

}


int buscarPessoa(Pessoa* lista)
{
    int id, i;
    printf("\nID: ");
    scanf("%d", &id);

    int tamanho = contrarPessoasNaLista(lista);

    for(i=0;i<tamanho;i++)
    {
        if(lista[i].id == id)
        {
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
        while (idx < tamanho-1)
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

void liberarMemoria(Pessoa *lista)
{
    free(lista);
}

//implementando quicksort


/*
void trocar(Pessoa* a, Pessoa* b) 
{
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Pessoa* vetor, int tamanho) {

    int trocou;

    for (int i = 0; i < tamanho - 1; i++) {
        trocou = 0;

        for (int j = 0; j < tamanho - 1 - i; j++) {
            if ((vetor[j]).idade > (vetor[j + 1]).idade) {
                trocar(&vetor[j], &vetor[j + 1]);
                trocou = 1;
            }
        }

        if (!trocou) {
            // Se nenhuma troca ocorreu na passagem atual, o vetor está ordenado
            break;
        }
    }
}
*/