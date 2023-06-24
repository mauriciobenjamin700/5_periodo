#include <stdio.h>
#include <stdlib.h>
#include "listaestatica.h"

int main(int argc, char const *argv[])
{
	int pos = 0, tam = 10;
	Conta *lista = criarListaContasEstatica(tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	mostrarTodosElementos(lista, pos);
	return 0;
}