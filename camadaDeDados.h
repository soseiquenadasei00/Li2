#ifndef LI2_CAMADADEDADOS_H
#define LI2_CAMADADEDADOS_H

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
    JOGADAS jogs_gravadas;
    int num_jog_grav;
    int num_jogadas;
    int jogador_atual;
    int count_jog;
    int count_mov;
    int num;
    COORDENADA ultima_jogada;
} ESTADO;
/** Funções feita no .c*/
int numeroJogadas (ESTADO *e);
int JogAtual (ESTADO *e);
CASA estadoDaPeca (ESTADO *e ,COORDENADA *x);
ESTADO *inicializar_estado();
void tabuleiro_inicial(ESTADO *e);

#endif //LI2_CAMADADEDADOS_H
