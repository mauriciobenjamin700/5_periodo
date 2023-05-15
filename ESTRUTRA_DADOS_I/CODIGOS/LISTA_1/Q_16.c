#include <stdio.h>

int main(void) {
    int a,*b,**c,***d;
    scanf("%d",&a);
    b = &a;
    c = &b;
    d = &c;

    *b = a*2;
    printf("%d\n",*b);
    **c = *b+(*b/2);
    printf("%d\n",**c);
    ***d = **c+(**c/3);
    printf("%d\n",***d);

    return 0;
}