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
#include <windows.h>

#define SIZE 1000000

#define TRY 30

//retorna tempo de execução em milissegundos
double diffTime(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER frenquency)
{
    // Calcula o tempo decorrido
    double time_taken = (end.QuadPart - start.QuadPart) * 1000.0 / frenquency.QuadPart;
    return time_taken;
    //printf("%lf segundos\n", time_taken);
}



int main(void)
{
    int vetor1[SIZE], vetor2[SIZE], vetor3[SIZE];
    int num,i=0,j=0;
    //planejo fazer um vetor de double para armazenar os resultados e depois salvar em arquivos
    double result1[TRY], result2[TRY], result3[TRY];
    
    //frequencia do sistema operacional
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);

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

        QueryPerformanceCounter(&start);
        bubbleSort(vetor1,SIZE);
        QueryPerformanceCounter(&end);
        result1[j] = diffTime(start, end, frequency);
        /*
        printf("\nBUBBLE SORT: ");
        printf("%lf segundos\n", diffTime(start, end));
        */

        QueryPerformanceCounter(&start);
        insertionSort(vetor2,SIZE);
        QueryPerformanceCounter(&end);
        result2[j] = diffTime(start, end, frequency);
       
        /*
        printf("\nINSERTION SORT: ");
        printf("%lf segundos\n", diffTime(start, end));
        */

        QueryPerformanceCounter(&start);
        selectionSort(vetor3,SIZE);
        QueryPerformanceCounter(&end);
        result3[j] = diffTime(start, end, frequency);
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