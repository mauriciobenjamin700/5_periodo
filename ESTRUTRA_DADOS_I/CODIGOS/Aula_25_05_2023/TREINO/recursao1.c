#include <stdio.h>

//Calculando o rendimento de uma conta poupança usando recursão

float rendimento(float saldo, float taxa, int meses){
    if (meses>0)
    {
        return saldo * taxa + rendimento(saldo*taxa+saldo, taxa, meses-1);
    }
    else
    {
        return 0;
    }

}

float dividaComposta(float divida, float juros, int prazoMeses)
{
    if(prazoMeses>0)
    {
        return divida * juros + dividaComposta(divida - divida *juros,juros, prazoMeses - 1);
    }

    return 0;
}

int main(void)
{
    float saldo = 1000;
    float taxa = 0.1;
    int meses = 2;


    printf("\nRendimento: %.2f", saldo + rendimento(saldo, taxa, meses));

    printf("\nDivida com juros: %.2f", saldo + dividaComposta(saldo, taxa, meses));

    return 0;    
}