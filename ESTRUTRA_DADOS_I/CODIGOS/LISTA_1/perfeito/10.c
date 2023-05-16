#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int array[SIZE];
    int *ptr;

    printf("Digite %d valores inteiros:\n", SIZE);
    
    for (ptr = array; ptr < array + SIZE; ptr++) 
	{
        scanf("%d", ptr);
    }

    printf("O dobro dos valores lidos:\n");
    for (ptr = array; ptr < array + SIZE; ptr++) 
	{
        printf("%d\n", *ptr * 2);
    }

    return 0;
}