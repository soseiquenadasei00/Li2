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


/*Pretende-se também que crie funções que alterem a estrutura de dados. Todas
estas funções devem receber um apontador para ESTADO e modificá-lo. Só
estas funções deverão alterar o estado! Todo o resto do programa só deverá
modificar o estado através destas funções. Segue-se um exemplo dos protótipos
das funções que deverão ser criadas (podendo existir outras):*/


ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);


/*
inicializar_estado Esta função deverá criar um estado vazio (com o tabuleiro
inicializado)

obter_jogador_atual Esta função permite obter o número do jogador atual

obter_estado_casa Esta função permite obter o estado atual da casa

obter_numero_de_jogadas Esta função permite obter quantas jogadas

foram efetuadas (cada jogada tem o movimento de dois jogadores)*/