#ifndef LI2_CAMADADEDADOS_H
#define LI2_CAMADADEDADOS_H
#include "lista.h"
/**
 * \brief
 * Typedef para valores da CASA, todos são char
 */
typedef enum {UM='1',DOIS='2',VAZIA='.',PRETA='#',BRANCA='*'} CASA;
/**
 * COORDENADA há dois inteiros sendo eles para identificar as colunas=letras (A-H),linhas de (1-8) e o letrinh é um char para utilizamos no movs e prompt .
 */
typedef struct {
    /**
     * Coluna do tabuleiro
     */
    int letra;
    /**
     * Linhas do tabuleiro
     */
    int linha;
    /**
     * Char utilizado para o prompt e movs
     */
    char letrinha;
} COORDENADA;

/**
 * \brief
 * Typedef no qual busca quais as coordenas que o jogador 1 ou jogador 2
 */
typedef struct {
    /**
     * Coordenada do jogador 1
     */
    COORDENADA jogador1;
    /**
     * Coordenada do jogador 2
     */
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
    /**
     * Tabuleiro no qual realizamos as jogadas
     */
    CASA tab[8][8];
    /**
     * Array conte todas as jogadas feitas
     */
    JOGADAS jogadas;
    /**
     * Numero de jogadas
     */
    int num_jogadas;
    /**
     * Jogador atual
     */
    int jogador_atual;
    /**
     * Contador para a troca de jogador
     */
    int count_jog;
    /**
     * Contador para todos os movimentos do jogo
     */
    int count_mov;
    /**
     * Contador para os movimentos sendo auxiliar para a funcionalidade do estado
     */
    int count_movs;
    /**
     * Caso de paragem
     */
    int num;
    /**
     * Conta quantas possiveis jogadas
     */
    int qntjogs;
    /**
     * Array com as possiveis coordenadas
     */
    COORDENADA possiveis_jog[8];
    /**
     * Coordenada da ultima jogada
     */
    COORDENADA ultima_jogada;
} ESTADO;

/*Funções feita no .c*/
ESTADO *inicializar_estado();
void tabuleiro_inicial(ESTADO *e);
#endif //LI2_CAMADADEDADOS_H