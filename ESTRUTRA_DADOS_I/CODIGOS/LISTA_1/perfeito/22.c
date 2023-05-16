#include <stdio.h>
#define TAMANHO 5

int soma_array(int *A,int *B,int *C,int tamanho_a,int tamanho_b)
{
    int i;
    if(tamanho_a == tamanho_b)
    {
        for(i=0;i<tamanho_a;i++)
        {
            *C = *A + *B;
            A++;
            B++;
            C++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void) {
    int a[TAMANHO] = {0,1,2,3,4},b[TAMANHO] = {5,6,7,8,9},c[TAMANHO] = {},i;
    printf("%d\n",soma_array(a,b,c, sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0])));
    
    for(i=0;i < TAMANHO; i++){
        printf("%d\n",c[i]);
    }

    return 0;
}

