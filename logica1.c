#include "CamadaDeDados.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.letra, c.linha);
    e->tab[c.letra][c.linha]='*';
    return 1;
}