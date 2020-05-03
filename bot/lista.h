//
// Created by pedro on 02/05/20.
//

#ifndef LI2PL1G02_LISTA_H
#define LI2PL1G02_LISTA_H
/**
 * \brief
 * Struct de lista ligada generalizada, ou seja, com void.
 */
typedef struct lista {
    void *valor;
    struct lista *prox;
}*LISTA;

// Função criada para a struct da lista ligada
LISTA criar_lista();
LISTA proximo(LISTA *l);
void freeList(LISTA *l);
void insere_cabeca(LISTA *l, void *valor);
void remove_cabeca(LISTA *l);
int lista_vazia(LISTA l);
int tamanho_lista(LISTA l);
#endif //LI2PL1G02_LISTA_H
