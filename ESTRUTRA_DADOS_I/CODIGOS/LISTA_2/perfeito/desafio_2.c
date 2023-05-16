#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
    int x,total_intens=0, *array,i;
    array = (int *) malloc(total_intens * sizeof(int));

    printf("\nDigite um valor para X: ");
    scanf("%d", &x);

    while(x != -1)
    {
        total_intens ++;
        array = (int *) realloc(array,total_intens * sizeof(int));

        array[total_intens-1] = x;
        

        printf("\nDigite um valor para X: ");
        scanf("%d", &x);
    }

    //alternativas
    int somatorio=0, menor=0,maior=0;
    float media=0;

    //letra A & C ao mesmo tempo
    for(i=0;i<total_intens;i++)
    {

        somatorio += array[i];

        if (menor==0 && maior ==0){
            menor = array[i];
            maior = array[i];
        }
        else{
            if (array[i]>maior){
                maior = array[i];
            }
            if (array[i]<menor){
                menor = array[i];
            }
        }
    }
    printf("\nSomatorio dos valores == %d", somatorio);

    //Letra B
    media = somatorio/total_intens;
    printf("\nMedia dos valores == %.2f", media);
    

    //Letra C
    printf("\nMenor valor == %d\nMaior valor == %d", menor,maior);


    //Letra D
    for(i=0;i<total_intens;i++){
        printf("\nVetor na posicao %d possui valor %d", i,array[i]);
    }
    
    free(array);
    return 0;
    }
