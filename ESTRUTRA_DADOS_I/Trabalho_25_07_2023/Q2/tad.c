#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

// tavez o uso de uma váriavel global para contar quantos dados produtos existem para gerar os ID automaticamente seja interessante

struct produto
{
    int id;
    char nome[30];
    Produto *prox; // acessa todos os produtos do cliente
};

struct cliente
{
    char nome[30];
    char cpf[11];
    char cep[8]; // atraves do cep conseguimos chegar em regioes especificas
    char bairro[30], rua[30];
    int numero_casa;
    char telefone[20];
    char email[30];
    char referencia[50];
    Produto *produtos; // aponta para os produtos do cliente
    Cliente *prox;     // acessa todos os clientes
};

struct rota
{
    /*
    Rota consiste em organizar as tentativas de entrega
    Existe uma fila de entrega
        se a entrega falhar
            direciona o cliente para a pilha de segunda chance
                se falhar denovo
                    direciona o cliente para a ultima chance
                        se falhar novamente
                            vai para fila de devolução (-0.8)
                        se conseguir (2 pt)
                            cliente removido da rota
                se não falhar, entrega realizada com sucesso (3 pt)
                    cliente removido da rota
        se não falhar, entrega realizada com sucesso (5 pt)
            cliente removido da rota

    */
    Cliente *filaT1;  // dessa forma garantimos entregar todos os itens de um cliente, após isso iremos para o proximo;
    Cliente *pilhaT2; // poderá realizar até 3 tentativas
    Cliente *pilhaT3;

    Cliente *filaDevolucao;

    // talvez considerar ter mais de uma rota e apontar para a proxima rota -> "(por  ser  uma  transportadora  de  pequeno porte, épermitido apenas uma rota de entrega por vez, mas podendo ser feitas quantas  rotas  for  necessário)."

    int tentativa;
};

struct transportadora
{
    float score;
    Rota* rotaAtiva;
    Cliente* listaClientes;
};

Cliente *criarListaCliente()
{
    return NULL;
}

Cliente *inserirCliente(Cliente *clientes)
{
    // usa lista encadeada simples
    Cliente *new = (Cliente *)malloc(sizeof(Cliente)), *aux = clientes;

    new->produtos = NULL;

    printf("Nome do cliente: ");
    scanf(" %s", new->nome);

    printf("CEP: ");
    scanf("%d", &new->cep);
    printf("Bairro: ");
    scanf(" %s", new->bairro);
    printf("Rua: ");
    scanf(" %s", new->rua);
    printf("Nº da casa:");
    scanf(" %d", &new->numero_casa);
    printf("Telefone: ");
    scanf("%s", &new->telefone);
    printf("Email: ");
    scanf("%s", &new->email);
    printf("Referencia: ");
    scanf("%s", &new->referencia);

    new->prox = NULL;

    if (clientes == NULL)
    {
        return new;
    }
    else
    {
        aux = clientes;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = new;
        return clientes;
    }
}

Cliente *liberarClientes(Cliente *clientes)
{
    Cliente *temp = clientes;
    while (temp != NULL)
    {
        clientes = temp->prox; // clientes é atualizada para o próximo nó na lista, ou seja, temp->prox.
        free(temp);            // A memória alocada para o nó atual, representada por temp, é liberada com a função free.
        temp = clientes;       // A variável temp é atualizada para o próximo nó, ou seja, clientes.
    }
    return NULL; // O endereço cliente não aponta para nenhum endereço da memória válido.
}

Cliente *buscarCliente(Cliente *clientes, char cpf[])
{
    Cliente *aux = clientes;

    while (aux != NULL)
    {
        if (compara_str(cpf, aux->cpf))
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

Cliente* removerCliente(Cliente *clientes, char cpf[])
{
    Cliente* c = buscarCliente(clientes, cpf);
    
    if(c != NULL)
    {
        
    }
}

int compara_str(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '/0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

Rota *criarRota()
{
    return NULL;
}

Rota *adicionarProdutos(Cliente *clientes, Rota *rotas)
{
    Produto *newProduto = (Produto *)malloc(sizeof(Produto));
    Cliente *aux;

    printf("CPF cliente: ");
    setbuf(stdin, NULL);
    scanf("%s", aux->cpf);
    aux = buscarCliente(clientes, aux->cpf);
    if (aux != NULL)
    {
        newProduto->id = rand() % 100 + 10;
        printf("Produto: ");
        setbuf(stdin, NULL);
        scanf("%s", &newProduto->nome);
        if (aux->produtos)
        {
            newProduto->prox = aux->produtos;
            aux->produtos = newProduto;
        }
        else
        {
            newProduto->prox = NULL;
            aux->produtos = newProduto;
            rotas = inserirRota(rotas, aux);
        }
    }
    return rotas;
}

Transportadora *EntregaConcluida(Transportadora *t, char cpf[])
{
    if(t->rotaAtiva->tentativa == 1)
    {
        Rota *aux = t->rotaAtiva;

        while (compara_str(aux->filaT1->cpf, cpf) != 1)
        {
            aux = aux->filaT1->prox;
        }
        //remover da fila de entrega o cliente que recebeu
        t->score += 5;

        return t;
    }
    else if(t->rotaAtiva->tentativa == 2)
    {
        printf("Implementar depois!");
    }
    else if(t->rotaAtiva->tentativa == 3)
    {
        printf("Implementar depois!");
    }
    else
    {
        Rota *aux = t->rotaAtiva;

        while (compara_str(aux->filaDevolucao->cpf, cpf) != 1)
        {
            aux = aux->filaDevolucao->prox;
        }
        //remover da fila de entrega o cliente que recebeu
        t->score -= 0.8;

        return t;
    }
    
}

Transportadora *EntregaFracassada(Transportadora *t, char cpf[], float score)
{
    Rota *rota = t->rotaAtiva;
    Cliente *c = buscarCliente(t->rotaAtiva->filaT1, cpf);

    Cliente* pilhaT2;

    // caso a pilha de devoluções referentes a segunda tentativa esteja vazia
    if (rota->pilhaT2 == NULL)
    {
        // o cliente sera adicionado na pilha de devolução como primeiro elemento
        rota->pilhaT2 = c;
    }
    else
    {
        //caso não seja o primeiro elemento, devemos adicionar no fim pois é uma pilha
        pilhaT2 = rota->pilhaT2;
        while ( pilhaT2->prox != NULL) 
        {
            pilhaT2 = pilhaT2->prox;
        }
        pilhaT2->prox = c;
        
    }

    return t;
}
