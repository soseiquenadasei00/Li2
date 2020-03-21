#include <stdio.h>
#include <stdlib.h>
#include "camadaDeDados.h"
#include "interface.h"

int jogar(ESTADO *e, COORDENADA c) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado

    char parabens1[] = "Parabéns Jogador 1!! Você venceu!!" ;
    char parabens2[] = "Parabéns Jogador 2!! Você venceu!!";

    e->tab[c.linha][c.letra]='*';

    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;
    e->tab[c.linha][c.letra] = BRANCA;

    e->ultima_jogada.linha = c.linha;
    e->ultima_jogada.letra = c.letra;

    if (e -> tab[7][0] == BRANCA) {
        printf("%s",parabens1);
        return 0;
    }
    if (e -> tab[0][7] == BRANCA){
        printf("%s",parabens2);
        return 0;
    }

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
int casa_viz(COORDENADA cAntes, COORDENADA cJog)
{
    int x, y;

    x = abs(cAntes.linha - cJog.linha);
    y = abs(cAntes.letra - cJog.letra);

    if ((x==1 && (y==1||y==0)) || (y==1 && (x==1||x==0))) return 1;
}

int casa_livre (ESTADO *e, COORDENADA c)
{
    if (e->tab[c.linha][c.letra] != PRETA && e->tab[c.linha][c.letra] != BRANCA) return 1;
}




