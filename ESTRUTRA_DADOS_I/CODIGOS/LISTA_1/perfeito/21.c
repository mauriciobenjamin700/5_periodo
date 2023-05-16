#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int array[5] = {1,2,3,4,5},*ponteiro,i,tamanho;
    ponteiro = array;
    tamanho = sizeof(array)/sizeof(array[0]);
    for(i=0;i<tamanho;i++)
	{
        *ponteiro += 1;
        printf("%d\n",*ponteiro);
        ponteiro++;
    }
    return 0;
}