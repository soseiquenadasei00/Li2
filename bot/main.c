#include <stdio.h>
#include "aux.h"
#include "lista.h"
int main(int argc, char **argv) {

    ESTADO *e=inicializar_estado();
    LISTA d = criar_lista();

    if (argc !=3) {
        printf("Uso: %s\n",argv[0]);
        return 0;
    }
    lertab(e,argv[1]);
    possiveis_jogadas(e,&d);
    jog01(e,&d);
    freeList(&d);
    savetab(e,argv[2]);
    return 0;
}

