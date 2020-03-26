#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
int jogar(ESTADO *e, COORDENADA c);
int casa_viz(COORDENADA cAntes, COORDENADA cJog);
int casa_livre (ESTADO *e, COORDENADA c);
int possiveis_jogadas(ESTADO *e);
void parabens(int jogador);


#endif //LI2_LOGICA_H
