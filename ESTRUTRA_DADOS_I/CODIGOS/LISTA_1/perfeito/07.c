#include <stdio.h>

void func(int *a, int *b)
{
    *a = *a + *b;

}

int main(void)
{

    int x,y;

    printf("\nInforme um valor inteiro para x: ");
    scanf("%d", &x);

    printf("\nInforme um valor inteiro para y: ");
    scanf("%d", &y);

    printf("A soma de %d com %d -> ", x,y);
    
    func(&x,&y);
    
    printf("%d", x);

    return 0;
}