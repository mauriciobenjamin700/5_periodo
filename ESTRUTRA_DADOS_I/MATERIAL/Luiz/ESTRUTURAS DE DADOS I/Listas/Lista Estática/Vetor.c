#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct conta{
    float saldo;
    int numeroconta;
    char titular;
};

Conta * criarListaEstatica(int tamanho){
    Conta * ListarContas;
    ListarContas = (Conta*) calloc(tamanho, sizeof(Conta));
    return ListarContas;
}

void inserirElemento(Conta * ListarContas,int pos, int tamanho){
    float saldo;
    int numeroconta;
    char titular;

    scanf("%f", &saldo);
    scanf("%d", &numeroconta);
    scanf("%s", &titular);
    for(int i=0; i < tamanho; i++){
        if(pos > 0 && pos < tamanho){
            ListarContas[pos].saldo = saldo;
            ListarContas[pos].numeroconta = numeroconta;
            ListarContas[pos].titular = titular;
        }
    }

}

void removerElemento(Conta * ListarContas, int tamanho){ // remover pelo "numero conta"
    int Nconta;
    scanf("%d",&Nconta);
    for(int i=0; i < tamanho; i++){
        if(ListarContas->numeroconta == Nconta){
            remove(Nconta);
        }
        
    }
} 

int buscarElemento(Conta * ListarContas, int tamanho, int num_conta){
    for(int i=0; i < tamanho; i++){
        if(ListarContas->numeroconta == num_conta){
            return 1;
        }else{
            return -1;
        }
    }
}
void mostrarElemento(Conta elemento){
    printf("Saldo:%f", elemento.saldo);
    printf("Numero da conta:%d", elemento.numeroconta);
    printf("Titular:%s", elemento.titular);  
}

void mostrarTodosElementos(Conta *Lista,int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("Saldo:%f", Lista[i].saldo);
        printf("Numero da conta:%d", Lista[i].numeroconta);
        printf("Titular:%s", Lista[i].titular);
    }
}
void liberarMemoria(Conta *listaContas){
    free(listaContas);
}

void mostrarSaldo(Conta * lista, int num_conta, int tamanho){
    for(int i =0; i < tamanho; i++){
        if(lista->numeroconta == num_conta){
            printf("saldo: %f", lista->saldo);
        }
    }
}

