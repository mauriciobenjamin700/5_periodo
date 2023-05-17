#include <stdio.h>
/*
1. Crie um algoritmo que recebe entradas inteiras do usuário até um momento que ele digitar um valor 
X que servirá como parada. X = -1, lembrando que o valor de X não pode ser contabilizado para nada 
(somatório, média, menor valor, maior valor...). Ao final, o algoritmo deverá informar:
a. O valor do somatório de todos os números;
b. O valor da média de todos os números;
c. O menor e o maior números informados;
*/

int main(){

    int parada_x, somatorio = 0, media = 0, menor = 0, maior = 0, contador_numeros = 0;

    parada_x = 1;

    while(parada_x != -1)
    {
        printf("Digite um valor inteiro: ");
        scanf("%d", &parada_x);

        if (parada_x == -1){
            printf("\nPrograma encerrado, digitou -1\n");
        }
        // if's and else's para testar os casos 
        else {
            somatorio += parada_x;
            contador_numeros += 1;
            //Não consegui pensar numa solução melhor, ta tarde da noite ja
            if (menor==0){
                menor = parada_x;
            }

            else if (menor > parada_x){
                menor = parada_x;
            }

            if (maior < parada_x){
                maior = parada_x;
            }
            }
        }

    media = somatorio/contador_numeros;

    printf("Letra A -> %d\n", somatorio);
    printf("Letra B -> %d\n", media);
    printf("Letra C:\n Menor -> %d\n Maior -> %d", menor, maior);
    

    return 0;
}