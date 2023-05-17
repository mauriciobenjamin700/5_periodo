#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função recursiva que receba dois valores inteiros (x e y) e retorne o resultado de x^y 
para o método principal.
*/

int re(int x, int y){

    if (y==0){
        return 1;
    }
    else{
        return  x * re(x,y-1);     
    }
        
}

int main(){
    int x;
    int y;
    int resultado;

    x = 3;
    y = 3;

    resultado = re(x,y);

    printf("A potencia de %d por %d == %d", x,y,resultado);
    return 0;
}