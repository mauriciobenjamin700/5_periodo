#include <stdio.h>
#include <stdlib.h>

#include "operacoes.h"

int main()
{
	float x = 87, y = 65;
	printf("Soma: %.2f ", somar(x, y));
	printf("\nSubtrair: %.2f ", subtrair(x, y));
	printf("\nMultiplicar: %.2f ", multiplicar(x, y));
	printf("\nDividir: %.2f ", dividir(x, y));
	return 0;
}