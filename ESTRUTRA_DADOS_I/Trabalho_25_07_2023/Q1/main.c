#include <stdio.h>
#include <stdlib.h>
#include "criador.c"
#include "fazenda.c"
#include "animal.c"

int menuGeral()
{
    int opc;

    printf("\n\n1 - operacoes de Criador\n");
    printf("2 - operacoes de animal\n");
    printf("3 - operacoes de fazenda\n");
    printf("0 - para sair dos menus\n\n");

    setbuf(stdin,NULL);

    scanf("%d", &opc);

    return opc;
}

int menuCriador()
{
    int opc;

    printf("\n\n1 - cadastrar criador\n");
    printf("2 - mostrar atributos de criador\n");
    printf("3 - remover criador\n");
    printf("4 - para realizar busca de criador\n\n");
            
    scanf("%d", &opc);
    return opc;
}

int menuAnimal()
{

    int opc;

    printf("digite 1 - cadastrar criador\n");
    printf("digite 2 - mostrar atributos de criador\n");
    printf("digite 3 - remover criador\n");
    printf("Digite 4 - para realizar busca de criador\n\n");

    scanf("%d", &opc);
    return opc;
    
}

int menuFazenda()
{

    int opc;

    printf("1 - cadastrar fazenda\n");
    printf("2 - remover a fazenda\n");
    printf("3 - buscar fazenda\n");
    printf("4 - mostrar fazenda\n\n");

    scanf("%d", &opc);
    return opc;
    
}

int main()
{

    Criador *lista_criador;
    Fazenda *lista_fazenda;
    Animal *lista_animal;

    lista_animal = criaListaEncadeadaSimplesAnimais();
    lista_fazenda = criarListaEncadeadaCircularFazendas();
    lista_criador = criarListaDuplaCriadores();

    int op, sub_op, cria;

    do
    {   
        op = menuGeral();

        if (op == 1)
        {
            sub_op = menuCriador();

            switch (sub_op)
            {
            case 1:
                lista_criador = cadastrarCriador(lista_criador);
                break;
            case 2:
                mostrarTodos(lista_criador);
                break;
            case 3:
                removerCriador(&lista_criador);
                break;
            case 4:
                mostarCriador(buscarCriador(lista_criador));
                break;
            case 0:
                break;
            }
        }
        else if (op == 2)
        {

            sub_op = menuAnimal();

            switch (sub_op)
            {
            case 1:
                lista_animal = cadastrar_animal(lista_animal);
                break;
            case 2:
            {
                printf("infoma o id do animal!");
                scanf("%d", &cria);
                lista_animal = permutasAnimais(lista_fazenda, lista_fazenda, cria);
                break;
            }
            case 3:
            {
                printf("digite o animal a ser removido");
                scanf("%d", &cria);
                lista_animal = remover_animal(lista_fazenda, cria);
                break;
            }
            case 0:
                break;
            }
        }
        else if (op == 3)
        {

            sub_op = menuFazenda();

            switch (sub_op)
            {
            case 1:
                lista_fazenda = cadastrarFazenda(lista_fazenda);
                break;
            case 2:
                printf("digite o id da fazenda a ser excluida!\n");
                scanf("%d", &cria);
                lista_fazenda = removerFazenda(lista_fazenda, cria);
                break;
            case 3:
                printf("digite o id da fazenda a ser localizada");
                scanf("%d", &cria);
                buscarFazenda(lista_fazenda);
                break;

            case 4:
                mostrarFazenda(lista_fazenda);
                break;
            case 0:
                break;
            }
        }
    } while (op != 0);
}
