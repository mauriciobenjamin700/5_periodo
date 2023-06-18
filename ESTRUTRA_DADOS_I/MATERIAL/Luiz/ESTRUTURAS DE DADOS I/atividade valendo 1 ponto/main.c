#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"


int main(){
    Imagem *img;

    img = criarImagem(5, 5);
    preencherImagem(img);
    ImprimirImagem(img);

    /*
    1 - Comente o que acontece com as linhas 15 e 16 img->pixels[10].valor = 255; printf("%d", img->pixels[10].valor);
    Resposta: No ambiente de "imagem.h", especificamente no cabeçalho, tem-se-que a assinatura da estrutura e não a estrutura em si, 
    ou seja, a definição dela. Nesse sentido, diferentemente de uma função, não há como fazer o chamamento somente por meio disso. 
    Em outras palavras, não há como acessar os atributos através desse viés. Tal como, por meio da assinatura de uma função, 
    há como como realizar o chamamneto em outro arquivo, e em uma estrutura, não tem como fazer isso. A estrutura não está definida 
    no cabeçalho, não tem como ter acesso a ela da função main, e quando realiza o fluxo, quando executa o main, e quando chega no 
    (# include "imagem.h"), ele lê a definição e não consegue acessar o atributo somente por meio de uma definição, 
    haja vista que o atributo não se encontra nesse ambiente. Portanto, o erro se encontra nessa abordagem.

    2 - Comente o que acontece com as linhas 20 e 21 setPixelValue(img, 3,2, 255);
    printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3,2));
    Resposta: Nessa viés, dá certo, isso porque, ele acessa os atributos a partir da função definida no mesmo arquivo que as structs estão 
	definidas.
    */



    //liberarImagem(img);
    setPixelValue(img, 3,2, 255);
    printf("Valor da posicao 3,2: %d\n", getPixelValue(img, 3,2));
    return 0;
}