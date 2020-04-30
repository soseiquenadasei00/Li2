#ifndef LI2_CAMADADEDADOS_H
#define LI2_CAMADADEDADOS_H
#include "lista.h"
/**
 * Typedef para valores da CASA, todos são char
 */
typedef enum {UM='1',DOIS='2',VAZIA='.',PRETA='#',BRANCA='*'} CASA;
/**COORDENADA há dois inteiros sendo eles para identificar as colunas=letras (A-H) e as linhas de (1-8).*/
typedef struct {
    int letra;
    int linha;
    char letrinha;
} COORDENADA;

/**Typedef no qual busca quais as coordenas que o jogador 1 ou jogador 2*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**Typedef para jogadas,sendo limitadas em 32 jogadas total */
typedef JOGADA JOGADAS[32];
/**Informações do estado tab(tabuleiro), numero de jogadas (começa no 0), jogador atual (começa no jogador 1)*/
typedef struct {
    CASA tab[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
    int count_jog;
    int count_mov;
    int count_movs;
    int num;
    int qntjogs;
    COORDENADA possiveis_jog[8];
    COORDENADA ultima_jogada;
    //COORDENADA possivel_jogada;
} ESTADO;

/** Funções feita no .c*/
ESTADO *inicializar_estado();
void tabuleiro_inicial(ESTADO *e);
//void checaCasa (ESTADO *e, COORDENADA c, CASA h);

#endif //LI2_CAMADADEDADOS_H
