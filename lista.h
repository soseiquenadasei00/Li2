#ifndef LI2_LISTA_H
#define LI2_LISTA_H

typedef struct lista {
    void *valor;
    struct lista *prox;
}*LISTA;

// Função criada para a struct do bot
LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);

#endif //LI2_LISTA_H
