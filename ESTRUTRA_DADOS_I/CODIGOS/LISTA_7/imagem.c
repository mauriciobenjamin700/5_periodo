#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"

struct pixel{
	int valor, x, y;
};

struct imagem{
	Pixel *pixels;
	int largura, altura;
};


Imagem* criarImagem(int largura, int altura)
{
	Imagem *img;

	img = (Imagem*) malloc(sizeof(Imagem));

	img->largura = largura;

	img->altura = altura;

	img->pixels = (Pixel*) calloc (largura*altura, sizeof(Pixel));


	return img;
}
void preencherImagem(Imagem *img)
{
	int i,j;

	int k;

	for(i=0;i<img->largura;i++)
	{
		for(j=0;j<img->altura;j++)
		{
			k = i * img->altura * j;
			img->pixels[k].x = i;
			img->pixels[k].y = j;
			//img->pixels[k].valor = i+j;
			setPixelValue(img,i,j,i+j);
		}
	}
}
void imprimirImagem(Imagem *img)
{
	int i,j;

	//int k;

	for(i=0;i<img->largura;i++)
	{
		for(j=0;j<img->altura;j++)
		{
			//k = i * img->altura * j;

			//printf("%d ", img->pixels[k].valor);
			printf("%d ", getPixelValue(img, i,j));
		}

		printf("\n");
	}

}
void liberarImagem(Imagem *img)
{
	free(img->pixels);
	free(img);
}
void setPixelValue(Imagem *img, int x, int y, int valor)
{
	int k;

	if ((x >= 0 && x < img->largura) && (y >= 0 && y < img->altura))
	{
	k = x * img->altura + y;
	img->pixels[k].valor = valor;
	}
	else
	{
		printf("\nPosicoes Invalidas");
	}
}
int getPixelValue(Imagem *img, int x, int y)
{
	//retornar -1 caso posicao invalida;
	int k;

	if ((x >= 0 && x < img->largura) && (y >= 0 && y < img->altura))
	{
	k = x * img->altura + y;

	return img->pixels[k].valor;
	}
	else
	{
		return -1;
	}
}
