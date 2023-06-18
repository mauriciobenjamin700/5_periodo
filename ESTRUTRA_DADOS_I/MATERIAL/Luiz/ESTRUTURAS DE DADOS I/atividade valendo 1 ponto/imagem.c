#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagem.h"



// struct pixel
struct pixel{
    int valor, x, y;
};

// struct imagem
struct imagem{
    Pixel *pixels;
    int largura, altura;
};

// função criar iamgem
Imagem *criarImagem(int largura, int altura){ // tipo Imagem
    Imagem *img; // ponteiro para struct imagem
    img = (Imagem*) malloc(sizeof(Imagem)); // alocando a struct Imagem
    img->altura = altura; // acessa atributos
    img->largura = largura; // acessa atributos
    img->pixels = (Pixel*)malloc(altura * largura * sizeof(Pixel)); // alocando a struct Pixel
    return img; // retornou para o main
}

// função para preencher a imagem
void preencherImagem(Imagem *img){
    int i, j;

    srand(time(NULL)); 

    for(i = 0; i < img->altura; i++){
        for(j = 0; j < img->largura; j++)
        img->pixels[(i * img->largura) + j].valor = rand() % 256; // preenchendo a imagem com numeros aleatórios
        }
    }

void ImprimirImagem(Imagem *img){
    int i, j;
    for(i = 0; i < img->altura; i++){
        for(j = 0; j < img->largura; j++){
            printf("%d", img->pixels[(i * img->largura) * j].valor); // imprimindo a imagem
        }
        printf("\n");
    }
}

void liberarImagem(Imagem *img){
    free(img);
}

void setPixelValue(Imagem *img, int y, int x, int valor){
    int k;
    if((x > 0 && y > 0) && (y < img->altura && x < img->largura)){
        k = y * img->largura * x;
        img->pixels[k].valor = valor;
        img->pixels[k].x = x;
        img->pixels[k].y = y;
    }

}

int getPixelValue(Imagem *img, int y, int x){
    int k;
    if((x > 0 && y > 0) && (y < img->altura && img->largura)){
        k = y * img->largura + x;
        return img->pixels[k].valor;
    }
}