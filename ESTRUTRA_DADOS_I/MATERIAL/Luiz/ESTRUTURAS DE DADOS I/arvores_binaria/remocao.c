#include<stdio.h>
#include<stdlib.h>



typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}node;


// BUSCA UMA RAIZ PARA REMOVER DA ÁRVORE
int buscar_para_Remover(node *raiz, int k){
    if(raiz == NULL)
        return 0;
    node *ant = NULL;
    node *atual = raiz;
    while(atual != NULL){
        // A CHAVE A REMOVER FOI ENCONTRADA
        if(atual->chave == k){
            // REMOVENDO A RAIZ
            if(atual == raiz)
                raiz = remover_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remover_atual(atual);
                else{
                    ant->esq = remover_atual(atual);
                }
            return 1;
            }
        }
        // VAI CONTINUAR ANDANDO NA ÁRVORE ATÉ ENCONTRAR O 
        // NÓ A SER REMOVIDO!
        ant =  atual;
        // ANDA PARA A DIREITA
        if(k > atual->chave)
            atual = atual->dir;
        // ANDA PARA ESQUERDA
        else
            atual = atual->esq;
    }
}

node * remover_atual(node * atual){
    node *no1;
    node *no2;
    // NÃO TEM FILHO NA ESQUERDA
    // TRATA DO NÓ FOLHA E DO NÓ COM 1 FILHO
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    // PROCURA O FILHO MAIS A DIREITA DA SUB-ARVORE ESQUERDA
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // COPIA O FILHO MAIS A DIREITA NA SUB-ARVORE ESQUERDA 
    // PARA O LUGAR DO NÓ REMOVIDO
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}