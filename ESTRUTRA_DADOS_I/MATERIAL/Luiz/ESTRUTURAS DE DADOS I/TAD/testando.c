#include<stdio.h>
#include<stdlib.h>

#include"exemplostring.h"

int iguais(char* str1, char* str2){
    int i, aux, aux2;
    for(i=0; str1[i]!='\0'; i++){ 
        for(int j=0; str2[j]!='\0'; j++){
            aux = i;
            aux2 = j;
        }
    }
    if(aux != aux2){
        return "False";
    }
    if(str1[aux] != str2[aux2]){
        return "False";
    }else{
        return "True";
    }
}
