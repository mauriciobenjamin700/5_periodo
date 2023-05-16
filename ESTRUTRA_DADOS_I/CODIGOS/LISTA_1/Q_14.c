#include <stdio.h>

int monta_array(int* array,int* value){
    /*int len = sizeof(*array)/sizeof(*array);*/
    int i,*pt;
    pt = array;
    for(i=0;i<3;i++){
        *pt = *value;
        pt++;
    }
    return 0;
}

int main(void){
    int a[3] = {0},b = 2;
    monta_array(a,&b);
    printf("%d\n%d\n%d\n",a[0],a[1],a[2]);
    return 0;
}