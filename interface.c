#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#define  TAMANHO 1024

/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro no qual será gerado
 * Função que gera um arquivo
 */
void savetab(ESTADO *e, char *tabuleiro){
    FILE *f= fopen(tabuleiro, "w");
    show_tab(f,e);
    fclose(f);
}

void posf(ESTADO *e, char *tabuleiro){
    FILE *f= fopen(tabuleiro, "w");
    show_tab(f,e);
    aux_mov1(e,f);
    fclose(f);
}
/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro que será lido
 * Função que le o arquivo gerado
 */

void lertab(ESTADO *e) {
    int i = 0;
    int xa, xb, ya, yb;

    tabuleiro_inicial(e);

    e->tab[3][4] = PRETA;

    while (i < e->num_jog_grav)
    {
        xa = e->jogs_gravadas[i].jogador1.letra;
        xb = e->jogs_gravadas[i].jogador1.linha;
        ya = e->jogs_gravadas[i].jogador2.letra;
        yb = e->jogs_gravadas[i].jogador2.linha;

        e->tab[xb][xa] = PRETA;
        e->tab[yb][ya] = PRETA;

        i++;
    }

    xa = e->ult_jog_grav.letra;
    xb = e->ult_jog_grav.linha;

    e->tab[xb][xa] = BRANCA;

    e->ultima_jogada.linha = e->ult_jog_grav.linha;
    e->ultima_jogada.letra = e->ult_jog_grav.letra;

}

/**
 \brief Função que mostra a tabuleiro no ecrã.
 */
void mostrar_tabuleiro(ESTADO *e) {
    int i, j;
    int c = 8;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
          printf ("%c ",e->tab[i][j]);}
        printf("  %d\n", c);
        c--;}
    printf("\nA B C D E F G H\n");
}
/**
\brief I\O do jogo, onde conforme a jogadas acontecem, é atualizado o estado dos dados
*/
int interpretador(ESTADO *e){
    char file_name[TAMANHO];
    char linha[TAMANHO];
    char col[2],lin[2];

    e->num = 0;
    e->count_jog = 1;
    e->count_mov = 1;
    e->num_jogadas = 0;

    while (e->num == 0){

        if((possiveis_jogadas (e)) == 0) {
            parabens(e->jogador_atual);
            break;}

        e->jogador_atual = ((e->count_jog) % 2 == 0) ? 2 : 1;

        if ((e->count_jog) == 3){
            e->num_jogadas++;
            e->count_jog = 1;
        }
        fgets(linha,TAMANHO,stdin);
        sscanf(linha, "%[a-h]%[1-8]", col, lin);
        COORDENADA c = {*col -'a','8' - *lin};
        c.letra = *col -'a';
        c.linha = '8'- *lin;
        c.letrinha = col[0];
        /*Validação de jogadas*/
        if (strlen(linha) == 3  && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
            if ((casa_viz(e->ultima_jogada, c) == 1) && (casa_livre(e,c) == 1))
            {
                movs(e,c);
                jogar(e,c,col,lin);
            } else printf("Jogada invalida,tente novamente!!\n\n");
        }

        /* Caso o jogador digite "Quit" o jogo acaba*/
        if(!(strncmp(linha,"Quit",4))) break;

        /*Caso o jogador digite "gr" irá gravar o tabuleiro e o estado */
        if(sscanf(linha, "gr %s",file_name)==1) {
            savetab(e,file_name);
            gravar_jog(e);
        }

        /*Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
        if (sscanf(linha,"ler %s")==(1)){
            lertab(e);
        }
        if (sscanf(linha,"movs %s")==(-1)){
               aux_mov(e);
        }
        //printf("%s e o scanf deu:%d \n\n", linha, sscanf(linha, "pos %s",file_name) );
        if (sscanf(linha,"pos %s",file_name)==1){
            posf(e,file_name);
        }

        if (e->num == 0) mostrar_tabuleiro(e);
    }
    return 0;
}