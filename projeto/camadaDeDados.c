#include <stdlib.h>
#include "camadaDeDados.h"
/**
 * \brief
 * Função que inicializa o estado,ou seja, aloca uma memoria e gera o tabuleiro inicial
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
/**
 * \brief
 * Função no qual começamos com um tabuleiro do 0
 * @param e estado zerado
 */
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