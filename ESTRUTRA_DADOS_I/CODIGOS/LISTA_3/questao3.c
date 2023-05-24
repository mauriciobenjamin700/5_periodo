#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_matriz(int **mat, int *linhas, int *colunas);
void mudar_matriz(int **mat, int *linhas, int *colunas);
void preencher_matriz(const char *arquivo,int **mat, int *linhas, int *colunas);
void criar_txt(int **mat, int *linhas, int *colunas);

int main(){
    char arquivo[] ={"input.txt"};
    int **mat,linhas,colunas;


    // abertura de arquivo
    FILE *file = fopen(arquivo,"r");
    int i;

    if(file){

        printf("\tDados lidos do arquivo\n");
        fscanf(file,"%d", &linhas);
        fscanf(file,"%d", &colunas);

        mat = (int**) calloc(linhas, sizeof(int*));
        for(i = 0; i < linhas;i++){
            mat[i] = (int*) calloc(colunas,sizeof(int));
        }

    }
    else
        printf("\nERRO ao abrir o arquivo!!!\n");

    preencher_matriz(arquivo,mat,&linhas,&colunas);
    mudar_matriz(mat,&linhas,&colunas);
    imprime_matriz(mat,&linhas,&colunas);
    criar_txt(mat,&linhas,&colunas);

    for(i =0; i < linhas;i++){
            free(mat[i]);
        }
        free(mat);

    fclose(file);
    

    return 0;
}

void preencher_matriz(const char *arquivo,int **mat, int *linhas, int *colunas){

    FILE *file = fopen(arquivo,"r");

    printf("%s\n", arquivo);
    int i,j;

    if(file){
        for(i = 0; i < *linhas;i++){
            for(j = 0; j < *colunas;j++){
                fscanf(file, "%d", &mat[i][j]);
            }
        }
        fclose(file);

    }
    else
        printf("\nERRO ao preencher a matriz");

}

void mudar_matriz(int **mat, int *linhas, int *colunas){

    int i,j;

    for(i = 0; i < *linhas; i++){
        for(j = 0; j < *colunas; j++){
            if(abs( i - j) < 100){
                mat[i][j] = 255;
            }
            else
                mat[i][j] = 0;
        }
        printf("\n");
    }

}

void imprime_matriz(int **mat, int *linhas, int *colunas){

    int i,j;

    for(i = 0; i < *linhas; i++){
        for(j = 0; j < *colunas; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

void criar_txt(int **mat, int *linhas, int *colunas){
    char arquivo[] = {"novo.txt"};
    FILE *file = fopen(arquivo,"w+");

    printf("%s\n", arquivo);
    int i,j;

    if(file){
        for(i = 0; i < *linhas;i++){
            for(j = 0; j < *colunas;j++){
                fprintf(file, "%d", mat[i][j]);
            }
        }
        fclose(file);

    }
    else
        printf("\nERRO ao preencher a matriz");

}
