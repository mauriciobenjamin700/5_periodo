#include<stdio.h>
#include<stdlib.h>
#include "ListaCicular.h" 

int main(){
     Conta * ListarContas;
     int a;
     int valor, oldvalue, newValue;

     ListarContas = criarLista();
      a = listaVazia(ListarContas);

     ListarContas = inserir(ListarContas);
     ListarContas = inserir(ListarContas);

     ListarContas = inserirFim(ListarContas);
     ListarContas = inserirFim(ListarContas);

     ListarContas = inserirOrdenado(ListarContas);
     ListarContas = inserirOrdenado(ListarContas);
     
     mostrarLista(ListarContas);

     printf("Numero da conta para alterar:");
     scanf("%d",&oldvalue);

     printf("Novo Numero:");
     scanf("%d",&newValue);

     ListarContas = alterar(ListarContas,oldvalue,newValue);

     printf("Numero da conta para buscar:");
     scanf("%d",&valor);

     ListarContas = buscar(ListarContas, valor);

     printf("Numero da conta para remover:");
     scanf("%d",&valor);
     ListarContas = remover(ListarContas,valor);
     
     mostrarLista(ListarContas);
     liberarLista(ListarContas);
     return 0;
}

