#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
#include "lista.h"

void movs(ESTADO *e, COORDENADA c);
void show_tab(FILE *f, ESTADO *e);
void prompt(ESTADO *e);
int jogar(ESTADO *e, COORDENADA c);
int casa_viz(COORDENADA cAntes, COORDENADA cJog);
int casa_livre (ESTADO *e, COORDENADA c);
int possiveis_jogadas(ESTADO *e,LISTA *d);
void parabens(int jogador);
void aux_mov(ESTADO *e);
void aux_movf(ESTADO *e,FILE *f);
void posf(ESTADO *e, int x);
void troca_jog(ESTADO *e);
void iniciar_estado(ESTADO *e);
void mudar_estado(ESTADO *e);
void insere_lista(LISTA *a,ESTADO *e);
int concat(int a, int b);
int tamanho_list(LISTA d);
void printl2(LISTA a);
void jogs(ESTADO *e,LISTA l);
int calcula_dist(int linha, int coluna, ESTADO* e);
COORDENADA melhor_coord(ESTADO *e, LISTA l);
void jog01(ESTADO *e, LISTA l);


//int printRandoms (int lower, int upper, int count);
//void jorge(ESTADO *e,LISTA l);
#endif //LI2_LOGICA_H
