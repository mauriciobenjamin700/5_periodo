#include <stdio.h>
#include <stdlib.h>

#include "pontuacao.h"

struct pontuacao{
	int entregas;
	float pontos, media;
};

Pontuacao *criarEscore(){
	Pontuacao *score = (Pontuacao*) calloc(1, sizeof(Pontuacao));
	
	return score;
}

void alterarEscore(Pontuacao **score, float pontos){
	(*score)->pontos += pontos;
	(*score)->entregas++;
}

void imprimirEscore(Pontuacao **score){
	printf("Pontuacao:\n\n\tEntregas: %d\n\tPontos: %.2f\n\tMedia: %.2f\n\n", (*score)->entregas, (*score)->pontos, (*score)->media);
}

