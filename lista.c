#include <stdio.h>
#include <stdlib.h>
#include "camadaDeDados.h"
#include "lista.h"


LISTA criar_lista(){
   LISTA d = NULL;
   return d;
}


LISTA insere_cabeca(LISTA L, void *valor) {
    LISTA d = malloc(sizeof(struct lista));
    d->valor = valor;
    d->prox = L;
    return d;
}


void *devolve_cabeca(LISTA L){
    LISTA d = malloc(sizeof(struct lista));
    d->valor = L->valor;
    d->prox=NULL;
    return d;

}
LISTA proximo(LISTA L){
    LISTA r = L -> prox;
    return r;
}

LISTA remove_cabeca(LISTA L){
    LISTA r = L -> prox;
    free(L);
    return r;
}

int lista_esta_vazia(LISTA L){
    if (L == NULL) return 1;
    return 0;
}