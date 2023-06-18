#include<stdio.h>
#include<stdlib.h>

struct conta{
    float saldo;
    int num_conta;
    char titular[100];
    struct conta *prox;
};

typedef struct conta Conta;

Conta * criarLista();
Conta * inserir(Conta *l);
void mostrarLista(Conta *l);
Conta * inserir_no_final(Conta *lista);
