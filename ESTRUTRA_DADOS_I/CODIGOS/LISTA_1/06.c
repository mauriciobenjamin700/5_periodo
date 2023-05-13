#include <stdio.h>
#include <stdlib.h>

int soma_dobro(int *a,int*b){
    int soma;
    *a = (*a * 2);
    *b = (*b * 2);

    soma =  *a + *b;
    return soma;
}

int main(){

    int x,y;

    printf("\n informe um valor para x: ");
    scanf("%d", &x);

    printf("\ninforme um valor para y: ");
    scanf("%d", &y);

    printf("A soma do dobro de %d com o dobro de %d -> : ", x,y);
    printf("%d + %d = %d",x,y,soma_dobro(&x,&y));


return 0;
}
