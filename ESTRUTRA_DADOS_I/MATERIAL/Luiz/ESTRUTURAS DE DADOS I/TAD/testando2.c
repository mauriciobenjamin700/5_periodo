#include<stdio.h>
#include<stdlib.h>

#include"exemplostring.h"


int main(){
    char str1[100];
    char str2[100];

    puts("String1:");
    gets(str1);
    puts("String2:");
    gets(str2);
    puts(iguais(str1,str2));
}