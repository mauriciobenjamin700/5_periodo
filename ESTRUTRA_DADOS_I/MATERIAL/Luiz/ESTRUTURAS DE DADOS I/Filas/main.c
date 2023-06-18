#include<stdio.h>
#include<stdlib.h>
#include"Filas.h"

int main(){
    Fila * fila_Conta;
    Conta * fila_de_contas;
    int n, opc;

    while(1){
        printf("---------------------------------------------------------------------\n");
        printf("1-Criar Fila\n2-Fila Vazia\n3-Inserir na Fila\n4-Mostrar Fila\n5-Retirar Fila\n6-Inicio da Fila\n7- Fim da Fila\n 8- Liberar Fila\n");
        printf("---------------------------------------------------------------------\n");
        printf("Opcao:");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                fila_Conta = fila_cria(fila_Conta);
                printf("Fila criada!\n");
            break;
            case 2:
                n = fila_vazia (fila_Conta);
                if(n == 1){
                    printf("Fila vazia\n");
                }else{
                    printf("Fila não vazia\n");
                }
            break;
            case 3:
                fila_Conta = fila_insereFila(fila_Conta);
                printf("Elemento inserido\n");
            break;
            case 4:
                n = fila_vazia(fila_Conta);
                if(n == 1)
                    printf("Fila vazia\n");
                mostrar_todos_elementos_fila(fila_Conta);
            break;
            case 5:
                 n = fila_vazia(fila_Conta);
                if(n == 1)
                    printf("Fila vazia\n");
                fila_Conta = fila_retiraFila(fila_Conta);
                printf("Elemento removido\n");
            break;
            case 6:
                mostrar_inicio(fila_Conta);
            break;
            case 7:
                mostrar_fim(fila_Conta);
            break;
            case 8:
                LiberarFila(fila_Conta);
                printf("Fila liberada\n");
                return 0;
    
        default:
            printf("Valores inválidos\n");
            break;
        }
    }
    return 0;
}