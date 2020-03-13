#include "CamadaDeDados.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA x) {
    printf("jogar %d %d\n", x.letra, x.linha);
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[x.letra][x.linha]=BRACA;
    return 1;
}
