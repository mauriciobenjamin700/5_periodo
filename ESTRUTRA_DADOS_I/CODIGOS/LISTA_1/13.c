#include <stdio.h>

int verificaSubstring(char *str1, char *str2) {
    while (*str1 != '\0') {  // Enquanto não chegarmos ao final da primeira string
        char *p1 = str1;
        char *p2 = str2;

        while (*p1 == *p2 && *p2 != '\0') {  // Enquanto os caracteres são iguais e não chegamos ao final da segunda string
            p1++;
            p2++;
        }

        if (*p2 == '\0') {  // Se chegamos ao final da segunda string, encontramos a substring
            return 1;
        }

        str1++;  // Avança para o próximo caractere na primeira string
    }

    return 0;  // Não encontramos a substring
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
Nesse exemplo, a função verificaSubstring recebe dois ponteiros para caracteres (char *str1 e char *str2) que representam as duas strings. A função itera sobre a primeira string usando um loop while, e dentro desse loop, um segundo loop while é usado para comparar os caracteres da primeira e segunda strings.

Se os caracteres forem iguais e ainda não chegamos ao final da segunda string (*p2 != '\0'), avançamos para o próximo caractere nas duas strings (p1++ e p2++). Se chegarmos ao final da segunda string, isso significa que encontramos a substring e retornamos 1.

Caso contrário, se não encontrarmos a substring até o final da primeira string, retornamos 0.

No main(), o programa solicita ao usuário para inserir as duas strings e, em seguida, chama a função verificaSubstring para verificar se a segunda string ocorre dentro da primeira. O resultado é impresso no console.
*/