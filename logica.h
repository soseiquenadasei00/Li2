#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
#include "lista.h"
void movs(ESTADO *e, COORDENADA c);
void show_tab(FILE *f, ESTADO *e);
void prompt(ESTADO *e);
void jogar(ESTADO *e, COORDENADA c);
void parabens(int jogador);
void aux_mov(ESTADO *e);
void aux_movf(ESTADO *e,FILE *f);
void posf(ESTADO *e, int x);
void troca_jog(ESTADO *e);
void iniciar_estado(ESTADO *e);
void mudar_estado(ESTADO *e);
void insere_lista(LISTA *a,ESTADO *e);
void jog01(ESTADO *e, LISTA *l);
void jog02(ESTADO *e, LISTA *l);
int casa_viz(COORDENADA cAntes, COORDENADA cJog);
int casa_livre (ESTADO *e, COORDENADA c);
int possiveis_jogadas(ESTADO *e,LISTA *d);
int calcula_dist(COORDENADA c, ESTADO* e);
int verifica_jog(ESTADO e, COORDENADA c);
COORDENADA area_par(ESTADO *e, LISTA *l);
COORDENADA melhor_coord02(ESTADO e, LISTA *l);
#endif //LI2_LOGICA_H