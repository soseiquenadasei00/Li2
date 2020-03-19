#include <stdio.h>
#include "camadaDeDados.h"

int jogar(ESTADO *e, COORDENADA x) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[x.linha][x.letra]='*';
    return 1;
}

/*int pecaPreta (ESTADO *e COORDENADA c){
    e->C='#';
    return 1;
}*/