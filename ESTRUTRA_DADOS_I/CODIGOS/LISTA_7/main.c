#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

int main()
{
	Imagem *img;

	img = criarImagem(5,5);
	preencherImagem(img);
	imprimirImagem(img);
	
	/*
	1 - Comente o que acontece com as linhas 15 e 16
	img->pixels[10].valor = 255;
	printf("%d ", img->pixels[10].valor);
	*/
	/*
	2 - Comente o que acontece com as linhas 20 e 21
	setPixelValue(img, 3,2, 255);
	printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3,2));
	*/

	//setPixelValue(img, 3,2, 255);
	//printf("\nValor da posicao 3,2 %d\n", getPixelValue(img, 3,2));
	//imprimirImagem(img);

	//img->pixels[10].valor = 255;
	//printf("\n%d \n", img->pixels[10].valor);

	
	//Resposta pergunta 01: O usuário está acessando a TAD diretamente para atribuir e buscar o valor ao inves de usar o metodo getPixelvalue para implementar o mesmo, não é uma boa pratica de programação mas funciona.

	//Resposta pergunta 02: O usuário está acessando a TAD por meio dos metodos que foram criando para operala, isso é uma boa pratica de programação e garante que a saida do metodo será algo que ja foi preparado para o usuário.

	//imprimirImagem(img);

	liberarImagem(img);

	return 0;
}