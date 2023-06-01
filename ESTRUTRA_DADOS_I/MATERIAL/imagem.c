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

