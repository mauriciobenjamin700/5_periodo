#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"fazenda.h"
#include"criador.h"

int main()
{
    Criador *p;
    Fazenda *p2;
    int idFazenda = 0, idcriador = 0;

    p = criarListaDuplaCriadores();
    p = cadastrarCriador(p);
    //p = cadastrarCriador(p);
    //p = cadastrarCriador(p);
    mostrarCriador(p);
    
    printf("id do criador: ");
    scanf("%d", &idcriador);
    p = alterarFz(p, idcriador);

    mostrarCriador(p);

    printf("id do criador da fazenda: ");
    scanf("%d", &idcriador);
    //removerFazenda(p2,idFazenda);
    removerFz(p,idcriador);
    mostrarCriador(p);
    
    //removerFazenda(p2, idFazenda);

    //liberarMemoria(p2);
    //mostrarCriador(p);
    }
