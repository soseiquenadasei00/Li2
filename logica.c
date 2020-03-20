#include <stdio.h>
#include <stdlib.h>
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


//int possiveis_jogadas(COORDENADA utljog){

}



int checar_coordenada(COORDENADA cAntes, COORDENADA cJog)
{
    int x, y;

    x = abs(cAntes.linha - cJog.linha);
    y = abs(cAntes.letra - cJog.letra);

    if ((x==1 && (y==1||y==0)) || (y==1 && (x==1||x==0))) return 1;
}