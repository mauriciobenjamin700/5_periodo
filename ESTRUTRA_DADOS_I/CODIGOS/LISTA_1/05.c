#include <stdio.h>
#include <stdlib.h>

int troca(int *x, int *y){
    int maior;

    if (*x < *y){
        maior = *y;
        *y = *x;
        return maior;

    }
    else{
        return *x;
    }
}

int main(){

    int x,y;

    printf("\n informe um valor para x: ");
    scanf("%d", &x);

    printf("\ninforme um valor para y: ");
    scanf("%d", &y);

    x = troca(&x,&y);
    printf("\nMaior valor == %d \nMenor valor == %d\n", x,y);


return 0;
}
