#include "str.h"
#include <stdio.h>
#include <stdlib.h>

char menu()
{
    char opc;
    printf("\n1 - Ler string\n2 - Tamanho string\n3 - Comparar String\n4 - Concatenar String\n5 - Liberar String\n6 - Sair\nSua escolha: ");
    fflush(stdin);
    scanf("%c", &opc);

    return opc;


}

int main(void)
{
    char opc;

    char *string_1, *string_2, *nova_string;

    int tamanho, retorno;

    opc = menu();

    while (opc!='6')
    {
        switch (opc)
        {
        case '1':
            string_1 = lerStr();
            printf("\nString lida com sucesso!\nString: %s", string_1);
            break;
        
        case '2':
        string_1 = lerStr();
        printf("\nString lida com sucesso!\nString: %s", string_1);
        tamanho = tamanhoStr(string_1);

        printf("\nTamanho da String: %d", tamanho);


            break;
        
        case '3':
            string_1 = lerStr();
            string_2 = lerStr();

            retorno = comparar(string_1, string_2);

            if(retorno==1)
            {
                printf("\nStrings diferentes!");

            }
            else
            {
                printf("\nStrings Iguais!");
            }
            break;

        case '4':
            string_1 = lerStr();
            string_2 = lerStr();

            nova_string = concatenar(string_1, string_2);

            printf("\nNova concatenada: %s", nova_string);

            break;
        
        case '5':
            liberar(string_1);
            liberar(string_2);
            liberar(nova_string);
            
            break;

        case '6':
            break;

        default:
            break;
        }

    opc = menu();
    }
    

    return 0;
}