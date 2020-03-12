#include <stdlib.h>
#include "CamadaDeDados.h"



ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;


    return e;
}
