#include <stdio.h>
#include <stdlib.h>
#include "fazenda.h"
#include "animal.h"

struct animal
{
    int id_animal, id_fazenda;
    char sexo;  // M ou F
    float peso; // em KG
    int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca
    struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais()
{
    return NULL;
}

Animal *cadastrar_animal(Animal *rebanho)
{
    Animal *novo = (Animal *)malloc(sizeof(Animal));
    int id_animal, id_fazenda, status;
    float peso;
    char sexo;

    if (novo)
    {

        printf("\n\nDigite o id do animal\n");
        scanf("%d", &id_animal);
        printf("\n\nDigite o id da fazenda\n");
        scanf("%d", &id_fazenda);
        printf("\n\nDigite o peso do animal em Kg\n");
        scanf("%f", &peso);
        printf("\n\ndigite o status do animal\n\t1 - Nascimento na propria fazenda\n\t2 - venda\n\t3 - troca\n");
        scanf("%d", &status);
        printf("\n\ndigite o sexo do anima M ou F\n");
        setbuf(stdin, NULL);
        scanf("%c", &sexo);

        novo->id_animal = id_animal;
        novo->id_fazenda = id_fazenda;
        novo->peso = peso;
        novo->sexo = sexo;
        novo->status = status;
        novo->prox = rebanho;
        rebanho = novo;
    }
    else
        printf("Erro ao alocar memoria");

    return rebanho;
}

// obervar para atualizar o status do animal na fazenda de destino
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal)
{
    // Criar uma variável auxiliar para armazenar a lista de animais da fazenda de origem
    Animal *aux;

    aux = origem->rebanho;

    // Procurar o animal com o ID especificado na lista de animais da fazenda de origem
    while (aux != NULL)
    {
        if (aux->id_animal == id_animal)
        {
            // Remover o animal da fazenda de origem
            origem->rebanho = remover_animal(origem, id_animal);
            // Cadastrar o animal na fazenda de destino
            destino->rebanho = cadastrar_animal(destino->rebanho);
            // Liberar a memória da fazenda de origem temporária
            liberar_memoria(aux);
            // Retornar a fazenda de destino com o novo animal cadastrado
            return destino->rebanho;
        }
        aux = aux->prox;
    }

    // Se o animal não foi encontrado na fazenda de origem, imprimir uma mensagem de erro
    printf("\n\nAnimal com o ID %d nao encontrado na fazenda de origem.\n", id_animal);

    return destino->rebanho; // Retorna a fazenda de destino sem alterações
}

Animal *remover_animal(Fazenda *fazenda, int id_animal)
{
    Animal* aux;
    Animal* remover = NULL;

    // Verifica se a lista de animais da fazenda não está vazia
    if (fazenda->rebanho)
    {
        // Verifica se o animal a ser removido é o primeiro da lista
        if (fazenda->rebanho->id_animal == id_animal)
        {
            remover = fazenda->rebanho;
            fazenda->rebanho = remover->prox;
        }
        else
        {
            // Procura o animal na lista de animais da fazenda
            aux = fazenda->rebanho;
            while (aux->prox && aux->prox->id_animal != id_animal)
            {
                aux = aux->prox;
            }
            // Se o animal foi encontrado, o remove da lista
            if (aux->prox)
            {
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }

    //  caso o animal seja encontrado a memoria será alocada para ele será liberada
    if (remover)
    {
        liberar_memoria(remover);
    }

    // Retorna o ponteiro para o animal removido (ou NULL se o animal não foi encontrado)
    return remover;
}

void liberar_memoria(Animal *rebanho)
{
    free(rebanho);
}