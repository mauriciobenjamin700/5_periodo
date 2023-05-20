
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_matriz(int **m, int l, int c){
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

void mostrar_vetor(int *v, int c){
	for (int i = 0; i < c; i++)
		printf("%d ",v[i]);
}

void calcular_pontos(int *v){
	printf("Tiveram %d peoes sorteados, totalizando %.2f \n", v[0], (float)v[0] * 1);
	printf("Tiveram %d cavalos sorteados, totalizando %.2f\n", v[1], (float)v[1] * 2.5);
	printf("Tiveram %d bispos sorteados, totalizando %.2f\n", v[2], (float)v[2] * 4.5);
	printf("Tiveram %d torres sorteados, totalizando %.2f\n", v[3], (float)v[3] * 6);
	printf("Tiveram %d rainhas sorteados, totalizando %.2f\n", v[4], (float)v[4] * 8);
	printf("Tiveram %d reis sorteados, totalizando %.2f\n", v[5], (float)v[5] * 10);
}
int main()
{
	int **mat, n, m, *vet, ***cubo;

	//alocal memoria para matriz 3D
	//alocar a profundidade
	int v = 5;
	cubo = (int ***) calloc(v, sizeof(int **));
	int i, j;
	//aloca a profundidade
	for (i = 0; i < v; ++i)
		cubo[i] = (int **) calloc(v, sizeof(int *));
	//aloca o restante da matriz(altura x largura)
	for (i = 0; i < v; ++i)
		for (j = 0; j < v; ++j)
			cubo[i][j] = (int *) calloc(v, sizeof(int));

	for (int z = 0; z < v; ++z){
		for (int y = 0; y < v; ++y){
			for (int x = 0; x < v; ++x){
				printf("%d ", cubo[z][y][x]);
			}
			printf("\n");
		}
		printf("\n");
	}
				
	/*scanf("%d %d",&n,&m);
	mat = (int **) calloc(n, sizeof(int*));
	//alocacao da matriz
	for (int i = 0; i < n; i++)
	{
		mat[i] = (int *) malloc(m * sizeof(int));		
	}
	//preencher a matriz
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat[i][j] = rand() % 6 + 1;

	//verificar a posicao
	vet = (int * ) calloc(6, sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			vet[mat[i][j] - 1]++;
	mostrar_matriz(mat, n, m);
	mostrar_vetor(vet, 6);
	calcular_pontos(vet);
	//liberaar memoria da matriz
	for (int i = 0; i < n; ++i)
	{
		free(mat[i]);
	}
	free(mat);

	//liberar memoria de vetor
	free(vet);
	*/
	return 0;
}