#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função recursiva que calcule os juros
compostos de um valor. Para isso o programa deverá ler um
valor inicial, o número de meses e a taxa de juros ao mês, e
passar estes valores à função como parâmetros. */

float juros_compostos(float valor, int meses, float taxa){
    if(meses == 0)
        return valor;
    valor = valor + (valor * (taxa/100));
    return juros_compostos(valor, meses-1,taxa);
}

int main(){
    float valor, taxa;
    int meses;
    printf("Valor inicial R$: ");
    scanf("%f", &valor);
    printf("Meses: ");
    scanf("%d", &meses);
    printf("Taxa: ");
    scanf("%f", &taxa);
    printf("O valor com juros e de R$:%.2f",  juros_compostos(valor, meses, taxa));
    return 0;
}