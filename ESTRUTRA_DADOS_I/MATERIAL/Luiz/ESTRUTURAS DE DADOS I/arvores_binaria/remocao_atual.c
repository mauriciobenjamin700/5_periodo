#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}node;


// Função de Remover
node * remover(node* no, int valor){
    if(no == NULL)
        return NULL;
    else{
        // A CHAVE A REMOVER FOI ENCONTRADA
        if(no->chave == valor){
            // REMOVE UM NÓ FOLHA
            if(no->esq == NULL && no->dir == NULL){
                free(no);
                return NULL;
            }else{
                // REMOVE UM NÓ QUE SÓ TEM 1 FILHO
                if(no->esq == NULL || no->dir == NULL){
                    node* aux;
                    // O FILHO É NA ESQUERDA
                    if(no->esq != NULL)
                        aux = no->esq;
                    // O FILHO É NA DIREITA
                    else
                        aux = no->dir;
                    free(no);
                    return aux;
                // REMOVE UM NÓ COM 2 FILHOS
                }else{
                    // PEGA O ELEMENTO MAIS A DIREITA DA SUBÁRVORE A ESQUERDA 
                    node* aux = no->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    // REALIZA A TROCA DO VALOR A SER REMOVIDO, PELO VALOR DO ELEMENTO MAIS A DIREITA 
                    no->chave = aux->chave;
                    aux->chave = valor;
                    no->esq = remover(no->esq, valor);
                    return no;
                }
            }
        // BUSCA PELA RAIZ PARA SER REMOVIDA
        }else{
            // CHAMADAS RECURSIVAS PARA ANDAR NA ARVORE
            if(valor < no->chave){
                no->esq = remover(no->esq, valor);
            }else{
                no->dir = remover(no->dir, valor);
            }
            return no;
        }
    }
}