#include <stdio.h>
#include <stdio.h>

struct notas
{
    float media_simples,media_ponderada,nota1,nota2;
};

struct notas ler_notas(struct notas n)
{
    printf("\nDigite a nota 1: ");
    scanf("%f",&n.nota1);
    printf("\nDigite a nota 2: ");
    scanf("%f",&n.nota2);

    return n;
}

struct notas calcula_notas(struct notas n)
{
    n.media_simples = (n.nota1+n.nota2)/2;
    n.media_ponderada = (n.nota1+n.nota2*2)/3;

    return n;
}

int main(void)
{

    struct notas n;
    n = calcula_notas(ler_notas(n));
    printf("Nota 1: %.2f\nNota 2: %.2f\nMedia Simples: %.2f\nMedia Ponderada: %.2f\n",n.nota1,n.nota2,n.media_simples,n.media_ponderada);
    return 0;
}