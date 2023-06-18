#include<stdio.h>
#include<stdlib.h>
#include"Pilhas.h"

int main(){
    Pilha * pilha_Conta;
    int n, opc;

    while(1){
        printf("---------------------------------------------------------------------\n");
        printf("1-Criar pilha\n2-Pilha vazia\n3-Inserir na pilha\n4-Mostrar pilha\n5-Remover pilha\n6-Mostrar topo da pilha\n7-Liberar pilha\n");
        printf("---------------------------------------------------------------------\n");
        printf("Opcao:");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                pilha_Conta = criarPilha();
                printf("Pilha criada!\n");
            break;
            case 2:
                n = pilhaVazia(pilha_Conta);
                if(n == 1){
                    printf("Pilha vazia\n");
                }else{
                    printf("Pilha não vazia\n");
                }
            break;
            case 3:
                pilha_Conta = inserirPilha(pilha_Conta);
                printf("Elemento inserido\n");
            break;
            case 4:
                mostrarTodaPilha(pilha_Conta);
            break;
            case 5:
                pilha_Conta = removerPilha(pilha_Conta);
                printf("Elemento removido!\n");
            break;
            case 6:
                mostrarTopoPilha(pilha_Conta);
            break;
            case 7:
                liberarPilha(pilha_Conta);
                printf("Pilha liberada\n");
                return 0;
    
        default:
            printf("Valores inválidos\n");
            break;
    }
    }
    return 0;
}