#include <stdio.h>
#include "tad.h"

int menu();

int main(void)
{
    int opc;

    Transportadora* t;

    t = criarTranspotadora();

    do
    {   
        opc = menu();
        switch (opc)
        {

        case 11:

            cadastrarCliente(&t->listaClientes); //ok
            break;
        
        case 12:
            
            mostrarCliente(buscarCliente(t->listaClientes)); //ok
            break;


        case 13:
            
            removerCliente(&t->listaClientes); //ok
            break;

        case 21:
            ativarRota(t); //ok
            break;

        case 22:
            clienteRota(t); //ok (caso n haja uma rota, n permitir adicionar cliente)
            break;

        case 23:
            produtoCliente(t); //ok (caso n haja um cliente, n permitir adicionar produto)
            break;
        
        case 24:
            mostrarFilaEntrega(t); //ok
            break;
        
        case 25:
            concluirEntrega(t); 
            break;
        
        case 26:
            t = concluirRota(t); //ok (a rota nao pode ser encerrada se ela não existir, tratar isso)
            break;
        case 31:
            imprimirEscore(t); //o importante que é o score funciona, as gracinhas n3
            break;

        case 32:
            mostrarTClientes(t->listaClientes);
            break;

        default:
            break;

        }


    } while (opc != 0);
    
    printf("\n\nSISTEMA ENCERRADO...");
    
    return 0;
}

int menu()
{
    int opc;

    printf("\n\n----------MENU----------");
    printf("\n\n1 - Cliente\n2 - Rota\n3 - Transportadora\n4 - Sair\nOPC: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        printf("----------CLIENTE----------");
        printf("\n\n1 - Cadastrar\n2 - Buscar\n3 - Remover\n4 - Voltar\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 11;
        
        else if(opc==2)
            return 12; 

        else if(opc==3)
            return 13; 
        
        else if(opc==4)
            return -1; 

        else return 0;       
        break;

    case 2:
        printf("----------ROTA----------");
        printf("\n\n1 - Nova Rota\n2 - Adicionar Cliente a fila de entrega\n3 - Adicionar produto para o cliente\n4 - Mostrar fila de entrega\n5 - Concluir entrega\n6 - Concluir Rota\n7 - Voltar\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 21;
        
        else if(opc==2)
            return 22; 

        else if(opc==3)
            return 23;

        else if(opc==4)
            return 24;

        else if(opc==5)
            return 25;

        else if(opc==6)
            return 26;

        else if(opc==7)
            return -1; 

        else return 0;       
        break;

    case 3:
        printf("----------TRANSPORTADORA----------");
        printf("\n\n1 - Mostrar desempenho da Transportadora\n2 - Mostrar todos os clientes\n3 - Voltar\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 31;
        
        else if(opc==2)
            return 32; 
        
        else if(opc==3)
            return 33;

        else if(opc==3)
            return -1; 

        else return 0;       
        break;

    default:
        return 0;
        break;
    }

}
