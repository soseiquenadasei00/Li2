#ifndef TRABALHOLI2_CAMADADEDADOS_H
#define TRABALHOLI2_CAMADADEDADOS_H
typedef enum {'.','*', '#'} CASA;

typedef struct {
    int letra;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;
//Funções
int numeroJogadas (ESTADO e*);
int JogAtual (ESTADO e*);
CASA estadoDaPeca (ESTADO *e ,COORDENADA *x);
ESTADO *inicializar_estado();

#endif //TRABALHOLI2_CAMADADEDADOS_H
