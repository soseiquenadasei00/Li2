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

/**
 * Remove a cabeça da lista
 * @param l lista ligada
 */
void remove_cabeca(LISTA *l){
    LISTA current;
    current =(*l)-> prox;
    free(*l);
    (*l) = current;
}
/**
 * Verifica se a lista está vazia
 * @return 1 caso a lista esteja vazia
 */
int lista_vazia(LISTA l){
    if (l == NULL) return 1;
    return 0;
}
/**
 * Esta função calcula o tamanho da lista
 * @param l lista
 * @return tamanho da lista
 */
int tamanho_lista(LISTA l){
    int t=0;
    while (l){
        t++;
        l = l->prox;
    }
    return t;
}