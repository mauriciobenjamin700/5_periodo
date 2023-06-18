#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int *v, *v2, m, x, cont=0;
    printf("Insira o numero de posições para o vetor: ");
    scanf("%d", &m);
    printf("Os numeros devem variar de 0-X, informe o X: ");
    scanf("%d", &x);

    v = (int*)malloc(m*sizeof(int));

    if (v == NULL){
        printf("Memoria insuficiente");
        exit(1);
    }

    for(int i = 0; i < m; i++)
        v[i] = rand() % x;

    for(int i = 0; i < m; i++)
        v2[v[i]]++;

    for(int i = 0; i < x; i++)
        printf("O valor %d ocorreu %d vezes\n", i, v2[i]);

    return 0;
}