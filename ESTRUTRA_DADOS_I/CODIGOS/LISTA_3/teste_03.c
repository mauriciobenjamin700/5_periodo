#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *arquivo;

    //arquivo = fopen("C:\\Users\\Notebook\\Documents\\GitHub\5_periodo\\ESTRUTRA_DADOS_I\\CODIGOS\\LISTA_3\\input.txt","r");
    arquivo = fopen("input.txt", "r");

    if ( arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo");
        return 1;
    }

    char linha[100]; // Variável para armazenar cada linha do arquivo

    while (fgets(linha, sizeof(linha), arquivo) != NULL) 
    {
        printf("%s", linha); // Ou faça qualquer manipulação desejada com a linha
    }


    fclose(arquivo);

    return 0;
}