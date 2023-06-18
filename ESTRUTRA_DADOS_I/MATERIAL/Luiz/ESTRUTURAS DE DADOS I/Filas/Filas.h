#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct conta Conta;
typedef struct fila Fila;

Fila* fila_cria();
Fila* fila_insereFila(Fila* fila);
Fila* fila_retiraFila(Fila* fila);
int fila_vazia (Fila* fila);
void LiberarFila (Fila* fila);
void mostrar_inicio(Fila *fila);
void mostrar_fim(Fila *fila);
void mostrar_todos_elementos_fila(Fila *fila);