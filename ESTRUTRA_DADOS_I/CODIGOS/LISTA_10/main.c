#include "pessoas.c"
#include <stdio.h>
#include <stdlib.h>



int main(){

    Pessoa *lista;
    lista = criarLista();

    inserirPessoaOrdenado(lista);
    inserirPessoaOrdenado(lista);
    mostrarTodasPessoas(lista);
    inserirPessoaOrdenado(lista);

    printf("\nlista\n");
    mostrarTodasPessoas(lista);
    
    liberarMemoria(lista);
    return 0;
}