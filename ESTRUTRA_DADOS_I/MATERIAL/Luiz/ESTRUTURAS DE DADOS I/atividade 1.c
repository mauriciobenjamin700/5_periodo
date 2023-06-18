#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int *maiorMenorMedia(int col, int linh, int **mat);
void mostrarMaiorMenorMeida(int *vol, int t);
void mostrarDados(int l, int c, int **m);
int **preencheMatriz(int col, int lin);


int ** preencherMatriz(int lin, int col){
	srand(time(NULL));
	int **mat, i, l, c;
	mat = (int**) calloc(lin, sizeof(int*));
	for(i=0; i < lin; i++){
		mat[i] = (int*) calloc(col, sizeof(int));
	}
	for(l=0; l < lin; l++){
		for(c=0; c < col; c++){
			mat[l][c] = rand() % 100;
		}
	}
			
	return mat;
}

void mostrarDados(int lin, int col,int **mat){
	int i, j;
	for(i=0;i < lin; i++){
		for(j=0; j < col; j++){
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
	
}

int * menorMaiorMedia(int l,int c, int **mat){
	int i,j, maior=0,menor=0,media=0;
	int * vol;

	vol = (int*) calloc(media,sizeof(int));
	vol = (int*) calloc(maior,sizeof(int));
	vol = (int*) calloc(menor,sizeof(int));

	menor = mat[0][0];
	for(i=0;i < l; i++){
		for(j=0; j < c; j++){
			if(mat[i][j] < menor){
				menor = mat[i][j];
			}
			if(mat[i][j] > maior){
				maior = mat[i][j];	
			}
		}
	}
	for(i=0;i < l; i++){
		for(j=0; j < c; j++){
			media += mat[i][j];
		}
	}
	media = ((media)/(l * c));
	return vol;
}

void mostrarMaiorMenorMeida(int *vol, int t){
	int i;
	printf("Valores: \nMedia \nMaior \nMenor");
	for(i=0; i < 3; i++)
		printf("%d\t", vol[i]);
	printf("\n");
	free(vol);
}
		

int main(){
	int **c, *l;
	c = preencherMatriz(4,4);
	mostrarDados(4,4,c);
	l = menorMaiorMedia(4,4,c);
	mostrarMaiorMenorMeida(l,4);

	return 0;
}
