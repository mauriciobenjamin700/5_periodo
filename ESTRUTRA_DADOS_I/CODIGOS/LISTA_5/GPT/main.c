#include "tad.h"
#include <stdio.h>
#include <stdlib.h>

char menu()
{
    char sinal;

    printf("\n1 - Adicionar Pessoa\n2 - Buscar pessoa pela altura\n3 - Remover pessoa do vetor\n4 - Mostrar todas as pessoas\n5 - Mostrar uma pessoa de acordo com a altura informada\n6 - Sair\nSua resposta: ");

    fflush(stdin);
    scanf("%c", &sinal);

    return sinal;
}

int main(void)
{

    char sinal=0;
    int indice=0;
    int retorno=0;
    float altura=0;

    

    sinal = menu();

    servidor(1);

    while (sinal != '6')
    {
        switch (sinal)
        {
        case '1':
            
            add_pessoa();

            break;
        
        case '2':

            printf("\nAltura: ");
            fflush(stdin);
            scanf("%f", &altura);

            indice = buscar_pessoa(altura);

            if (indice != -1)
            {
                printf("\nEncontrei na posicao %d", indice);
            }
            else
            {
                printf("\nNao encontrei!");
            }

            break;

        case '3':
            printf("\nIndice que tera seu conteudo deletado: ");
            fflush(stdin);
            scanf("%d", &indice);

            retorno = remover_pessoa(indice);
            
            if(retorno==0)
            {
                printf("\nFalha no processo!");
            }
            else
            {
                printf("\nProcesso realizado com sucesso");
            }

            break;

        case '4':
            mostrar_pessoas();
            break;

        case '5':

            printf("\nAltura: ");
            fflush(stdin);
            scanf("%f", &altura);
            mostrar_pessoa(altura);
            break;

        case '6':
            servidor(0);
            break;

        default:
            printf("\nOpcao Invalida!\n");
            break;
        }

        sinal = menu();
    }
    


    

    return 0;
}