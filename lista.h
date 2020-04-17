#ifndef LI2_LISTA_H
#define LI2_LISTA_H
#include "camadaDeDados.h"
typedef struct lista {
    void *valor;
    struct lista *prox;
}*LISTA;


LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);

#endif //LI2_LISTA_H
