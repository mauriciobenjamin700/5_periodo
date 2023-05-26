//faca o fatorial de um numero em C

#include <stdio.h>

int fatorial(int numero)
{
    if(numero<=1)
    {
        return 1;
    }
    else
    {
        return numero * fatorial(numero-1);
    }
}

int main(void)
{

    int  numero=5;

    printf("%d", fatorial(numero));

    
    return 0;
}
