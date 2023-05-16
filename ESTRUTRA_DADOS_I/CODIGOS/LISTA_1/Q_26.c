#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float* X1,float* X2){
    if(A > 0){
        float delta = (B*B) - (4*A*C);
        if(delta > 0){
        *X1 = (-B + sqrt(delta))/(2*A);
        *X2 = (-B - sqrt(delta))/(2*A);
        printf("%f\n%f\n",*X1,*X2);
        }else if(delta < 0){
            printf("Nao existe raizes reais\n");
        }
    }else if(A == 0){
        printf("A nao pode ser igual a 0");
    }
    return 0;
}

int main(void){

    float A,B,C,X1,X2;

    A = 4;
    B = 2;
    C = -6;

    raizes(A,B,C,&X1,&X2);

    
    return 0;
}