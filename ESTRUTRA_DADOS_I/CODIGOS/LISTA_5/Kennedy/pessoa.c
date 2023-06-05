#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pessoa.h"

struct Pessoa{
    char nome[15];
    int idade;
    float altura;
};

Pessoa* createVet(){
    return NULL;
}

Pessoa* adicionarPessoa(Pessoa* vet, int* tamanho, char* nome, int idade, float altura){
    Pessoa* aux;
    aux = vet;
    
    if ((*tamanho) == 0){
        aux = (Pessoa*)malloc(sizeof(Pessoa));
    }else{
        aux = (Pessoa*)realloc(aux, ((*tamanho) + 1)* sizeof(Pessoa));
    }

    strcpy(aux[(*tamanho)].nome, nome);
    aux[(*tamanho)].idade = idade;
    aux[(*tamanho)].altura = altura;
    (*tamanho)++;
    
    return aux;
}
void imprimePessoas(Pessoa* vet, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("\n\nNome: %s\nIdade: %d\nAltura: %0.2f",vet[i].nome, vet[i].idade, vet[i].altura);
    }
    
}

int buscarPessoaAltura(Pessoa* vet, int tamanho, float altura){
    int i;
    printf("\ntamanho na busca: %i\n", tamanho);
    printf("\naltura na busca: %0.2f\n", altura);
    for (i = 0; i < tamanho; i++)
    {
        if (vet[i].altura == altura){
            return i;
        }
    }
    return -1;
}

void mostrarPessoaAltura(Pessoa* vet, int tamanho, float altura){
    int endereco = buscarPessoaAltura(vet, tamanho, altura);
    if (endereco != -1)
    {
        printf("\n%s possui esta altura", vet[endereco].nome);
    
    }else
    {
        printf("\nNinguem possui esta altura");
    }

}

Pessoa* limpaMemoria(Pessoa* vet){
    free(vet);
    return NULL;
}