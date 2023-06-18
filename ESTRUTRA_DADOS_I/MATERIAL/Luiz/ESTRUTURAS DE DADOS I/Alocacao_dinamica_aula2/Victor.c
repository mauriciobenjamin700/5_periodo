#include<stdio.h>
#include<stdlib.h>

int main(){
    int *v= NULL,num=0,count=0,total=0;

    for(int i=0; scanf("%d",&num) && num!=-1; i++){
        count++;
        v = (int*) realloc(v, sizeof(int) * count);
        v[i] = num;
    } 
    for(int i=0; i < count; i++){
        total += v[i];
    }
    printf("%d", total);
    printf("%d", count);
    printf("Media:%2.f",(float)total/count);
    free(v);

    return 0;
}