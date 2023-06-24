#include <stdlib.h>
#include <stdio.h>
#include "TAD_lista_estatica.c"

int menu()
{
    int opc;

    printf("\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Inserir ordenado\n4 - Mostrar Todas as Pessoas\n5 - Contar Pessoas na Lista\n6 - Buscar Pessoa\n7 - Remover Pessoa\n8 - Liberar Memoria\n 0 - Sair\nEntrada: ");
    scanf("%d", &opc);

    return opc;
}


int main(void)
{
    Pessoa* lista;
    Pessoa p;

    p.id = 0;
    p.altura = 1.0;
    p.idade = 20;
    scanf("%s", p.nome);

    int opc;

    lista = (Pessoa*) malloc (sizeof(Pessoa));

    lista[0] = p;

    opc = menu();

    while (opc !=0)
    {
        switch (opc)
        {
        case 1:
            inserirPessoaInicio(lista);
            break;
        
        case 2:
            inserirPessoaFim(lista);
            break;
        
        case 3:
            //inserirPessoaOrdenado(lista);
            printf("Falta fazer");
            break;
        case 4:
            mostrarTodasPessoas(lista);
            break;
        case 5:
            contrarPessoasNaLista(lista);
            break;
        case 6:
            printf("\nPessoa na posicao: [%d]", buscarPessoa(lista));
            break;
        case 7:
            removerPessoa(lista);
            break;
        case 8:
            liberarMemoria(lista);
            break;
        case 0:
            printf("\nPrograma Encerrado!");
            break;
        default:
            printf("\nOpcao Invalida!");
            break;
        }
    }
    
    return 0;
}