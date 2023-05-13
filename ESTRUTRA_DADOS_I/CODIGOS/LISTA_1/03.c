#include <stdio.h>

int main(void){
    int x,y;

    printf("Valor de X: ");
        scanf("%d", &x);
    printf("\nValor de y: ");
        scanf("%d", &y);

    printf("\nEndereco de X == %p, valor = %d \nEndereco de Y == %p, valor = %d", &x,x,&y,y);


    if (&x>&y){
        printf("\n\n%d possui um maior endereco de memoria!\nEndereco de memoria == %p\n",x,&x);
    }
    else{
        printf("\n\n%d possui um maior endereco de memoria!\nEndereco de memoria == %p\n",y,&y);
    }


    return 0;
}
