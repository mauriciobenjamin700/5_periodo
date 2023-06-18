#include<stdio.h>
#include<stdlib.h>

#include"exemplostring.h"

int main (){
    char* str[100];
    char* str1[100];
    char* str2[100];
    char* str3[100];
    char* str4[100];

    /*teste para ler uma string*/
    ler();

    /* teste referente ao tamanho*/
    printf("String:");
    scanf("%c", &str);
    printf("tamanho: %d", tamanho(str));
    return 0;

    /* teste referente a concatenação*/
    printf("String1:");
    scanf("%c", &str1);
    printf("String2:");
    scanf("%c", &str2);
    printf("Concatenando: %c", concatenar(str1,str2));

    /* teste referente a strigs iguais*/

    printf("String1:");
    scanf("%c", &str3);
    printf("String2:");
    scanf("%c", &str4);
    printf("Comparando: %d", iguais(str1,str2));
}