#include <stdio.h>

void intervalo(int n)
{
    if(n>=0)
    {
        printf("%d ", n);
        intervalo(n-1);
    }
}


int main(void)
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    intervalo(num);

    return 0;
}