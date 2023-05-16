#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float* X1,float* X2)
{

    if(A > 0)
    {
        float delta = (B*B) - (4*A*C);
        if(delta > 0)
        {
        *X1 = (-B + sqrt(delta))/(2*A);
        *X2 = (-B - sqrt(delta))/(2*A);
        printf("%f\n%f\n",*X1,*X2);
        }
        else if(delta < 0)
        {
            printf("\nNao existe raizes reais\n");
        }
    }
    else if(A == 0)
    {
        printf("A nao pode ser 0");
    }
    return 0;
}

int main(void)
{

    float A,B,C,X1,X2;

    printf("\nDigite um valor para A: ");
    scanf("%f", &A);
    printf("\nDigite um valor para B: ");
    scanf("%f", &B);
    printf("\nDigite um valor para C: ");
    scanf("%f", &C);

    raizes(A,B,C,&X1,&X2);

    
    return 0;
}