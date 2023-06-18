typedef struct pixel Pixel;
typedef struct imagem Imagem;

Imagem *criarImagem(int largura, int altura);
void preencherImagem(Imagem *img);
void imprimirImagem(Imagem *img);
void liberarImagem(Imagem *img);
void setValue(Imagem *img, int x, int y, int valor);
int getPixelValue(Imagem *img, int x, int y);