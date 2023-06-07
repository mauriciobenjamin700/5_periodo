#include <stdlib.h> 
#include <stdio.h> 
#include "matriz.h"

struct matriz { 
	int lin; 
	int col;
	float* v; 
};


/* Função cria - Aloca e retorna matriz m por n */ 
Matriz* cria (int m, int n)
{
	//vou alocar um vetor
	Matriz *mat;

	mat = (Matriz*) malloc (sizeof(Matriz*));

	if(mat)
	{
		printf("\nAloquei!");

		mat->lin = m;
		mat->col = n;
		mat->v = (float*) calloc(m*n,sizeof(float));

	}	
	else
	{
        printf("\nNão foi possivel alocar matriz! \n");
        exit(1);
	}



	return mat;
}
/* Função libera - Libera a memória de uma matriz */ 
void libera (Matriz* mat)
{
	//int tamanho = mat->lin * mat->col;
	//int i;

	//for (i=0;i<tamanho;i++)
	//{
		//free(mat->v[i]);
		free(mat->v);

		free(mat);
	//}
}

/* Função acessa - Retorna o valor do elemento [i][j] */ 
float acessa (Matriz* mat, int i, int j)
{
	//caso posicao invalida, retorno -1
	int k;

	//tamanho = (mat->lin * mat->col) - 1;
	
	
	if((i>=0 && i<mat->lin) && (j>=0 && j< mat->col))
	{
		//formula matematica para encontrar a posicao de una matriz em um vetor
		k = i * mat->col + j;
		return mat->v[k];
	}
	else
	{
		return -1;
	}

	
}
/* Função atribui - Atribui valor ao elemento [i][j] */ 
void atribui (Matriz* mat, int i, int j, float v)
{
	//caso posicao invalida  retorno -1
	int k;

	//tamanho = (mat->lin * mat->col) - 1;
	
	
	if((i>=0 && i<mat->lin) && (j>=0 && j< mat->col))
	{
		//formula matematica para encontrar a posicao de una matriz em um vetor
		k = i * mat->col + j;
		mat->v[k] = v;

	}


}
/* Função linhas - Retorna o no. de linhas da matriz */ 
int linhas (Matriz* mat)
{
	return mat->lin;
}
/* Função colunas - Retorna o no. de colunas da matriz */ 
int colunas (Matriz* mat)
{
	return mat->col;
}