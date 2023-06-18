#include<stdio.h>
#include<stdlib.h>

#include"exemplo1.h"


int main(){
    float x=87, y=65;
    printf("soma: %f", soma(x,y));
    printf("\nsubtrair: %f", subtrair(x,y));
    printf("\nmultiplicar: %f", multiplicar(x,y));
    printf("\ndividir: %f", dividir(x,y));
    return 0;
}