#include <stdio.h>

struct notas
{
    float media_simples,media_ponderada,nota1,nota2;
};

struct notas ler_notas(struct notas n);
struct notas calcula_notas(struct notas n);

int main(void){

    return 0;
}

struct notas ler_notas(struct notas n){
    scanf("%f",n.nota1);
    scanf("%f",n.nota2);

    return n;
}

struct notas calcula_notas(struct notas n){
    //Imagine uma continhas
}
