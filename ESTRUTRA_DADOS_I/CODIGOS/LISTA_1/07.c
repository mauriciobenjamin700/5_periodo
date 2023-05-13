void func(int *a, int *b){
    *a = *a + *b;

}

#include <stdio.h>

int main(void){

    int x,y;

    printf("\n informe um valor para x: ");
    scanf("%d", &x);

    printf("\ninforme um valor para y: ");
    scanf("%d", &y);

    printf("A soma dde %d com %d -> ", x,y);
    func(&x,&y);
    printf("%d", x);


    return 0;
}
