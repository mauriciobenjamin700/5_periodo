#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void){
    int array[SIZE];
    int *ponteiro;

    for (ponteiro=array; ponteiro < (array + SIZE); ponteiro++)
	{
        scanf("%d", ponteiro);
    }

    for (ponteiro=array; ponteiro < (array + SIZE); ponteiro++)
	{
        if ((*ponteiro%2)==0)
		{
            printf("\nO numero %d eh par, logo seu endereco e %p", *ponteiro, ponteiro);
        }
    }
    
    return 0;
}
