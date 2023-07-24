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
    char email[40];
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
    int entregasRealizadas;
    Rota* rotaAtiva;
    Cliente* listaClientes;
};

// ###################################################### CLIENTE #############################################
/*
Clentes são pessoas das quais nos fornecem seus dados, tais dados serão armazenados na transportadora para facilitar
na hora de realizar a entrega do produto para o cliente.

*/

//poderia trocar pra void
/*
Cliente *criarListaCliente()
{
    return NULL;
}
*/
void cadastrarCliente(Cliente **clientes)
{
    // usa lista encadeada simples
    Cliente* new = (Cliente *)malloc(sizeof(Cliente));
    Cliente* aux = *clientes; // Usamos *clientes para acessar a variável original

    new->produtos = NULL;

    printf("\n\nNome do cliente: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", new->nome);

    printf("\n\nCPF: ");
    setbuf(stdin,NULL);
    scanf("%s", new->cpf);

    printf("\n\nCEP: ");
    setbuf(stdin,NULL);
    scanf("%s", new->cep);

    printf("\n\nBairro: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", new->bairro);

    printf("\n\nRua: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", new->rua);

    printf("\n\nNº da casa: ");
    setbuf(stdin,NULL);
    scanf("%d", &new->numero_casa);

    printf("\n\nTelefone: ");
    setbuf(stdin,NULL);
    scanf("%s", new->telefone);
    
    printf("\n\nEmail: ");
    setbuf(stdin,NULL);
    scanf("%s", new->email);

    printf("\n\nReferencia: ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", new->referencia);

    new->prox = NULL;

    if (*clientes == NULL)
    {
        *clientes = new;

    }
    else
    {
        aux = *clientes;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = new;

    }
}

Cliente *buscarCliente(Cliente *clientes)
{
    char cpf[11];
    Cliente *aux = clientes;

    printf("\n\nCPF do cliente: ");
    setbuf(stdin,NULL);
    scanf("%s", cpf);
    
    while (aux != NULL)
    {
        if (compara_str(cpf, aux->cpf))
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

void mostrarCliente(Cliente* c)
{
    if(c!= NULL)
    {
        printf("\n\n----------------------------------------");
        printf("\n\nNome do cliente: %s", c->nome);

        printf("\n\nCEP: %s", c->cep);

        printf("\n\nBairro: %s", c->bairro);

        printf("\n\nRua: %s", c->rua);

        printf("\n\nNº da casa: %d", c->numero_casa);

        printf("\n\nTelefone: %s", c->telefone);
        
        printf("\n\nEmail: %s", c->email);

        printf("\n\nReferencia: %s",c->referencia);
    }
    else
    {
        printf("\n\nCliente sem Cadastro!");
    }
}
    
void mostrarTClientes(Cliente* clientes)
{
    Cliente* aux = clientes;

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            mostrarCliente(aux);
            aux = aux->prox;
        }
    
    }
    else
    {
        printf("\n\nNao ha clientes cadastrados");
    }
}

void removerCliente(Cliente *clientes)
{
    //falta implementar
    Cliente* c = buscarCliente(clientes);
    Cliente* anterior;
    
    if(c != NULL)
    {
        anterior = clientes;

        while (anterior->prox != c)
        {
            anterior = anterior->prox;
        }

        anterior = c->prox;

        //free(c);
        printf("225\n");
        liberarProdutos(c->produtos);
        free(c);
        printf("\n\nCliente removido com sucesso!");
        
    }
    else
    {
        printf("\n\nCliente Nao encontrado!");
    }
}

void liberarCliente(Cliente *cliente){
    printf("237\n");
    liberarProdutos(cliente->produtos);
    free(cliente);

    
} // Fica por sua conta implementar isso lazi,

/* não faz sentido liberar todos os clientes de uma vez
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
*/

