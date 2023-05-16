#include <stdio.h>
#include <math.h>

void frac(float num, int* inteiro, float* frac){
    *inteiro = (int) floor(num);
    *frac = num-*inteiro;
}

int main(void){
    int n_int;
    float n_frac,n_completo=10.3;

    frac(n_completo,&n_int,&n_frac);
    printf("%d\n%f\n",n_int,n_frac);
    return 0;
}