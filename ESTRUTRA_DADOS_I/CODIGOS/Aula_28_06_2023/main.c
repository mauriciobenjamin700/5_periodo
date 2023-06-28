#include <stdio.h>
#include <stdlib.h>
#include "encadeada.c"

int main(void)
{
    Pessoa *p;
    p = NULL;
    //criarLista(p);
    inserirInicio(p);
    mostrarTodasPessoas(p);

    return 0;
}