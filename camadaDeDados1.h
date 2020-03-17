
#ifndef TRABALHOLI2_CAMADADEDADOS_H
#define TRABALHOLI2_CAMADADEDADOS_H

//Pq não é possivel alterar 'VAZIA' para '.' direto no typedef?
typedef enum {VAZIA,PRETA,BRANCA} CASA;

//COORDENADA há dois inteiros sendo eles para identificar as colunas=letras (A-H) e as linhas de (1-8) de baixo para cima.
typedef struct {
    int letra;
    int linha;
} COORDENADA;

//Typedef no qual busca quais as coordenas que o jogador 1 ou jogador 2
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];
//Informações do estado tab(tabuleiro), numero de jogadas (começa no 0), jogador atual (começa no jogador 1)
typedef struct {
    CASA tab[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;
//Funções
int numeroJogadas (ESTADO *e);
int JogAtual (ESTADO *e);
CASA estadoDaPeca (ESTADO *e ,COORDENADA *x);
ESTADO *inicializar_estado();

#endif //TRABALHOLI2_CAMADADEDADOS_H
