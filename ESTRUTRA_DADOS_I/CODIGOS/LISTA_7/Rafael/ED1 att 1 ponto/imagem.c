#include<stdio.h>
#include<stdlib.h>

#include "imagem.h"



struct pixel{
    int valor, x, y;
    
};


struct imagem{
    Pixel *pixels;
    int largura, altura;

    };


Imagem *criarImagem(int largura, int altura){
        Imagem *img;

        img = (Imagem*) malloc(sizeof(Imagem));
        img->altura = altura;
        img->largura = largura;
        img->pixels = (Pixel*)malloc(altura * largura * sizeof(Pixel));
        
        return img;
}

void preencherImagem(Imagem *img){
    int i, j;
    
    for(i = 0; i < img->altura; i++){
        for (j = 0; j < img->largura; j++){
        //k = i + img + j;
       //img->pixel[k] = valor;
       setPixelValue(img, i, j, j+i);
        }
    }
}

void imprimirImagem(Imagem *img){
    int i, j;
      for(i = 0; i < img->altura; i++){
        for (j = 0; j < img->largura; j++){
        printf("%d", getPixelValue(img, i, j));
            
        }
            printf("\n");
    }
}

void liberarImagem(Imagem *img){
    free(img->pixels);
    free(img);
}

void setPixelValue(Imagem *img, int y, int x, int valor){
    int k;
    k = y * img->largura + x;
    
    img->pixels[k].valor = valor;
        
        img->pixels[k].y = y;
            
            img->pixels[k].x = x;


}

int getPixelValue(Imagem *img, int y, int x){
        int k;
	if ((y >= 0) && (x >= 0) && (y <= img->altura) && (x <= img->largura)){
		k = y * img->largura + x;
		return img->pixels[k].valor;
	} else {
		return -1;
	}

}