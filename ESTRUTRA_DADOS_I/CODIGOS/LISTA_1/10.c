#include <stdio.h>
#include <stdlib.h>

int main() {
    int SIZE = 5, array[SIZE];
    int *ptr;

    // Lê o array do teclado
    printf("Digite %d valores inteiros:\n", SIZE);
    for (ptr = array; ptr < array + SIZE; ptr++) {
        scanf("%d", ptr);
    }

    // Imprime o dobro de cada valor lido
    printf("O dobro dos valores lidos:\n");
    for (ptr = array; ptr < array + SIZE; ptr++) {
        printf("%d\n", *ptr * 2);
    }

    return 0;
}
