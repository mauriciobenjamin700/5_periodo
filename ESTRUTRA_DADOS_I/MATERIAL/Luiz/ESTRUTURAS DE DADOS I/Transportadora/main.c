#include<stdio.h>
#include<stdlib.h>
#include"Transportadora.h"

int main(){
    Cliente * listaClientes = criarListadeCliente();
    Rotas * FiladeRotas = CriarFiladeRotas(FiladeRotas);
    int opc;
    
    while(1){
        printf("---------------------------------------------------------------------\n");
        printf("1- Cadastrar cliente\n2- Lista de clientes\n3- Inserir rota\n"
               "4- Remover rota\n7- Sair\n");
        printf("---------------------------------------------------------------------\n");
        printf("Opcao:");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                listaClientes = cadastrarCliente(listaClientes);
                printf("Cliente cadastrado!\n");
            break;
            case 2:
                mostrarListadeClientes(listaClientes);
            break;
            case 3:
                fila_insereRotas(FiladeRotas);
                printf("Rota inserida!\n");
            break;
             case 4:
                fila_RemoverRota(FiladeRotas);
                printf("Rota removida!\n");
            break;
            case 7:
                liberarListadeClientes(listaClientes);
                printf("Lista de clientes liberada\n");
                return 0;

            default:
                printf("Opção incorreta! Digite uma das opções do menu!\n");
            break;
        }

    }

    return 0;
}

