#include <stdio.h>
#include <stdlib.h>

int main(void){
    int inteiro, *ponteiro_inteiro;
    float real, *ponteiro_real;
    char caracter, *ponteiro_caracter;

    ponteiro_inteiro = &inteiro;
    ponteiro_real = &real;
    ponteiro_caracter = &caracter;
    

    printf("\nDigite um valor inteiro: ");
        scanf("%d", &inteiro);
    printf("\nDigite um valor Real: ");
        scanf("%f", &real);
    printf("\nDigite um valor Caracter: ");
        scanf("%s", &caracter);

    printf("\nInteiro: %d \nReal: %.2f\nCaracter: %c \n", inteiro,real,caracter);

    printf("Modificarei os valores!!!\n");

    
    printf("\nDigite um valor inteiro: ");
        scanf("%d", ponteiro_inteiro);
    printf("\nDigite um valor Real: ");
        scanf("%f", ponteiro_real);
    printf("\nDigite um valor Caracter: ");
        scanf("%s", ponteiro_caracter);


    printf("\nInteiro: %d \nReal: %.2f\nCaracter: %c \n", inteiro,real,caracter);

    return 0;
}
