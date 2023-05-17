#include <stdio.h>

int potencia(int x, int y) {
  if (y == 0) {
    return 1;
  } else {
    return x * potencia(x, y - 1);
  }
}

int main() {
  int x, y, resultado;
  
  printf("Digite a base: ");
  scanf("%d", &x);
  
  printf("Digite o expoente: ");
  scanf("%d", &y);
  
  resultado = potencia(x, y);
  printf("%d elevado a %d == %d\n", x, y, resultado);
  
  return 0;
}
