#include <stdio.h>

int maior(int A[], int tamA);

int main(void) {
    int N,i,k;
    printf("Tamanho do Array:");
    scanf("%d", &N);
    int Array[N],*p;
    p = Array;
    for(i=0;i<N;i++){
        scanf("%d", &Array[i]);
    }

    printf("Quantos numeros por linha?");
    scanf("%d", &k);

    while(N != 0){
        N -= k;
        if(N < 0){
            N += k;
            for(i=0;i<N;i++){
                printf("%d ", *p);
                p++;
            }
            break;
        }

        for(i=0;i<k;i++){
            printf("%d ", *p);
            p++;
        }
        printf("\n");
        
    }

    printf("\nMaior:%d",maior(Array,sizeof(Array)/sizeof(Array[0])));

    return 0;
}

int maior(int A[], int tamA){
    int m = 0,i;

    for(i=0;i<tamA;i++){
        if(A[i] > m){
            m = A[i];
        }
    }
    return m;
}