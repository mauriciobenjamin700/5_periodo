#include <stdio.h>
#include <string.h>

int verificaSubstring(char *str1, char *str2) {
    if (strstr(str1, str2) != NULL) {
        return 1; // A segunda string ocorre dentro da primeira
    } else {
        return 0; // A segunda string não ocorre dentro da primeira
    }
}

int main() {
    char str1[100];
    char str2[100];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    if (verificaSubstring(str1, str2)) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string não ocorre dentro da primeira.\n");
    }

    return 0;
}
/*
Neste exemplo, a função verificaSubstring chama a função strstr para procurar a ocorrência da segunda string dentro da primeira string. A função strstr retorna um ponteiro para a primeira ocorrência da segunda string dentro da primeira string, ou NULL se a segunda string não for encontrada.

No main(), a entrada das strings e a impressão do resultado são feitas da mesma maneira que no exemplo anterior. Agora, a função verificaSubstring utiliza a função strstr para verificar se a segunda string ocorre dentro da primeira. Se strstr retornar um ponteiro diferente de NULL, isso significa que a segunda string foi encontrada e a função retorna 1. Caso contrário, a função retorna 0.

Essa abordagem é mais simples e eficiente para verificar a ocorrência de uma substring em uma string em comparação com a aritmética de ponteiros, pois a função strstr é otimizada para esse propósito específico.
*/