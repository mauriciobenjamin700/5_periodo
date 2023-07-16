#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

//tavez o uso de uma váriavel global para contar quantos dados produtos existem para gerar os ID automaticamente seja interessante

struct produto
{
    int id;
    char nome[30];
    Produto* prox;//acessa todos os produtos do cliente
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
    Produto* produtos; //aponta para os produtos do cliente
    Cliente* prox;// acessa todos os clientes

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
    Cliente* filaT1; // dessa forma garantimos entregar todos os itens de um cliente, após isso iremos para o proximo;
    Cliente* pilhaT2; //poderá realizar até 3 tentativas 
    Cliente* pilhaT3;

    Cliente* filaDevolucao;

    //talvez considerar ter mais de uma rota e apontar para a proxima rota -> "(por  ser  uma  transportadora  de  pequeno porte, épermitido apenas uma rota de entrega por vez, mas podendo ser feitas quantas  rotas  for  necessário)."
    
};

struct transportadora
{
    float score;
    Rota rotaAtiva;
};

