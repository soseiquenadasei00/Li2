#include <stdio.h>
#include "camadaDeDados.h"

int jogar(ESTADO *e, COORDENADA x) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[x.linha][x.letra]='*';
    return 1;
}

int pecaPreta(ESTADO *e, COORDENADA c){

    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;

    e->tab[c.linha][c.letra] = BRANCA;

    e->ultima_jogada.linha = c.linha;
    e->ultima_jogada.letra = c.letra;


    return 1;
}