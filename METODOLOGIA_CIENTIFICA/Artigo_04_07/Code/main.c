/*
Você deverá coletar o tempo total de ordenação para um conjunto específico de números.
Procure utilizar uma base grande de números (milhões!), gere-os automaticamente.
Para cada algoritmo, em um mesmo computador, vocês irão executar 30 vezes e colher os
resultados
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"
#include "arquivo.c"


#define SIZE 100000

#define TRY 30

double diffTime(clock_t start, clock_t end)
{
    // Calcula o tempo decorrido
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return time_taken;
    //printf("%lf segundos\n", time_taken);
}



int main(void)
{
    int vetor1[SIZE], vetor2[SIZE], vetor3[SIZE];
    int num,i=0,j=0;
    //planejo fazer um vetor de double para armazenar os resultados e depois salvar em arquivos
    double result1[TRY], result2[TRY], result3[TRY];

    // Inicializa a semente com o valor do relógio do sistema
    srand(time(NULL));

    for(j=0;j<TRY;j++)
    {

        while (i<SIZE)
        {
            num = rand() % 10;  // Gera números aleatórios de 0 a 9
            vetor1[i] = num;
            vetor2[i] = num;
            vetor3[i] = num;

            i++;
        }
        
        // Mede o tempo de execução do Bubble Sort

        clock_t start = clock();
        bubbleSort(vetor1,SIZE);
        clock_t end = clock();
        result1[j] = diffTime(start, end);
        /*
        printf("\nBUBBLE SORT: ");
        printf("%lf segundos\n", diffTime(start, end));
        */

        start = clock();
        insertionSort(vetor2,SIZE);
        end = clock();
        result2[j] = diffTime(start, end);
       
        /*
        printf("\nINSERTION SORT: ");
        printf("%lf segundos\n", diffTime(start, end));
        */

        start = clock();
        selectionSort(vetor3,SIZE);
        end = clock();
        result3[j] = diffTime(start, end);
        /*
        printf("\nSELECTION SORT: ");
        printf("%lf segundos\n", diffTime(start, end));
        */

    }

    // salvando os dados em arquivos .txt
    criar(result1,TRY, "Resultado1.txt");
    criar(result2,TRY, "Resultado2.txt");
    criar(result3,TRY, "Resultado3.txt");

    system("PAUSE");
   

    return 0;
}