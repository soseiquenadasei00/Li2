#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#include "lista.h"
#define  TAMANHO 1024
/**
 * \brief
 *  Está função salva o tabuleiro em um ficheiro
 * @param e Estado atual
 * @param tabuleiro
 */
void savetab(ESTADO *e, char *tabuleiro){
    FILE *f= fopen(tabuleiro, "w");
    show_tab(f,e);
    fprintf(f,"\n");
    aux_movf(e,f);
    fclose(f);
}
/**
 * \brief
 * Esta função ler o ficheiro salvo
 * @param e Estado Atual
 * @param tabuleiro
 */
void lertab(ESTADO *e,char *tabuleiro) {
    FILE *f= fopen(tabuleiro,"r");
    tabuleiro_inicial(e);
    iniciar_estado(e);
    char j1[3],j2[3],col1[2],lin1[2],col2[2],lin2[2],linha[TAMANHO];
    int jogadas;
    for (int i = 0; i < 8 && fgets(linha, TAMANHO, f) != NULL;i++);
    while ((jogadas = (fscanf(f,"%*s %s %s\n",j1,j2)))!= EOF) {
        sscanf(j1, "%[a-h]%[1-8]", col1,lin1);
        COORDENADA c1 = {*col1 -'a','8' - *lin1,0};
        c1.letra = *col1 -'a';
        c1.linha = '8'- *lin1;
        c1.letrinha = col1[0];
        sscanf(j2, "%[a-h]%[1-8]", col2,lin2);
        COORDENADA c2 = {*col2 -'a','8' - *lin2,0};
        c2.letra = *col2 -'a';
        c2.linha = '8'- *lin2;
        c2.letrinha = col2[0];
        if (jogadas==2){
            troca_jog(e);
            movs(e,c1);
            jogar(e,c1);
            mudar_estado(e);

            troca_jog(e);
            movs(e,c2);
            jogar(e,c2);
            mudar_estado(e);
             }
        else if (jogadas==1){
            troca_jog(e);
            movs(e,c1);
            jogar(e,c1);
            mudar_estado(e);}
    }
    fclose(f);
    }
/**
 * \brief
 * Função que mostra a tabuleiro no ecrã.
 * @param e Estado atual
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
 * Interpretador do jogo, local onde aplicamos as funções e comandos par ao jogo
 * @param e Estado do jogo
 * @return 0
 */
int interpretador(ESTADO *e) {
    char file_name[TAMANHO],linha[TAMANHO],col[2],lin[2];
    int x;
    LISTA d = criar_lista();
    iniciar_estado(e);
    e->count_mov = 1;
    while (e->num == 0) {
        troca_jog(e);
        if ((possiveis_jogadas(e, &d)) == 0) {
            parabens(e->jogador_atual);
            break;}
        prompt(e);
        if (fgets(linha, TAMANHO, stdin)) {
            sscanf(linha, "%[a-h]%[1-8]", col, lin);
            COORDENADA c = {*col - 'a', '8' - *lin, 0};
            c.letra = *col - 'a';
            c.linha = '8' - *lin;
            c.letrinha = col[0];
            /*Validação de jogadas*/
            if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
                if ((casa_viz(e->ultima_jogada, c) == 1) && (casa_livre(e, c) == 1)) {
                    movs(e, c);
                    jogar(e, c);
                    mudar_estado(e);
                } else printf("Jogada invalida,tente novamente!!\n\n");
            }
            /* Caso o jogador digite "Quit" o jogo acaba*/
            if (!(strncmp(linha, "Quit", 4))) break;
            /*Caso o jogador digite "gr" irá gravar o tabuleiro e o estado */
            if (sscanf(linha, "gr %s", file_name) == 1) {
                savetab(e, file_name);
            }
            /*Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
            if (sscanf(linha, "ler %s", file_name) == (1)) {
                lertab(e, file_name);
            }/*Caso o jogador digite "movs" irá dar no ecrã as jogadas feita até o momento*/
            if (strcmp(linha, "movs")==10) {
                aux_mov(e);
            }
            /*Caso o jogador digite "pos" irá gravar o tabuleiro e os movimentos*/
            if (sscanf(linha, "pos %d", &x) == 1) {
                posf(e, x);
            }
            /*Caso o jogador digite "jog" irá ativar o bot e haverá uma jogada*/
            if (strcmp(linha, "jog")==10) {
                jog01(e,&d);
            }
            /*Caso o jogador digite "jog2" irá ativar o bot2 e haverá uma jogada*/
            if (strcmp(linha, "jog2")==10) {
                jog02(e, &d);
            }
            freeList(&d);
            if (e->tab[7][0] == BRANCA) {
                parabens(1);
                e->num++;
            }
            if (e->tab[0][7] == BRANCA) {
                parabens(2);
                e->num++;}
            e->count_mov++;
            if (e->num == 0) mostrar_tabuleiro(e);

        }
    }
    return 0;
}