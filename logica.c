#include <stdio.h>
#include "camadaDeDados.h"

int jogar(ESTADO *e, COORDENADA x) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[x.linha][x.letra]='*';

    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;

    e->tab[x.linha][x.letra] = BRANCA;

    return 1;
}