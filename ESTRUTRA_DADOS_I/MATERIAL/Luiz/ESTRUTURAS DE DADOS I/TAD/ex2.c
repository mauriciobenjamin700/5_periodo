#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int tamanho(char *str){
    int aux = 0;
    for(int i=0; str[i] != '\0'; ++i){
        aux ++;
    }
    return aux;
}

int main (){
    char str[100];
    puts("String:");
    gets(str);
    printf("tamanho:%d", tamanho(str));
    return 0;
}