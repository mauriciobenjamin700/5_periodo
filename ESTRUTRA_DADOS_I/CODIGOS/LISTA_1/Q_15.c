#include <stdio.h>

int imprimir(int* array){
    int i,*pt;
    pt = array;
    for(i=0;i<3;i++){
        printf("%d ",*pt);
        pt++;
    }
    return 0;
}

int main(void){
    int a[3] = {1,2,3};
    imprimir(a);
    return 0;
}