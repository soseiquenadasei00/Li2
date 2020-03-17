#include "CamadaDeDados.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA x) {
    printf("jogar %d %d\n\n", x.letra, x.linha);
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[x.linha][x.letra]='*';
    return 1;
}