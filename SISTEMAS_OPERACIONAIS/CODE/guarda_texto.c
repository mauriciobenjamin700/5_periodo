#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char sinal = ' ';
    int cont = 1;

    char *vetor = (char*) malloc(cont * sizeof(char));

    printf("Digite um valor caracter qualquer diferente de 'p': ");
    scanf(" %c", &sinal);

    while (sinal != 'p') {
    
        vetor[cont - 1] = sinal;
        cont++;
        vetor = (char*) realloc(vetor, cont * sizeof(char));
        
        printf("Digite um valor caracter qualquer diferente de 'p': ");
        scanf(" %c", &sinal);
    }

    vetor = (char*) realloc(vetor, cont * sizeof(char));
    vetor[cont - 1] = '\0';  // Adicionando o caractere nulo ao final do vetor

    printf("%s\n", vetor);

    free(vetor);

    return 0;
}
