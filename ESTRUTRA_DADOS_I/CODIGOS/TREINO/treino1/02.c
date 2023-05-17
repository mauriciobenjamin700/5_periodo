#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
2. Crie uma solução que recebe uma matriz de M x N (m = 200, n = 100) informados pelo usuário. Essa 
matriz será preenchida aleatoriamente de 0 a X (valor informado pelo usuário). Ao final o algoritmo 
deverá apresentar quantas vezes cada número contida na matriz ocorreu. Exemplo para uma matriz 
qualquer: [1, 0, 2, 3, 4, 1, 0, 9]: 
§ O número 0 ocorreu 2 vezes
§ O número 1 ocorreu 2 vezes
§ O número 2 ocorreu 1 vez
§ O número 3 ocorreu 1 vez
§ O número 4 ocorreu 1 vez
§ O número 9 ocorreu 1 vez
*/

int main(){
    int M = 200,N=100, X=0;
    int matrix[M][N];
    

    printf("Digite um valor para M: ");
    scanf("%d", &M);

    printf("\nDigite um valor para N: ");
    scanf("%d", &N);

    printf("\nDigite um valor para X: ");
    scanf("%d", &X);

    int occurrences[X+1];

    srand(time(NULL)); // inicializa o gerador de numeros aleatorios

     // preenche a matriz aleatoriamente
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % (X+1);
        }
    }

    // inicializa o array de ocorrencias com zeros
    for (int i = 0; i <= X; i++) {
        occurrences[i] = 0;
    }

    // conta as ocorrencias de cada numero na matriz
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num = matrix[i][j];
            occurrences[num]++;
        }
    }

    // imprime as ocorrencias de cada numero
    for (int i = 0; i <= X; i++) {
        if (occurrences[i] > 0){
            printf("%d ocorreu %d vezes\n", i, occurrences[i]);
        }
    }

    // Mostrando Matriz para comprovar o resultado pro pedro
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num = matrix[i][j];
            printf("%d ", num);
        }
        printf("\n");
        }
    return 0;
}

/*
Explicando o código, primeiro declaramos as variáveis M, N e X. M e N são definidas como 200 e 100, respectivamente, e X é lido do usuário através da função scanf.

Em seguida, criamos uma matriz matrix de tamanho M x N e um array occurrences de tamanho X+1 para armazenar a contagem de ocorrências de cada número na matriz.

Usamos a função srand(time(NULL)) para inicializar o gerador de números aleatórios com a hora atual do sistema, e então preenchemos a matriz aleatoriamente usando a função rand() % (X+1).

Depois, inicializamos o array occurrences com zeros e contamos as ocorrências de cada número na matriz percorrendo cada elemento da matriz e incrementando a posição correspondente no array occurrences.

Por fim, imprimimos as ocorrências de cada número no array occurrences.

Para testar o código, basta compilar e executar o programa.

*/