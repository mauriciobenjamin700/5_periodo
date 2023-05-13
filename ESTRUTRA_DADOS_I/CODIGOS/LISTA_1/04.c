#include <stdio.h>
#include <stdlib.h>

int troca(int *a, int *b){
    int aux=*a;

    *a = *b;
    *b = aux;

    return 0;

}

int main(){

    int x,y;

    printf("\n informe um valor para x: ");
    scanf("%d", &x);

    printf("\ninforme um valor para y: ");
    scanf("%d", &y);

    if (troca(&x,&y) == 0){
        printf("\nTroquei o valor de 'X' para %d", x);
        printf("\nTroquei o valor de 'Y' para %d", y);
    }
    else{
    printf("\nErro na funcao");
    }




return 0;
}
