#include<stdio.h>
#include<stdlib.h>



typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}node;



node* busca(node *r, int k) {
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
       return busca (r->esq, k);
    else
       return busca (r->dir, k);
}



// Recebe uma árvore de busca não vazia r.
// Remove a raiz da árvore e rearranja a
// árvore de modo que ela continue sendo
// de busca. Devolve o endereço da nova
// raiz.

node* removeraiz(node *r){  
    node *p;
    node *q;
    if (r->esq == NULL) {
       q = r->dir;
       free (r);
       return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
       p = q; q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é o pai de q
    if (p != r) {
       p->dir = q->esq;
       q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}