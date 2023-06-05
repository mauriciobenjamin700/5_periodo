#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"pessoa.h"

int main (){
    
    Pessoa* vet;
    float altura;
    int idade;
    char nome[15];

    vet = createVet();

    printf("Nome: ");
    scanf("%s", nome);

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Altura: ");
    scanf("%f",&altura);

    int tamanho = 0;
    vet = adicionarPessoa(vet,&tamanho, nome, idade, altura);
    vet = adicionarPessoa(vet,&tamanho, "Carlos", 17, 2.0);
    vet = adicionarPessoa(vet,&tamanho, "Julia", 20, 1.65);
    
    // printf("\ntamanho na main: %i", tamanho);
    imprimePessoas(vet, tamanho);
    
    mostrarPessoaAltura(vet, tamanho, 1.5);
    
    vet = limpaMemoria(vet);

    return 0;
}