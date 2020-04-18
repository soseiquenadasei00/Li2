#include <stdio.h>
#include <stdlib.h>
#include "camadaDeDados.h"
#include "lista.h"

/**
 * Função que cria uma lista vazia
 * @return
 */
LISTA criar_lista(){
   LISTA d;
   d=NULL;
   return d;
}

/**
 * Insere na cabeça da lista o valor
 * @param L lista ligada
 * @param valor void
 * @return
 */
LISTA insere_cabeca(LISTA L, void *valor) {
    LISTA d = malloc(sizeof(struct lista));
    d->valor = valor;
    d->prox = L;
    return d;
}

/**
 * Devolve a cabeça da lista
 * @param L lista ligada
 * @return
 */
void *devolve_cabeca(LISTA L){
    LISTA d = malloc(sizeof(struct lista));
    d->valor = L->valor;
    d->prox=NULL;
    return d;
/**
 * Insere na cabeça da lista o valor
 */
LISTA insere_cabeca(LISTA L, void *valor){
 LISTA d = malloc(sizeof (struct lista));

}
}
/**
 * Da o proximo valor da lista
 * @param L
 * @return
 */
LISTA proximo(LISTA L){
    LISTA r = L -> prox;
    return r;
}
/**
 * Remove o primeiro elemento da lista
 * @param L
 * @return
 */
LISTA remove_cabeca(LISTA L){
    LISTA r = L -> prox;
    free(L);
    return r;
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