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

Pessoa* iniciar()
{
    Pessoa* lista;
    int posicoes, i;
    printf("Posicao: ");
    scanf("%d", &posicoes);

    lista = (Pessoa*) calloc (posicoes+1, sizeof(Pessoa));

    for(i=0;i<posicoes;i++)
    {
        lista[i].id = i;
        printf("\nIdade: ");
        setbuf(stdin,NULL);
        scanf("%d", &lista[i].idade);
        printf("\nAltura: ");
        setbuf(stdin,NULL);
        scanf("%f", &lista[i].altura);
        printf("\nNome: ");
        setbuf(stdin,NULL);
        scanf("%s", lista[i].nome);
    }
    lista[posicoes].id = -1;

    return lista;
}


void inserirPessoaInicio(Pessoa *lista)
{
    Pessoa aux;
    //salvando o valor do inicio na variavel aux
    aux = lista[0];
    int tamanho = contrarPessoasNaLista(lista);

    lista = (Pessoa*) realloc (lista,(tamanho+1)*sizeof(Pessoa)); //relocar o tamanho para criar o novo fim de lista



    //posicao inicial recebe novo valor
    
    lista[0].id = tamanho;
    printf("\nIdade: ");
    setbuf(stdin,NULL);
    scanf("%d", &lista[0].idade);
    printf("\nAltura: ");
    setbuf(stdin,NULL);
    scanf("%f", &lista[0].altura);
    printf("\nNome: ");
    setbuf(stdin,NULL);
    scanf("%s", lista[0].nome);

    //salvando o valor da primeira posicao no final
    lista[tamanho] = aux;

    //novo fim da lista
    lista[tamanho+1].id = -1;
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
            // Se nenhuma troca ocorreu na passagem atual, o lista está ordenado
            break;
        }
    }
    
}


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
    }
    
}

int contrarPessoasNaLista(Pessoa* lista)
{
    int i=0;

    while (lista[i].id != -1)
    {      
        i++;
    }

    return i;

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
            // Se nenhuma troca ocorreu na passagem atual, o lista está ordenado
            break;
        }
    }
}
*/