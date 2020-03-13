#include <stdlib.h>
#include "CamadaDeDados.h"
#include <stdio.h>

int numeroJogadas (ESTADO e*){
int n;
n=e->num_jogadas;
return n;
}

int JogAtual (ESTADO e*){
int j;
j=e.jogador_atual;
return j;
}


ESTADO *inicializar_estado() {
    ESTADO *e =malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    //mapa inicial
    int i,j;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++)
            e->tab[8][8]='.';
                    e->tab[4][4]='*';}


    return e;
}

CASA estadoDaPeca (ESTADO *e ,COORDENADA *x){
    int col1,lin2,p;
    col1= x->letra;
    lin2= x->linha;
    p=e->tab[col1][lin2];
    return p;
}