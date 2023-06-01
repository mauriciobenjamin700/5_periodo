#include "definicao.h"
#include <stdio.h>
#include <stdlib.h>


struct pessoa
{
    char nome[50];
    int idade;
    float altura;
};

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
    Pessoa *vetor;

    char sinal=0;
    int tamanho=0;

    int indice=0;

    int retorno=0;

    float altura=0;

    vetor = (Pessoa*) malloc(sizeof(Pessoa));

    sinal = menu();

    while (sinal != '6')
    {
        switch (sinal)
        {
        case '1':
            tamanho = sizeof(vetor) / sizeof(Pessoa);
            add_pessoa(vetor, tamanho);
            printf("\nPessoa adicionada com sucesso!\n");
            break;
        
        case '2':
            printf("Altura: ");
            fflush(stdin);
            scanf("%f", &altura);

            tamanho = sizeof(vetor) / sizeof(Pessoa);

            indice = buscar_pessoa(altura, vetor, tamanho);

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

            tamanho = sizeof(vetor) / sizeof(Pessoa);

            retorno = remover_pessoa(indice,vetor, tamanho);
            
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
            if(tamanho>0)
            {
                mostrar_pessoas(tamanho, vetor);
            }
            else
            {
                printf("\nNao cadastrou pessoas ainda!");
            }
            break;

        case '5':
            if(tamanho>0)
            {
                
                printf("\nAltura: ");
                fflush(stdin);
                scanf("%f", &altura);
                mostrar_pessoa(altura, vetor, tamanho);
            }
            else
            {
                printf("\nNao cadastrou pessoas ainda!");
            }
            break;

        case '6':

            break;

        default:
            printf("\nOpcao Invalida!\n");
            break;
        }

        sinal = menu();
    }
    


    

    return 0;
}