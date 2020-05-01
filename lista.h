#ifndef LI2_LISTA_H
#define LI2_LISTA_H

typedef struct lista {
    void *valor;
    struct lista *prox;
}*LISTA;

// Função criada para a struct do bot
LISTA criar_lista();
void insere_cabeca(LISTA *l, void *valor);
LISTA proximo(LISTA *l);
void freeList(LISTA *l);

#endif //LI2_LISTA_H
