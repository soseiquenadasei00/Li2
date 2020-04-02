#include <stdio.h>
#include <stdlib.h>
#include "camadaDeDados.h"
#include "logica.h"

/**
\brief Faz a mudança de estado e realiza a jogada
 * @param e Estado atual do jogo
 * @param c A coordenada
 */
int jogar(ESTADO *e, COORDENADA c, char col[2], char lin[2]) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[c.linha][c.letra]='*';
    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;
    e->tab[c.linha][c.letra] = BRANCA;
    e->ultima_jogada.linha = c.linha;
    e->ultima_jogada.letra = c.letra;

    if(e->tab[7][0] == BRANCA)
    {
        parabens(1); e->num++;
    }
    if(e->tab[0][7] == BRANCA)
    {
        parabens(2); e->num++;
    }
    //PROMPT
    printf("#%d Jogador %d (%d) -> %s%s\n", e->count_mov,e->jogador_atual,e->num_jogadas,col,lin);
    e->count_mov++;
    e->count_jog++;
    return 1;
}
/**
  \brief Função auxiliar que compara o maior número de 2 inteiros
 */
int max (int x, int y)
{
    if (x >= y) return x;
    else return y;
}
/**
  \brief Função auxiliar que compara o menor número de 2 inteiros
 */
int min (int x, int y)
{
    if (x <= y) return x;
    else return y;
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
 * Comando movs, ou seja, quando o jogador escrever movs deve devolver todos os movimentos feito até o atual momento
 * @param e estado atual
 * @param c coordenadas que foram salvas
 */

void movs(ESTADO *e, COORDENADA c)
{
    if (e->jogador_atual == 1)
    {
        e->jogadas[e->num_jogadas].jogador1.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas].jogador1.linha = c.linha+1;
    }

    if (e->jogador_atual == 2)
    {
        e->jogadas[e->num_jogadas].jogador2.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas].jogador2.linha = c.linha+1;
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
    putchar('\n\n');
}