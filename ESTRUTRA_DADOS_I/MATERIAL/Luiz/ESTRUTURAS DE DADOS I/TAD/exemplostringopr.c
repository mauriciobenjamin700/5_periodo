#include<stdio.h>
#include<stdlib.h>

#include"exemplostring.h"

void ler(){
    char* nome;
    nome = (char*) malloc(100 * sizeof(char));
    if(nome == NULL){
        printf("Memória insuficiente!");
    }
    scanf("%c", &nome);
    printf("%c", &nome);
    free(nome);
}

char* concatenar(char *str1, char*str2){
    int i;
    for(i=0; str1[i] != '\0'; ++i); 
        for(int j=0; str2[j] != '\0'; ++j, ++i) {
            str1[i] = str2[j];
        }
    str1[i]='\0';
    return str1;
}

int tamanho(char *str){
    int aux = 0;
    
    for(int i=0; str[i] != '\0'; ++i){
        aux ++;
    }
    return aux;
}

int iguais(char* str3, char* str4){
    int i, aux, aux2;
    
    for(i=0; str3[i]!='\0'; i++){ 
        for(int j=0; str4[j]!='\0'; j++){
            aux = i;
            aux2 = j;
        }
    }
    if(aux != aux2){
        return 0;
    }
    if(str3[aux] != str4[aux2]){
        return 0;
    }else{
        return 1;
    }
}