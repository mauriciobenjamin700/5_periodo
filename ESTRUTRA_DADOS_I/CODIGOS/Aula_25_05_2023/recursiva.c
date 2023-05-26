// faça uma furção recursiva que retorna o resultado de uma multiplicação usando somas

#include <stdio.h>

int func(int n1,int n2)
{
    if (n1==0 || n2==0)
    {
        return 0;
    }
    else
    {
        return n1 + func(n1, n2-1);
    }
}

int mult(int m, int n){
    if (m < 1)
        return 0;
    return n + mult(m-1, n);
}

int main(void)
{
    int resultado;

    //resultado = func(3,3);
    resultado = mult(0,3);

    printf("Resultado: %d", resultado);

    return 0;
}