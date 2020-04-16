#include <stdlib.h>
#include "camadaDeDados.h"
/**
 * Função criada para dar o numero do jogador
 * @param e -estado
 * @return retorna quem é o jogador
 */
int numeroJogadas (ESTADO *e){
int n;
n=e->num_jogadas;
return n;
}
/**
 * Função no qual devolve quem é o jogador da vez
 * @param e -estado
 * @return -retorna o jogador atual
 */
int JogAtual (ESTADO *e){
int j;
j=e->jogador_atual;
return j;
}
/** Da o estado atual da peça sendo ela (BRANCA,PRETA ou VAZIA)*/
CASA estadoDaPeca (ESTADO *e ,COORDENADA *x){
    int col1,lin2,p;
    col1= x->letra;
    lin2= x->linha;
    p=e->tab[lin2][col1];
    return p;
}
/**Função que inicializa o estado,ou seja, aloca uma memoria e gera o tabuleiro inicial
 */
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
    e->ultima_jogada.letra = 4;
    e->ultima_jogada.linha = 3;
    return e;
}

void tabuleiro_inicial(ESTADO *e){
    int i,j;
    e->num_jogadas = 0;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++)
            e->tab[i][j]=VAZIA;}
    e->tab[3][4]=BRANCA;
    e->tab[0][7]=DOIS;
    e->tab[7][0]=UM;
    e->ultima_jogada.letra = 4;
    e->ultima_jogada.linha = 3;
}

void checaCasa (ESTADO *e, COORDENADA c, CASA h){
    e->tab[c.letra][c.linha]=h;
}