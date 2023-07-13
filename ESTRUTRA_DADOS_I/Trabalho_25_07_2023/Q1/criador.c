#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

