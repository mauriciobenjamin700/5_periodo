#include <stdio.h>
#include <math.h>
#include <locale.h>

float juros_compostos(float montante, int num_meses, float taxa_juros) {
    if (num_meses == 0) 
    {
        return 0;
    } 
    else 
    {
        return (taxa_juros*montante) + juros_compostos(montante+(taxa_juros*montante), num_meses - 1, taxa_juros);

    }
}

int main() {
    float montante, taxa_juros;
    int num_meses;


    printf("Digite o valor inicial: ");
    scanf("%f", &montante);

    printf("Digite o numero de meses: ");
    scanf("%d", &num_meses);

    printf("Digite a taxa de juros ao mes (em decimal): ");
    scanf("%f", &taxa_juros);

    float rendimento = juros_compostos(montante, num_meses, taxa_juros);

    printf("\nValor final apos %d meses: %.2f\n\nRendeu %.2f", num_meses, rendimento+montante, rendimento);

    return 0;
}
