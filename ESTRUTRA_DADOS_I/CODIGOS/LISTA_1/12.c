#include <stdio.h>
#include <stdlib.h>

int ordena(int *x,int *y,int *z){
    int maior,menor,meio,sinal;

    if (*x != *y && *x != *z && *y != *z){

        // Caso X seja o maior
        if (*x > *y && *x > *z){
            maior = *x;

            if (*y>*z){
                meio = *y;
                menor = *z;
            }
            else{
                meio = *z;
                menor = *y;
            }
        } 
        //Caso y seja o maior
        else if (*y > *x && *y > *z){
            maior = *y;

            if (*x>*z){
                meio = *x;
                menor = *z;
            }
            else{
                meio = *z;
                menor = *x;
            }
        }
        // Caso Z seja o maior
        else{
            maior = *z;

            if (*x>*y){
                meio = *x;
                menor = *y;
            }
            else{
                meio = *y;
                menor = *x;
            }
        }

        sinal = 0;

    }
    else{
        maior = *x;
        meio = *y;
        menor = *z;
        sinal = 1;
    }

    *x = menor;
    *y = meio;
    *z = maior;

    return sinal;
}

int main(void){
    int x,y,z, sinal;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    sinal = ordena(&x,&y,&z);

    if (sinal == 0){
        printf("\nOs valores sao diferentes");
    }
    else{
        printf("\nOs valores sao iguais");
    }

    printf("\nMaior Valor = %d\nValor do Meio = %d\nMenor Valor = %d", z,y,x);

    return 0;
}
