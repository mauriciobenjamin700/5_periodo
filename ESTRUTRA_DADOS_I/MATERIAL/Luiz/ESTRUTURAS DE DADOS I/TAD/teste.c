#include<stdio.h>
#include<string.h>

char* concatenar(char *str1, char*str2){
    int i;
    for(i=0; str1[i]!='\0'; ++i); 
        for(int j=0; str2[j]!='\0'; ++j, ++i) {
            str1[i] = str2[j];
        }
    str1[i]='\0';
    return str1;
}

int main(){
    char str1[100];
    char str2[100];
    puts("String1:");
    gets(str1);
    puts("String2:");
    gets(str2);
    puts(concatenar(str1,str2));
    return 0;
}