int compara_str(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
// #################################################### ROTA #######################################################
/*
Rotas são o percurso que o entregador deve fazer para entregar todos os produtos para seu respectivo cliente
esse percurso deve abranger toda a FILA de entrega, visitando de cliente em cliente para entregar seus produtos
caso o cliente não consiga receber o produto, deve anotar isso e ir para o próximo cliente

para uma rota existir, deve haver pelomenos um cliente
antes de inciar a rota, deve-se primeiro separar todos os clientes que irão ser adicionados na rota
cada cliente pode ter N produtos
depois de uma rota ser iniciada, ela não deverá ser parada até ser concluida
Somente depois de uma rota ser completamente concluida que poderá ser iniciado outra rota
*/

Rota *criarRota()
{
    Rota* r = (Rota*) malloc (sizeof(Rota));

    r->filaT1 = NULL;
    r->pilhaT2 = NULL;
    r->pilhaT2 = NULL;
    r->pilhaT3 = NULL;
    r->filaDevolucao = NULL;
    r->tentativa = 1;

    return r;
}

void ativarRota(Transportadora* t)
{
    Transportadora* temp = t;

    if(temp->rotaAtiva == NULL)
    {
        temp->rotaAtiva = criarRota();
        printf("\n\nRota criada com sucesso!");
    }
    else
    {
        printf("\n\nJa existe uma rota em andamento!");
    }

}

void concluirRota(Transportadora* t)
{
    Transportadora* temp = t;
    Rota* r = temp->rotaAtiva;

    if(r->filaT1 == NULL && r->pilhaT2 == NULL && r->pilhaT3 == NULL && r->filaDevolucao == NULL)
    {
        free(r->filaT1);
        free(r->pilhaT2);
        free(r->pilhaT3);
        free(r->filaDevolucao);

        free(r);
        
        r = NULL;
    }
}

void clienteRota(Transportadora* t)
{
    // Cliente já cadastrado?
    Cliente* cliente = buscarCliente(t->listaClientes);
    Cliente* fila;

    if (cliente != NULL)
    {
        // Fila está vazia?
        if (t->rotaAtiva->filaT1 == NULL)
        {
            t->rotaAtiva->filaT1 = cliente;
            cliente->prox = NULL; // Garantir que o cliente adicionado seja o último da fila
            printf("\n\nCliente adicionado à fila de entrega");
        }
        else //Detalhe importante, de tal forma não é possivel tratar caso o usuário adicione o mesmo cliente duas vezes a fila, pensamos em usar um vetor de string e checar se o nome na lista ja tinha sido adicionado mas provavelmente ia ficar pesado e desnecessário para essa etapa
        {
            fila = t->rotaAtiva->filaT1;
            while (fila->prox != NULL)
            {
                fila = fila->prox;
            }
            fila->prox = cliente;
            cliente->prox = NULL; // Garantir que o cliente adicionado seja o último da fila
            printf("\n\nCliente adicionado à fila de entrega");
        }
    }
    else
    {
        printf("\n\nCliente não possui cadastro!");
    }
}

void produtoCliente();


/*
Rota *adicionarProdutos(Cliente *clientes, Rota *rotas)
{
    Produto *newProduto = (Produto *)malloc(sizeof(Produto));
    Cliente *aux;
    char cpf[11];

    printf("CPF cliente: ");
    setbuf(stdin, NULL);
    scanf("%s", cpf);
    aux = buscarCliente(clientes, cpf);
    if (aux != NULL)
    {
        newProduto->id = rand() % 100 + 10;
        printf("Produto: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", newProduto->nome);
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
}*/
//####################################################### TRANSPORTADORA ######################################3
/*
Uma transportadora é um local que recebe e envia produtos para seus respectivos donos

*/

//troquei pra void pra testar
Transportadora* criarTranspotadora()
{
    Transportadora* t = (Transportadora*) malloc(sizeof(Transportadora));

    if(t)
    {
    t->listaClientes = NULL;
    t->rotaAtiva = NULL;
    t->score = 0;
    t->entregasRealizadas = 0;
    }
    else
    {
        printf("\n\nFalha na alocação!");
    }

    return t;
  
}

void imprimirEscore(Transportadora *t)
{
    printf("----------DESEMPENHO OBTIDO----------");
    printf("\n\nEntregas Realizadas: %.2f", t->score);
    printf("\n\nScore: %.2f", t->score);
}

Transportadora *EntregaConcluida(Transportadora *t, char cpf[])
{
    if(t->rotaAtiva->tentativa == 1)
    {
        t->rotaAtiva->filaT1 = t->rotaAtiva->filaT1->prox;

        //remover da fila de entrega o cliente que recebeu
        t->score += 5;

        return t;
    }
    else if(t->rotaAtiva->tentativa == 2)
    {
        printf("Implementar depois!");
        return t;
    }
    else if(t->rotaAtiva->tentativa == 3)
    {
        printf("Implementar depois!");
        return t;
    }
    else
    {
        Cliente *aux = t->rotaAtiva->filaT1;

        while (compara_str(aux->cpf, cpf) != 1)
        {
            aux = aux->prox;
        }
        //remover da fila de entrega o cliente que recebeu
        t->score -= 0.8;

        return t;
    }
    
}

Transportadora *EntregaFracassada(Transportadora *t)
{
    Rota *rota = t->rotaAtiva;
    Cliente *c = buscarCliente(t->rotaAtiva->filaT1);

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

//######################################################PRODUTO####################################################

void liberarProdutos(Produto *produtos)
{   
    Produto* aux;
    printf("504\n");
    while(produtos != NULL)
    {   
        aux = produtos;
        produtos = produtos->prox;
        printf("510\n");
        free(aux->nome);

        free(aux);
    }

}
