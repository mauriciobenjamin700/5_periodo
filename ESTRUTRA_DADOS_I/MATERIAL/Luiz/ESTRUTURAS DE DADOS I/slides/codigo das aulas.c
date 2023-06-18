#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void preencher(int *x, int tam){
	
	for (int i = 0; i < tam; ++i)
	{
		scanf("%d", &x[i]);
	}
}

void maiorMenor(int *maior, int *menor, int qtd){
	int valor;
	scanf("%d", &valor);
	*menor = valor;
	*maior = valor;

	for (int i = 0; i < qtd; ++i)
	{
		scanf("%d", &valor);
		if (valor < *menor ) *menor = valor;
		if (valor > *maior ) *maior = valor;
	}
}

int main()
{
	mediaValor();
	/*
	srand(time(NULL));
	int x = 5, *v, *vet2; 
	v = (int *) calloc(x, sizeof(int));
	vet2 = (int *) realloc(v, sizeof(int) * x * 2);
	if ((v == NULL) || (vet2 == NULL)){
		exit(1);
	}
	for (int i = 0; i < x; ++i)
	{
		v[i] = rand() % 100;
		printf("%d %d \n", v[i], i);
	}
	
	for (int i = 0; i < x; ++i)
	{
		printf("%d ", vet2[i]);
	}
	free(v);
	free(vet2);
	*/
	return 0;
}