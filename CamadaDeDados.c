#include <stdio.h>
#include "AuxCDD.h"

/* Algo do genero */  

typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
	int coluna;
	int linha;} 
	COORDENADA;
	typedef struct {
		COORDENADA jogador1;
		COORDENADA jogador2;
	} JOGADA;
	typedef JOGADA JOGADAS[32];
	typedef struct {
		CASA tab[8][8];
		COORDENADA ultima_jogada;
		JOGADAS jogadas;
		int num_jogadas;
		int jogador_atual;
	} ESTADO;


/*
tab armazena informação sobre o tabuleiro;

ultima_jogada a coordenada da última jogada

jogadas armazena informação sobre as jogadas

num_jogadas indica quantas jogadas foram efetuadas

jogador_atual indica qual é o jogador a jogar*/