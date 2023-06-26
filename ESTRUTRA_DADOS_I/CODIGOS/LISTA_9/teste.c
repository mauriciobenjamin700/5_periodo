#include <stdlib.h>
#include <stdio.h>
#include "TAD_lista_estatica.c"

int menu()
{
    int opc;

    printf("\n\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Inserir ordenado\n4 - Mostrar Todas as Pessoas\n5 - Contar Pessoas na Lista\n6 - Buscar Pessoa\n7 - Remover Pessoa\n8 - Liberar Memoria\n0 - Sair\n\nEntrada: ");
    scanf("%d", &opc);


    return opc;
}


int main(void)
{
    Pessoa* lista;

    lista = iniciar();

    int opc;

    opc = menu();

    while (opc !=0)
    {

        if(opc==1)
        {
            inserirPessoaInicio(lista);//funciona
        }
        else if(opc==2)
        {
            
            inserirPessoaFim(lista); //funciona
            
        }
        else if(opc==3)
        {
            inserirPessoaOrdenado(lista);
        }
        else if(opc==4)
        {   

            mostrarTodasPessoas(lista);//funciona
    
        }
        else if(opc==5)
        {

            printf("\nPesssoas: %d", contrarPessoasNaLista(lista)); //funciona

        }
        else if(opc==6)
        {

            printf("\nPessoa na posicao: [%d]\n", buscarPessoa(lista)); // funciona

        }
        else if(opc==7)
        {
            removerPessoa(lista); //funciona mais ou menos

        }
        else if(opc==8)
        {   

            liberarMemoria(lista); //funciona
            
        }
        else if(opc==0)
        {
            printf("\nPrograma Encerrado!");//funciona
            break;
        }
        else
        {

            printf("\nOpcao Invalida!");
        }

        opc = menu();
    }
    
    return 0;
}