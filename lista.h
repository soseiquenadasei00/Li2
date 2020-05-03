#ifndef LI2_LISTA_H
#define LI2_LISTA_H
/**
 * \brief
 * Struct de lista ligada generalizada, ou seja, com void.
 */
typedef struct lista {
    /**
     * Void no qual a lista ligada pode receber qualquer tipo
     */
    void *valor;
    /**
     * Da o proximo da lista
     */
    struct lista *prox;
}*LISTA;

/**
 * Funções criadas no .c
 * @return
 */
LISTA criar_lista();
LISTA proximo(LISTA *l);
void freeList(LISTA *l);
void insere_cabeca(LISTA *l, void *valor);
void remove_cabeca(LISTA *l);
int lista_vazia(LISTA l);
int tamanho_lista(LISTA l);
#endif //LI2_LISTA_H