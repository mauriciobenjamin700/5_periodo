#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float raio, float *area, float *volume)
{
    *area = 4 * 3.14 * (raio*raio);
    *volume = (4*3.14)/3 * (raio*raio*raio);
}

int main(void)
{
    
    float area,volume,raio;
    
    printf("\nDigite um valor para o raio: ");
    scanf("%f", &raio);

    calc_esfera(raio,&area,&volume);
    
    printf("Area: %.2f\nVolume: %.2f\n", area,volume);
    return 0;
    
}