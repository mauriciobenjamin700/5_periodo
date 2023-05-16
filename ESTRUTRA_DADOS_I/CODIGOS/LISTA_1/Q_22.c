#include <stdio.h>
#define TAM 5
int soma_array(int *A,int *B,int *C, int tamA,int tamB);

int main(void) {
    int a[TAM] = {0,1,2,3,4},b[TAM] = {9,8,7,6,5},c[TAM] = {},i;
    printf("%d\n",soma_array(a,b,c, sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0])));
    
    for(i=0;i < TAM; i++){
        printf("%d\n",c[i]);
    }

    return 0;
}

int soma_array(int *A,int *B,int *C,int tamA,int tamB){
    int i;
    if(tamA == tamB){
        for(i=0;i<tamA;i++){
            *C = *A + *B;
            A++;
            B++;
            C++;
        }
        return 1;
    }else{
        return 0;
    }
}