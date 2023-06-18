#include <stdio.h>
#include <stdlib.h>

//a funcao deve mostrar os numeros de 1 ate n
void mostrarValoresCrescentes(int n, int x){
	if (x <= n){//caso base
		printf("%d ",x);
		return mostrarValoresCrescentes(n, x+1); // caso geral
	}
}

//multiplicar M x N atraves de sucessivas adicoes (usando recursividade)
int multiplicacaoPorAdicao(int m, int n){
	if (n == 0 )//caso base
		return 0;
	return m + multiplicacaoPorAdicao(m, n-1);//caso geral
}

//funcao para calcular o fatorial de N de forma recursiva
int fatorial(int n){
	if (n == 0)//caso base (caso de parada)
		return 1;
	return n * fatorial(n-1);//caso geral 
}

//funcao recursiva para realizar as somas de todos os elemtnos de um vetor
int somaVetor(int *vet, int n){
	if (n == 1)// caso base
		return vet[0];
	return vet[n-1] + somaVetor(vet, n - 1); //caso geral resolvido de forma recursiva
}

//funcao recursiva para calcular a serie de fibbnacci
int fibbonacci(int n){
	if (n ==  0 || n == 1)//caso base 
		return n; 
	return fibbonacci(n-1) + fibbonacci(n-2); // caso geral para recursao binaria
}
int main(){
	//int vet[5] = {2,2,2,2,2};

	//mostrarValoresCrescentes(5, 1);
	//printf("A multiplicacao de 5 x 5 e igual a: %d ", multiplicacaoPorAdicao(5, 5));
	//printf("O fatorial de 5 é %d: ", fatorial(5));
	//printf("O valor da soma dos elementos do vetor é %d", somaVetor(vet, 5));
	for (int i = 0; i < 10; ++i)
		printf("%d, ", fibbonacci(i));

	

	return 0;
}