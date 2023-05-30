#include <stdio.h>

int intervalo(int n)
{
    if(n>=0)
    {
        return n + intervalo(n-1);
    }
    return 0;
}


int main(void)
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("A soma dos numeros no intervalo de %d ate 0 = %d",num,intervalo(num));

    return 0;
}