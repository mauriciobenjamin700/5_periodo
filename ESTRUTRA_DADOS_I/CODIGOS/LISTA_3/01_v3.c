#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int **criaMatriz(int **matriz, int alt, int larg, int pro){
 
        //aloco memória para a matriz
        matriz = (int**)calloc(alt, sizeof(int*));

        if(matriz){
            //aloco a largura
            for(int i = 0; i < larg; i++){
                matriz[i] = (int *)calloc(larg, sizeof(int));
            }
            //profundidade e altura
            for(int x = 0; x < pro; x++){
                for(int j = 0; j < pro; j++){
                    matriz[x][j] =  (int *)calloc(pro, sizeof(int));
                }
            }
            return matriz;
        }else{
            printf("Não foi possivel alocar matriz! \n");
            exit(1);
        }
  
    
}

void imprimeMatriz(int ***matriz, int tam){
    for(int a = 0; a < tam; a++){
        for(int l = 0; l < tam; l++ ){
            for(int p = 0; p < tam; p++){
                printf("%d", matriz[a][l][p]);
            }
            printf("\n");
        }
        printf("\n");
     }
}


int  CalcularMaiorEsfera(int ***matriz, int alt, int larg, int pro){

    int comp_a = 0, comp_l = 0, comp_p = 0, vetor[3], tam, dA, dL, dP, dist;  
    float areaDaMaiorEsfera;

    tam = alt*larg*pro;

    int raio =  fmin(fmin(alt/2, larg/2), pro/2);
    
    // fazer a mediana para descobrir a coordenada do centro
    for(int a = 0; a < alt; a++){
        for(int l = 0; l < larg; l++){
            for(int p = 0; p < pro; p++){
               comp_a += a;
               comp_l += l;
               comp_p += p;
            }
        }
    }

    // coordenadas do centro da matriz
    vetor[0] =  comp_a/tam;
    vetor[1] =  comp_l/tam;
    vetor[2] =  comp_p/tam;

    for(int a = 0; a < alt; a++){
        for(int l = 0; l < larg; l++ ){
            for(int p = 0; p < pro; p++){
                dA = a - vetor[0];
                dL = l - vetor[1];
                dP = p - vetor[2];

                dist = (pow(dA,2) + pow(dL,2) + pow(dP,2));

                if(dist == raio ){
                    matriz[a][l][p] = 1;
                    areaDaMaiorEsfera = (3.14 * pow(raio, 2));
                }

            }
        }
    }
    return areaDaMaiorEsfera;  
}



void liberaMatriz( int ***matriz, int tam){

    for(int a = 0;a < tam; a++){
        for(int l = 0; l < tam;l++){
           free(matriz[a][l]);
        }
        free(matriz[a]);
    }
    free(matriz);
}


int main(){

    int ***mat = NULL, tam;

    int alt,larg, pro;
    float areaDaMaiorEsfera;

    printf("Informe as dimensões da matriz: ");
    scanf("%d", &tam);
    alt =  tam;
    larg = tam;
    pro = tam;

    mat =  criaMatriz(mat, alt, larg, pro);

    areaDaMaiorEsfera =  CalcularMaiorEsfera(mat, alt, larg, pro);
    printf("O maior circulo tem area: %.2f \n",areaDaMaiorEsfera);

    imprimeMatriz(mat, tam);
    liberaMatriz(mat, tam);



    return 0;
}