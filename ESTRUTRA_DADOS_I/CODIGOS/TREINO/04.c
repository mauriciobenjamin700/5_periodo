#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função recursiva que receba um valor inteiro x e o retorne invertido. 
Exemplo: se x = 123, a função deve retornar 321.
*/
int tamanho(int numero){
  int contagem=0;
  while(numero != 0){
      numero /= 10;
      contagem++;
                    }
  return contagem;
}


int converte(int x, int tamanho){
  char vetor_x[tamanho];
  
  sprintf(vetor_x,"%d",x);

  return vetor_x;
}


int main(void) {
  int x;
  int tamanho_x;
  int **ponteiro;

  printf("Digite um numero: ");
  scanf("%d", &x);

  tamanho_x = tamanho(x);

  ponteiro = converte(x,tamanho_x);

  printf("%s", **ponteiro);

  return 0;
}
