#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include"fazenda.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais()
{
	return NULL;
}

Animal *cadastrarAn(Animal *rebanho, int id){
	Animal *animal_no = (Animal*) malloc(sizeof (Animal));
	animal_no->id_animal = rand() % 100 + 10;
	printf("\nDigite o id da fazenda: ");
	scanf("%d", &animal_no->id_fazenda);
	printf("Digite o Sexo do animal: ");
	scanf(" %c", &animal_no->sexo);
	printf("Digite o Peso do animal: ");
	scanf("%f", &animal_no->peso);
	printf("Digite o Status do animal: ");
	scanf("%d", &animal_no->status);

	animal_no->prox;
	return animal_no;
}



/*Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal){

}//obervar para atualizar o status do animal na fazenda de destino*/