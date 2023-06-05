#include "str.h"
#include <stdio.h>
#include <stdlib.h>


char* lerStr()
{
    char *str = (char*) malloc(300*sizeof(char));

    printf("\nInforme uma string: ");
    fflush(stdin);
    scanf("%s", str);

    return str;

}
int tamanhoStr(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }

    return i;

}
int comparar(char *str1, char *str2)
{
    //return 0 para igual e 1 para diferente
    int tamano_str1 = tamanhoStr(str1), tamano_str2 = tamanhoStr(str2);

    int retorno = 0;

    int i;

    if (tamano_str1 == tamano_str2)
    {
        for(i=0;i<tamano_str1;i++)
        {
            if (str1[i] != str2[i])
            {
                retorno = 1;
            }
        }
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

char* concatenar(char *str1, char *str2)
{
    int tamano_str1 = tamanhoStr(str1), tamano_str2 = tamanhoStr(str2);
    
    int tamanho_total = tamano_str1+tamano_str2;
    printf("\nTamanho 1: %d\nTamanho 2: %d\nTamanho 3: %d", tamano_str1, tamano_str2, tamanho_total);

    char *str = (char*) malloc(tamanho_total*sizeof(char));

    int i;

    //preenchendo a nova string com a primeira string
    for(i=0;i<tamano_str1;i++)
    {
        str[i] = str1[i];
    }
    //preenchendo a nova string com a segunda string
    for(i=0;i<tamano_str2;i++)
    {
        str[tamano_str1+i] = str2[i];
    }

    return str;

}
void liberar(char *str)
{
    free(str);
}
