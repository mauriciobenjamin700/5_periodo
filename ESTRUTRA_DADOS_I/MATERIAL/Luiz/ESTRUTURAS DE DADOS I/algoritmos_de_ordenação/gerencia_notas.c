#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[100];
    float nota[3];
} Aluno;

void imprimir(Aluno *lista, int tam);
void ordenar(Aluno *lista, int tam);

int main(){
    Aluno* lista = (Aluno*) malloc(sizeof(Aluno));
    int tam = 0;
    
    while(scanf("%s", lista[tam].nome) != EOF){
        scanf("%f", &lista[tam].nota);
        tam++;
        lista = (Aluno*) realloc(lista, sizeof(Aluno) * (tam + 1));
    }
    
    imprimir(lista, tam);
    ordenar(lista, tam);
    imprimir(lista, tam);
    
    return 0;
}

void ordenar_Nomes(Aluno *lista, int tam){
    int i, j;
    Aluno aux;

    for(i = 1; i < tam; i++){
        aux = lista[i];

        for(j = i - 1; j >= 0 && lista[j].nome != aux.nome; j--){
            lista[j + 1] = lista[j];
        }
        lista[j + 1] = aux;
    }
}

void ordenar_Notas(Aluno *lista, int tam){
    int i, j;
    Aluno aux;
    
    for(i = 1; i < tam; i++){
        aux = lista[i];
        
        for(j = i - 1; j >= 0 && lista[j].nota > aux.nota; j--)
            lista[j + 1] = lista[j];
        
        lista[j + 1] = aux;
    }
}

void imprimir(Aluno *lista, int tam){
    int i;
    
    printf("%-10s%-5s\n", "NOME", "NOTA");
    
    for(i = 0; i < tam; i++)
        printf("%-10s%-5.2f\n", lista[i].nome, lista[i].nota);
}