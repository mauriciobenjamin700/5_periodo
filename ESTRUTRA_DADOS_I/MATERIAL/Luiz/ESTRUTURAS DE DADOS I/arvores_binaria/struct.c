typedef struct produto{
    int id;
    char nome[100];
    int quant;
    float preco;
    struct produto * esquerda, * direita; 

}Produto;

typedef struct arvore{
    Produto * raiz; 
}Arvore;