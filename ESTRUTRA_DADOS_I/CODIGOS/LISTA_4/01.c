//crie uma função recursiva que calcule a exponenciação de um valor b por um expoente sem usar o operador de exponenciação
#include <stdio.h>

int potencia(int base, int expoente)
{
    if (expoente==0)
    {
        return 1;
    }
    else
    {
        return base * potencia(base,expoente-1);
    }
}

int main(void)
{
    int base, expoente;

    printf("\nDigite a base: ");
    scanf("%d", &base);

    printf("\nDigite o expoente: ");
    scanf("%d", &expoente);

    printf("\nResultado = %d", potencia(base, expoente));


    return 0;
}