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

int max (int x, int y)
{
    if (x >= y) return x;
    else return y;
}

int min (int x, int y)
{
    if (x <= y) return x;
    else return y;
}


int possiveis_jogadas(ESTADO *e)
{
    int count = 0, i, j;

    i = max((e->ultima_jogada.linha - 1), 0);
    j = max((e->ultima_jogada.letra - 1), 0);

    while (i <= min((e->ultima_jogada.linha + 1), 7))
    {
        while( j <= min((e->ultima_jogada.letra + 1), 7))
        {
            if (e->tab[i][j] == VAZIA) count++;
            j++;
        }
        i++;
        j = max((e->ultima_jogada.letra - 1), 0);
    }
    return count;

}

//int validacao_jog (COORDENADA cAntes, COORDENADA cJog)




int checar_coordenada(COORDENADA cAntes, COORDENADA cJog)
{
    int x, y;

    x = abs(cAntes.linha - cJog.linha);
    y = abs(cAntes.letra - cJog.letra);

    if ((x==1 && (y==1||y==0)) || (y==1 && (x==1||x==0))) return 1;
}