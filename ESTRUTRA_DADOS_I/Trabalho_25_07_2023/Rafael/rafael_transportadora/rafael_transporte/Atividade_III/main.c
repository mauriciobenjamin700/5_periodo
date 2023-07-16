#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main(){
    Cliente *clientes = criarListaCliente();
    Rota *rotas = criarRota();
    Pilha *pilha = criarPilha();

    clientes = inserirCliente(clientes);
    printf("\n");
    clientes = inserirCliente(clientes);
    printf("\n");

    printf("\n");
    printf("\n");


    rotas = adiconarProdutos(clientes, rotas);
    rotas = adiconarProdutos(clientes, rotas);

    printf("\n");

    mostrarTodos(clientes);

    printf("\n\n\n");


    rotas = entregarFila(rotas, pilha);
    mostrarRotas(rotas);
    rotas = entregarFila(rotas, pilha);

    mostrarRotas(rotas);

    imprimirEscore();
    
}