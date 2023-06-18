#include<stdio.h>
#include<stdlib.h>

#include "imagem.h"

struct pixel{
    int valor,x,y;
};

struct Imagem{
    Pixel *pixels;
    int largura, altura;
};

Imagem *criarImagem(int largura, int altura){
    Imagem* img;
    img = (Imagem*)malloc(sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->pixels = (Pixel*)malloc(altura * largura * sizeof(Pixel));

    return img;
}

void preencherImagem(Imagem *img){
    int k;
    for(int i; i < img->altura; i++){
        for(int j; j < img->largura; j++){
            k = i * img->largura * j;
            img->Pixel[k].valor= 0;
        }
    }

}
void imprimirImagem(Imagem *img){
    int k, vet[];
    for(int i; i < img->altura; i++){
        for(int j; j < img->largura; j++){
            k = i * img->largura * j;
            printf(img -> Pixel[k].valor= 0);
        }
    }
    
}
void liberarImagem(Imagem *img);
void setValue(Imagem *img, int x, int y, int valor);
int getPixelValue(Imagem *img, int x, int y);