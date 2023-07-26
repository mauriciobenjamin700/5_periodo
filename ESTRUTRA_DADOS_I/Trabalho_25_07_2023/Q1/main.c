#include <stdio.h>
#include <stdlib.h>
#include "criador.c"
#include "fazenda.c"
#include "animal.c"

int menuGeral()
{
    int opc;
    printf("\n\n---------------MENU GERAL----------");
    printf("\n\n1 - Criador\n");
    printf("2 - Animal\n");
    printf("3 - Fazenda\n");
    printf("0 - Sair\n\n");

    setbuf(stdin,NULL);

    scanf("%d", &opc);
    printf("\n-----------------------------------");

    return opc;
}

int menuCriador()
{
    int opc;
    printf("\n\n---------------MENU DO CRIADOR----------");
    printf("\n\n1 - Cadastrar\n");
    printf("2 - Mostrar Todos\n");
    printf("3 - Remover criador\n");
    printf("4 - Busca Criador\n");
    printf("5 - Voltar\n\n");
    
            
    scanf("%d", &opc);
    printf("\n-----------------------------------");
    return opc;
}

int menuAnimal()
{

    int opc;

    printf("\n\n---------------MENU DO ANIMAL----------");
    printf("\n\n1 - Cadastrar\n");
    printf("2 - Permuta\n");
    printf("3 - Remover \n");
    printf("4- Mostrar Todos\n\n");
    printf("5 - Contar Animais\n\n");
    printf("6 - Arroba\n\n");
    printf("7 - Status \n\n");
    //printf("4 - Buscar\n");
    printf("8 - Voltar\n\n");
    

    scanf("%d", &opc);
    printf("\n-----------------------------------");
    return opc;
    
}

int menuFazenda()
{

    int opc;
    printf("\n\n---------------MENU DA FAZENDA----------");
    printf("\n\n1 - Cadastrar\n");
    printf("2 - Remover\n");
    printf("3 - Buscar\n");
    printf("4 - Mostrar\n");
    printf("5 - Voltar\n\n");
    

    scanf("%d", &opc);
    printf("\n-----------------------------------");
    return opc;
    
}

int main()
{

    Criador *lista_criador = criarListaDuplaCriadores();;
    Fazenda *lista_fazenda = criarListaEncadeadaCircularFazendas();
    Animal *lista_animal = criaListaEncadeadaSimplesAnimais();

    int quantidade_M, quantidade_F;


    int op, sub_op, cria;
    //laço de repetição central
    do
    {   
        op = menuGeral();
        //caso queira opções do Criador
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
        //caso queira opções do Animal
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
            case 4:
            mostrarAnimais(lista_animal);
                break;
            
            case 5:
            quantidade_M = contarAnimais(lista_animal,'M');
            quantidade_F = contarAnimais(lista_animal,'F');

            printf("\n\nQuantide de Animais: M = %d & F = %d", quantidade_M, quantidade_F);

                break;

            case 6:
            contarArroba(lista_animal);
                break;
            
            case 7:
            printStatus(lista_animal);
                break;
            case 0:
                break;
            }
        }
        //caso queira opções da Fazenda
        else if (op == 3)
        {

            sub_op = menuFazenda();

            switch (sub_op)
            {
            case 1:
                lista_fazenda = cadastrarFazenda(lista_fazenda);
                break;
            case 2:
                printf("\n\nID Fazenda: ");
                scanf("%d", &cria);
                lista_fazenda = removerFazenda(lista_fazenda, cria);
                break;
            case 3:
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

    printf("\n\nSistema Encerrado...");
}
