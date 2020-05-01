#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * Função que cria uma lista vazia
 * @return lista
 */
LISTA criar_lista(){
   LISTA d = NULL;
   return d;
}
/**
 * Insere na cabeça da lista o valor
 * @param L lista ligada
 * @param valor void
 * @return
 */
void insere_cabeca(LISTA *l, void *valor) {
    LISTA d = malloc(sizeof(struct lista));
    d->valor = valor;
    d->prox = (*l);
    *l = d;
}
/**
 * Da o proximo valor da lista
 * @param L
 * @return
 */
LISTA proximo(LISTA *l){
    LISTA r = (*l) -> prox;
    return r;
}
/**
 * Esta função libera os elementos da lista
 * @param l lista ligada
 */
void freeList(LISTA *l)  {
    LISTA current = (*l);

    while (current != NULL)
    {
        current = (*l) -> prox;
        free(*l);
        (*l) = current;
    }
}