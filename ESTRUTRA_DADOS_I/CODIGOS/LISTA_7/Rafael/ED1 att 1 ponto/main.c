#include<stdio.h>
#include<stdlib.h>

#include "imagem.c"

int main(){

    Imagem *img;

    img = criarImagem(6,4);
    preencherImagem(img);
    imprimirImagem(img);

    /*1- comente o que acontece com as linhas 15 e 16
    img ->pixels[10].valor = 255
    printf("%d ", img->pixels[10].valor);

    Essa primeira n vai funcionar porque ele está tentando atribuir um valor no pixel dentro da main

    */
    /*2- comente o que acontece coms as linhas 20 e 21
    setPixelValue(img, 3,2, 255);
    printf("valor da posição 3,2 %d\n", getPixelValue(img, 3, 2));

        Já essa segunda funcionará pq ele ta chamando a função, atribuindo nessa função dentro da imagem e tambem a função de printar dentro da imagem.

    */

    img ->pixels[10].valor = 255;
    printf("\nvalor [10] = %d ", img->pixels[10].valor);

    setPixelValue(img, 3,2, 255);
    printf("\nvalor da posição 3,2 %d\n", getPixelValue(img, 3, 2));


    liberarImagem(img);
        
        
        
        return 0;

}

/*for(i < altura){
    for (j < largura){
        k = i + largura + j;
        mat -> pixel[k] = valor;

    }
}*/