#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

typedef struct transportadora Transportadora;
 
struct cliente 
{
    char nome[30];
    char cpf[11];
    char cep[8]; // atraves do cep conseguimos chegar em regioes especificas
    char bairro[30], rua[30];
    int numero_casa;
    char telefone[20];
    char email[30];

};
struct rota
{
    Cliente* fila_entrega;
}