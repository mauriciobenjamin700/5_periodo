#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"

int main(int argc, char const *argv[])
{
	Conta *lista;

	lista = criarLista();
	lista = inserirInicio(lista);
	lista = inserirInicio(lista);
	mostrarLista(lista);
	return 0;
}
