typedef struct animal Animal;


Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAn(Animal *rebanho, int id);
Animal *permutasAnimais(Animal *origem, Animal *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *remover(Animal *fazenda, int id_animal);

/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/