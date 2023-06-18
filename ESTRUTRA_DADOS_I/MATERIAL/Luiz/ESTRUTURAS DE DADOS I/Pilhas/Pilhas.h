#include<stdio.h>
#include<stdlib.h>

typedef struct conta Conta;
typedef struct pilha Pilha;

Pilha * criarPilha();
Pilha * inserirPilha(Pilha *p);
Pilha * removerPilha(Pilha *p);
int pilhaVazia(Pilha *p);
void liberarPilha(Pilha *p);
void mostrarTopoPilha(Pilha *p);
void mostrarTodaPilha(Pilha *p);