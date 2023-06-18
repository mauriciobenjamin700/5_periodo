#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "listaDuplamenteEncadeada.h"

int main(){
    Conta * ListarContas;
    int valor,oldvalue, newValue,a;

    ListarContas = criarLista();
    //ListarContas = inserirFim(ListarContas);
    //ListarContas = inserirInicio(ListarContas);
    //ListarContas = inserirFim(ListarContas);
    //ListarContas = inserirOrdenado(ListarContas);
    a = listaVazia(ListarContas);
    ListarContas = inserirOrdenado(ListarContas);
    mostrarLista(ListarContas);
    //printf("Numero da conta que deseja remover:\n");
    //scanf("%d",&valor);
    //ListarContas = remover(ListarContas, valor);
    //printf("Numero da conta para buscar:");
    //scanf("%d",&valor);

    //ListarContas = buscar(ListarContas, valor);

    printf("Numero da conta para alterar:");
    scanf("%d",&oldvalue);

    printf("Novo Numero:");
    scanf("%d",&newValue);

    ListarContas = alterar(ListarContas,oldvalue,newValue);
    mostrarLista(ListarContas);
    liberarLista;

    return 0;
}