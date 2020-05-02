#ifndef LI2_CAMADADEDADOS_H
#define LI2_CAMADADEDADOS_H
#include "lista.h"
/**
 * \brief
 * Typedef para valores da CASA, todos são char
 */
typedef enum {UM='1',DOIS='2',VAZIA='.',PRETA='#',BRANCA='*'} CASA;
/**
 * \brief
 * COORDENADA há dois inteiros sendo eles para identificar as colunas=letras (A-H),linhas de (1-8) e o letrinh é um char para utilizamos no movs e prompt .
 *
 */
typedef struct {
    int letra;
    int linha;
    char letrinha;
} COORDENADA;

/**
 * \brief
 * Typedef no qual busca quais as coordenas que o jogador 1 ou jogador 2
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
 * \brief
 * Typedef para jogadas,sendo limitadas em 32 jogadas total, sendo cada jogada 2 coordenada
 * */
typedef JOGADA JOGADAS[32];
/**
 * \brief
 * Informações do estado tab(tabuleiro), numero de jogadas (começa no 0), jogador atual (começa no jogador 1)
 * */
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
} ESTADO;

/*Funções feita no .c*/
ESTADO *inicializar_estado();
void tabuleiro_inicial(ESTADO *e);
#endif //LI2_CAMADADEDADOS_H
