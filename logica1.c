#include "CamadaDeDados.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
}