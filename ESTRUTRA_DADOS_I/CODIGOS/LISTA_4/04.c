#include <stdio.h>

//intervalo aberto
int intervalo(int n1, int n2)
{   //caso n1 seja maior que n2, e n2 seja maior que zero
    if(n1-1>n2)
    {
        return n1-1 + intervalo(n1-1,n2);
    }
    else if (n1<n2-1)
    {
        return n2-1 + intervalo(n1,n2-1);
    }

    return 0;
}


int main(void)
{
    int n1,n2;

    printf("\nDigite um numero: ");
    scanf("%d", &n1);
    printf("Digite outro numero: ");
    scanf("%d", &n2);

    printf("A soma dos numeros no intervalo de %d ate %d = %d",n1,n2,intervalo(n1,n2));

    return 0;
}