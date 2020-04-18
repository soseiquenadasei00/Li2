#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H

void movs(ESTADO *e, COORDENADA c);
void show_tab(FILE *f, ESTADO *e);
void prompt(ESTADO *e,COORDENADA c);
int jogar(ESTADO *e, COORDENADA c);
int casa_viz(COORDENADA cAntes, COORDENADA cJog);
int casa_livre (ESTADO *e, COORDENADA c);
int possiveis_jogadas(ESTADO *e);
void parabens(int jogador);
void aux_mov(ESTADO *e);
void aux_movf(ESTADO *e,FILE *f);
void posf(ESTADO *e, int x);
void troca_jog(ESTADO *e);
void iniciar_estado(ESTADO *e);
void mudar_estado(ESTADO *e);
//void acresList (ESTADO *e,COORDENADA c,LISTA d);
#endif //LI2_LOGICA_H
