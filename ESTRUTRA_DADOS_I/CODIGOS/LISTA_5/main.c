#include "definicao.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int tamanho=-1;

    char sinal=0;
    int indice=0;
    int retorno=0;
    float altura=0;

    int idade;

    char nome[50];

    sinal = menu();

    vetor = (Pessoa*) malloc(sizeof(Pessoa));

    while (sinal != '6')
    {
        switch (sinal)
        {
        case '1':

            
            printf("\nNome: ");
            fflush(stdin);
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';


            printf("\nIdade: ");
            fflush(stdin);
            scanf("%d", &idade);

            printf("\nAltura: ");
            fflush(stdin);
            scanf("%f", &altura);

            tamanho++;
            
            vetor[tamanho] = add_pessoa(nome,idade, altura);
            vetor = (Pessoa*) realloc(vetor, (tamanho+1) * sizeof(Pessoa));

            printf("\nPessoa adicionada com sucesso!\n");

            break;
        
        case '2':

            printf("\nAltura: ");
            fflush(stdin);
            scanf("%f", &altura);

            
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


            retorno = remover_pessoa(indice, vetor, tamanho);
            
            if(retorno==0)
            {
                printf("\nFalha no processo!");
            }
            else
            {
                printf("\nProcesso realizado com sucesso");
                tamanho --;
            }

            break;

        case '4':

            mostrar_pessoas(vetor, tamanho);
            break;

        case '5':

            printf("\nAltura: ");
            fflush(stdin);
            scanf("%f", &altura);

            mostrar_pessoa(altura, vetor, tamanho);
            break;

        case '6':
            free(vetor);
            break;

        default:
            printf("\nOpcao Invalida!\n");
            break;
        }

        sinal = menu();
    }
    


    

    return 0;
}