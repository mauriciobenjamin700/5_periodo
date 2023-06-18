#include<stdio.h>
#include<stdlib.h>
#include"listaDinamica.h"

int main(){
    Conta * listarContas;
    int valor, valor1, n;
    
    listarContas = criarLista();
    // listarContas = inserir(listarContas);
    //listarContas = inserir_no_inicio(listarContas);
    n = listaVazia(listarContas);

    listarContas = inserir_no_final(listarContas);

    //listarContas = inserirOrdenado(listarContas);
    mostrarLista(listarContas);

    //printf("Numero da conta que deseja remover:\n");
    //scanf("%f", &valor);
    //listarContas = remover(listarContas, valor);

    //printf("Numero da conta que deseja buscar:\n");
    //scanf("%f", &valor1);
    //listarContas = buscar(listarContas, valor1);
    
    //mostrarLista(listarContas);
    liberarLista(listarContas);
    return 0;
}
