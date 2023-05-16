#include <stdio.h>
#include <math.h>

void frac(float num, int* inteiro, float* frac){
    *inteiro = (int) floor(num);
    *frac = num-*inteiro;
}

int main(void){
    int numero_inteiro;
    float numero_fracionario,numero_completo;

    printf("\nDigite um valor fracionario: ");
    scanf("%f", &numero_completo);

    frac(numero_completo,&numero_inteiro,&numero_fracionario);
    printf("\nParte inteira -> %d\nParte fracionaria -> %f\n",numero_inteiro,numero_fracionario);
    return 0;
}
