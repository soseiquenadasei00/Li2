#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H

void movs(ESTADO *e, COORDENADA c);
int jogar(ESTADO *e, COORDENADA c, char col[2], char lin[2]);
int casa_viz(COORDENADA cAntes, COORDENADA cJog);
int casa_livre (ESTADO *e, COORDENADA c);
int possiveis_jogadas(ESTADO *e);
void parabens(int jogador);
void aux_mov(ESTADO *e);
void aux_mov1(ESTADO *e,FILE *f);
#endif //LI2_LOGICA_H
