#include <stdio.h>
#include <stdlib.h>


int main(void){
    int a,*b,**c,***d;

    b = &a;
    c = &b;
    d = &c;

    printf("Digite um valor para A: ");
    scanf("%d", &a);

    printf("\nDobro = %d\nTriplo = %d\nQuadruplo = %d", *b*2,**c*3,***d*4);


    return 0;
}
