#include <stdio.h>
#include <stdlib.h>
/*1. Crie uma função recursiva que calcule a exponenciação de
um valor b por um expoente p sem usar o operador de
exponenciação. */

int esponenciacao(int b, int p){
    if(p == 0)
        return 1;
    return b * esponenciacao(b, p - 1);
}

int main(){
    printf(" O valor eh:%d", esponenciacao(2, 3));
    return 0;
}