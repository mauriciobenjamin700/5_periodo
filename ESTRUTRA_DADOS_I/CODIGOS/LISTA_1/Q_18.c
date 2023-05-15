#include <stdio.h>
#include <math.h>

void calc_esfera(float R, float *area, float *volume){
    *area = 4 * 3.14 * (R*R);
    *volume = (4*3.14)/3 * (R*R*R);
}

int main(void) {
    
    float area,volume,R=10;

    calc_esfera(R,&area,&volume);
    
    printf("%f\n%f\n", area,volume);
    return 0;
}