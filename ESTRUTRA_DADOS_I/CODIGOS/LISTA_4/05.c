#include <stdio.h>

//A fórmula dos juros compostos é: M = C ( 1+i)t. Ou seja, a fórmula é: montante é igual ao capital, vezes a taxa de juros mais um, elevado ao tempo.
float juros_compostos(float valor_inicial, int total_meses, float taxa_juros, float juros_iniciais)
{
    if (total_meses>0)
    {
        juros_compostos(valor_inicial,total_meses-1,(1+taxa_juros*juros_iniciais), juros_iniciais);
    }
    return valor_inicial * (taxa_juros);
}


int main(void)
{
    float valor_inicial=20000, taxa_juros=0.06;
    int total_meses=3;

    printf("\nResultado = %.2f", juros_compostos(valor_inicial, total_meses, taxa_juros,taxa_juros));

    return 0;
}