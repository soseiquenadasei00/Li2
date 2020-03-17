#include <stdio.h>
#include <stdlib.h>
#include "CamadaDeDados.h"
//Obtem o numero de jogadas
int numeroJogadas (ESTADO *e){
int n;
n=e->num_jogadas;
return n;
}
//Obter o jogador atual
int JogAtual (ESTADO *e){
int j;
j=e->jogador_atual;
return j;
}

//Estado da peca sendo ela (PRETA,BRANCA,VAZIA) em uma coordenada especifica
CASA estadoDaPeca (ESTADO *e ,COORDENADA *x){
    int col1,lin2,p;
    col1= x->letra;
    lin2= x->linha;
    p=e->tab[lin2][col1];
    return p;
}
//Estado inicial, mapa inicial (sem incluir jogadas do jogador)
ESTADO *inicializar_estado() {
    ESTADO *e =malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    //mapa inicial
    int i,j;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++)
            e->tab[i][j]=VAZIA;}
    e->tab[3][4]=BRANCA;
    e->tab[0][7]=DOIS;
    e->tab[7][0]=UM;


    return e;
}
//Função que pega a casa
//CASA get_casa(ESTADO *e, int col, int lin);
//Função que da um valor a casa
//void set_casa(ESTADO *e, int col, int lin, CASA valor);