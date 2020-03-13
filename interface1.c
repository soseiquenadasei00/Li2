#include <stdio.h>
#include "CamadaDeDados.h"
#include "Logica.h"
#define  Tamanho 1024
#include <string.h>

//criar o tabuleiro com base nas peças
void pecas (CASA p ){
    if (p==BRANCA) printf ("*");
    if (p==PRETA) printf ("#");
    if (p==VAZIA) printf (".");
}
//Imprime o tabuleiro diante do novo estado estabelecido. Sendo sempre alterado pela função jogar
void mostrar_tabuleiro(ESTADO *e) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i==0 && j==7) printf("2");
            if (i==7 && j==0) printf("1");
             else pecas(e->tab[i][j]);
        }putchar('\n');
    }
}

/*int interpretador(ESTADO *e) {
    char linha[Tamanho];
    char col[2], lin[2];
    if (fgets(linha, Tamanho, stdin) == NULL)
        return 0;

    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);}
    return 1;
 }*/