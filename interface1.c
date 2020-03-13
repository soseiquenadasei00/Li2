#include <stdio.h>
#include "CamadaDeDados.h"
#include "Logica.h"
#define  Tamanho 1024
#include <string.h>
void mostrar_tabuleiro(ESTADO *e) {
}


int interpretador(ESTADO *e) {
    char linha[Tamanho];
    char col[2], lin[2];
    if (fgets(linha, Tamanho, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
