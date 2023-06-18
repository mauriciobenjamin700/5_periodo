#include<stdio.h>
#include<stdlib.h>
#include"listaDinamica.h"

int main(){
    Conta * listarContas;
    
    // listarContas = criarLista();
    // listarContas = inserir(listarContas);
    // listarContas = inserir(listarContas);
    // listarContas = inserir(listarContas);
    
    listarContas = inserir_no_final(listarContas);
    printf("lista: %d", listarContas->num_conta);
    return 0;
}
