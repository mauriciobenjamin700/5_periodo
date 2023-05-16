#include <stdio.h>
#include <stdlib.h>

int obtem_produtos_zerados(int *codigo, int *estoque,int *cod_prod_zerados,int quant_prod){
    int i,quant_prod_zerados=0;
    cod_prod_zerados = (int*) realloc(cod_prod_zerados,quant_prod * sizeof(int));

    for(i=0;i<quant_prod;i++){
        if(*estoque == 0){
            *cod_prod_zerados = *codigo;
            quant_prod_zerados++;
            cod_prod_zerados++;
        }
        estoque++;
        codigo++;
    }

    return quant_prod_zerados;
}


int main(void){

    int codigo[3] = {1,2,3}, estoque[3] = {5,2,0},*cod_prod_zerados,quant_prod_zerados,quant_prod,i;
    cod_prod_zerados = (int*) malloc(1*sizeof(int));
    quant_prod = sizeof(codigo)/sizeof(codigo[0]);
    quant_prod_zerados = obtem_produtos_zerados(codigo,estoque,cod_prod_zerados,quant_prod);

    printf("Total de produtos fora de estoque == %d\n",quant_prod_zerados);
    for(i=0;i<quant_prod_zerados;i++){
        printf("Vetor[%d], codigo do do produto com estoque zerado %d",i,*cod_prod_zerados);
        cod_prod_zerados++;
    }

    return 0;
}