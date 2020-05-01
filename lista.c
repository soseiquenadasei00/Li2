#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * Função que cria uma lista vazia
 * @return
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
 * Devolve a cabeça da lista
 * @param L lista ligada
 * @return
 */
void *devolve_cabeca(LISTA L){
    return L->valor;}

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
 * Remove o primeiro elemento da lista
 * @param L
 * @return
 */
void remove_cabeca(LISTA *l){
    LISTA r = (*l) -> prox;
    free(*l);
    (*l) = r;
}
/**
 * Devolve true se a lista estiver vazia e false para quando não estiver fazia
 * @param L
 * @return
 */
int lista_esta_vazia(LISTA L){
    if (L == NULL) return 1;
    return 0;
}
void freeList(LISTA *l)  {
    LISTA current = (*l);

    while (current != NULL)
    {
        current = (*l) -> prox;
        free(*l);
        (*l) = current;
    }
}
