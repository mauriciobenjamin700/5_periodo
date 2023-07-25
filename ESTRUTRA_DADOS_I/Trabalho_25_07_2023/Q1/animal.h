#include "fazenda.h"

typedef struct animal Animal;


Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrar_animal(Animal *rebanho);

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *remover_animal(Fazenda *fazenda, int id_animal);
void liberar_memoria(Animal *rebanho);


/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/