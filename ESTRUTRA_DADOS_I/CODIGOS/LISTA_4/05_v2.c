#include <stdio.h>
#include <math.h>
#include <locale.h>

float calcularJurosCompostos(float valorInicial, int numMeses, float taxaJuros) {
    if (numMeses == 0) {
        return valorInicial;
    } else {
        float juros = calcularJurosCompostos(valorInicial, numMeses - 1, taxaJuros);
        return juros * (1 + taxaJuros);
    }
}

int main() {
    float valorInicial, taxaJuros;
    int numMeses;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("Digite o valor inicial: ");
    scanf("%f", &valorInicial);

    printf("Digite o número de meses: ");
    scanf("%d", &numMeses);

    printf("Digite a taxa de juros ao mês (em decimal): ");
    scanf("%f", &taxaJuros);

    float valorFinal = calcularJurosCompostos(valorInicial, numMeses, taxaJuros);

    printf("Valor final após %d meses: %.2f\n", numMeses, valorFinal);

    return 0;
}
