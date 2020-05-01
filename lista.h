#ifndef LI2_LISTA_H
#define LI2_LISTA_H
/**
 * \brief
 * Struct de lista ligada generalizada, ou seja, com void.
 */
typedef struct lista {
    void *valor;
    struct lista *prox;
}*LISTA;

// Função criada para a struct do bot
LISTA criar_lista();
LISTA proximo(LISTA *l);
void freeList(LISTA *l);
void insere_cabeca(LISTA *l, void *valor);

#endif //LI2_LISTA_H
