
#include <stdio.h>
#include <stdlib.h>
#include "camadaDeDados.h"
#include "logica.h"

/**
\brief Faz a mudança de estado e realiza a jogada
 * @param e Estado atual do jogo
 * @param c A coordenada
 */
int jogar(ESTADO *e, COORDENADA c) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[c.linha][c.letra]='*';
    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;
    e->tab[c.linha][c.letra] = BRANCA;
    e->ultima_jogada.linha = c.linha;
    e->ultima_jogada.letra = c.letra;

}

/**
 * \brief Prompt do jogo
 */
void prompt(ESTADO *e, COORDENADA c) {
    char col = c.letrinha;
    int lin = 8 - c.linha;

    printf("#%d Jogador %d (%d) -> %c%d\n", e->count_mov, e->jogador_atual, e->num_jogadas, col, lin);
    e->count_jog++;
}

/**
 * Cria o tabuleiro no file
 */
void show_tab(FILE *f, ESTADO *e){
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++){
            fprintf(f,"%c",e->tab[i][j]);
        } fprintf(f,"\n");}
}
/**
  \brief Função auxiliar que compara o maior número de 2 inteiros
 */
int max (int x, int y)
{
    int z;
    z = (x >= y) ?  x : y;
    return z;
}
/**
  \brief Função auxiliar que compara o menor número de 2 inteiros
 */
int min (int x, int y)
{
    int z;
    z = (x <= y) ? x : y;
    return z;
}
/**
 \brief Função que conta quantas possíveis jogadas existem no momento
 * @param e Estado que vai nos fornecer: o tabuleiro com o estado de cada casa e a última jogada feita
 */
int possiveis_jogadas(ESTADO *e)
{
    int count = 0, i, j;

    i = max((e->ultima_jogada.linha - 1), 0);
    j = max((e->ultima_jogada.letra - 1), 0);

    while (i <= min((e->ultima_jogada.linha + 1), 7))
    {
        while( j <= min((e->ultima_jogada.letra + 1), 7))
        {
            if (e->tab[i][j] == VAZIA) count++;
            j++;
        }
        i++;
        j = max((e->ultima_jogada.letra - 1), 0);
    }
    return count;

}
/**
 \brief Função que garante se duas coordenadas são vizinhas no tabuleiro
 * @param cAntes última coordenada jogada no tabuleiro
 * @param cJog coordenada jogada pelo jogador
 */
int casa_viz(COORDENADA cAntes, COORDENADA cJog)
{
    int x, y;

    x = abs(cAntes.linha - cJog.linha);
    y = abs(cAntes.letra - cJog.letra);

    if ((x==1 && (y==1||y==0)) || (y==1 && (x==1||x==0))) return 1;
}

/**
 \brief Função que confer se a casa específica está livre para jogar
 * @param e Estado que nos dará o tabuleiro com os estados das suas casas
 * @param c coordenada da casa que queremos conferir o estado
 */
int casa_livre (ESTADO *e, COORDENADA c)
{
    if (e->tab[c.linha][c.letra] != PRETA && e->tab[c.linha][c.letra] != BRANCA) return 1;
}

void parabens(int jogador)
{
    printf("\nParabéns Jogador %d!! Você venceu!!\n", jogador);
}

/**
 * Funcao salvar_movs, armazena na lista de jogadas o ultimo movimento feito
 * @param e Estado atuaç
 * @param c coordenada imserida
 */
void movs(ESTADO *e, COORDENADA c)
{
    if (e->jogador_atual == 1)
    {
        e->jogadas[e->num_jogadas].jogador1.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas].jogador1.letra = c.letra;
        e->jogadas[e->num_jogadas].jogador1.linha = 8 - c.linha;
    }

    if (e->jogador_atual == 2)
    {
        e->jogadas[e->num_jogadas].jogador2.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas].jogador2.letra = c.letra;
        e->jogadas[e->num_jogadas].jogador2.linha =  8 - c.linha;
    }
}

/**
 * Função desenvolvida para ser o prompt do jogo (Estados do jogo)
 * @param e estado atual
 * @param f ficheiro
 */

void aux_mov(ESTADO *e){
    int movi = 1, jogs = 1, numjog = 1;
    while(movi < (e->count_mov)){
        if (jogs > 2){
            numjog++;
            jogs = 1;
        }
        if (movi % 2 == 0){
            printf( "%c%d\n",e->jogadas[(numjog-1)].jogador2.letrinha,e->jogadas[(numjog-1)].jogador2.linha);
        }
        else {
            printf("%02d: %c%d ",numjog,e->jogadas[(numjog-1)].jogador1.letrinha,e->jogadas[(numjog-1)].jogador1.linha);
        }

        movi++;
        jogs++;
    }
    putchar('\n');
}

void aux_mov1(ESTADO *e,FILE *f){
    int movi = 1, jogs = 1, numjog = 1;
    while(movi < (e->count_mov)){
        if (jogs > 2){
            numjog++;
            jogs = 1;
        }
        if (movi % 2 == 0){
            fprintf(f,"%c%d\n",e->jogadas[(numjog-1)].jogador2.letrinha,e->jogadas[(numjog-1)].jogador2.linha);
        }
        else {
            fprintf(f,"%02d: %c%d ",numjog,e->jogadas[(numjog-1)].jogador1.letrinha,e->jogadas[(numjog-1)].jogador1.linha);
        }

        movi++;
        jogs++;
    }
    putchar('\n');
}
