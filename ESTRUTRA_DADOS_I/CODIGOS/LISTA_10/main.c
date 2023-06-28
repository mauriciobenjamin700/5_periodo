#include "pessoas.h"
#include <stdio.h>
#include <stdlib.h>



int main(){

    Pessoa *lista;
    lista = criarLista(lista);

    lista = inserirPessoaOrdenado(lista);
    lista = inserirPessoaOrdenado(lista);
    mostrarTodasPessoas(lista);
    lista = inserirPessoaOrdenado(lista);

    printf("\nlista\n");
    mostrarTodasPessoas(lista);
    
    liberarMemoria(lista);
    return 0;
}