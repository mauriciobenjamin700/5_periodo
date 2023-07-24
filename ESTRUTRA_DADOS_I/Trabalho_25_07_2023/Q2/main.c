#include <stdio.h>
#include "tad.c"

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
            printf("\n\nCadastro Realizado com sucesso!");
            break;
        
        case 12:
            
            mostrarCliente(buscarCliente(t->listaClientes)); //ok
            break;


        case 13:
            printf("\n\nREMOVER O CADASTRO DE UM CLIENTE");
            break;

        case 21:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;

        case 22:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;

        case 23:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;
        
        case 31:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;

        case 32:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;

        case 33:
            printf("\n\nREALIZAR  CADASTRO DO CLIENTE");
            break;
        
        default:
            break;

        }


    } while (opc != 0);
    
    printf("\nSISTEMA ENCERRADO...");
    
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
        printf("\n\n1 - Cadastrar\n2 - Buscar\n3 - Remover\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 11;
        
        else if(opc==2)
            return 12; 

        else if(opc==3)
            return 13; 

        else return 0;       
        break;

    case 2:
        printf("----------ROTA----------");
        printf("\n\n1 - Cadastrar\n2 - Buscar\n3 - Remover\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 21;
        
        else if(opc==2)
            return 22; 

        else if(opc==3)
            return 23; 

        else return 0;       
        break;

    case 3:
        printf("----------TRANSPORTADORA----------");
        printf("\n\n1 - Cadastrar\n2 - Buscar\n3 - Remover\n\nOPC: ");
        scanf("%d", &opc);

        if(opc==1)
            return 31;
        
        else if(opc==2)
            return 32; 
        
        else if(opc==3)
            return 33; 

        else return 0;       
        break;

    default:
        return 0;
        break;
    }

}
