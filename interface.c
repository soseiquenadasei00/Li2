#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#define  TAMANHO 1024

void movs(ESTADO *e, COORDENADA c)
{
    if (e->jogador_atual == 1)
    {
        e->jogadas[e->num_jogadas].jogador1.letra = c.letra;
        e->jogadas[e->num_jogadas].jogador1.linha = c.linha;
    }

    if (e->jogador_atual == 2)
    {
        e->jogadas[e->num_jogadas].jogador2.letra = c.letra;
        e->jogadas[e->num_jogadas].jogador2.linha = c.linha;
    }
}

/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro no qual será gerado
 * Função que gera um arquivo
 */
void savetab(ESTADO *e, char *tabuleiro){
    FILE *f= fopen(tabuleiro, "w");
    int i, j;
    int movi = 1, jogs = 1, numjog = 1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++){
            fprintf(f,"%c",e->tab[i][j]);
    } fprintf(f,"\n");}
    while(movi < (e->count_mov)){
        if (jogs > 2){
            numjog++;
            jogs = 1;
        }
        if (movi % 2 == 0){
            fprintf(f, "%d%d\n",e->jogadas[(numjog-1)].jogador2.letra,e->jogadas[(numjog-1)].jogador2.linha);
        }
        else {
            if (numjog > 9){
                fprintf(f, "%d: %d%d ",numjog,e->jogadas[(numjog-1)].jogador1.letra,e->jogadas[(numjog-1)].jogador1.linha);
            }
            fprintf(f,"0%d: %d%d ",numjog,e->jogadas[(numjog-1)].jogador1.letra,e->jogadas[(numjog-1)].jogador1.linha);
        }
        movi++;
        jogs++;
    }

    fclose(f);}

/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro que será lido
 * Função que le o arquivo gerado
 */

void lertab(ESTADO *e, char *tabuleiro){
    FILE *f=fopen(tabuleiro,"r");
    char charaux;
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++){
            fscanf(f,"%c",&charaux);
            e->tab[i][j]=charaux;
            } fscanf(f,"\n");}
        fclose(f);}
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
        if((e->count_jog) % 2 == 0){
            e -> jogador_atual = 2;
        }
        else{
            e -> jogador_atual = 1;
        }
        if ((e->count_jog) == 3){
            e->num_jogadas++;
            e->count_jog = 1;
        }
        fgets(linha,TAMANHO,stdin);
        sscanf(linha, "%[a-h]%[1-8]", col, lin);
        COORDENADA c = {*col -'a','8' - *lin};
        c.letra = *col -'a';
        c.linha = '8'- *lin;
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
        }
        /*Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
        if (sscanf(linha,"ler %s",file_name)==1){
            if(file_name==NULL) printf("Arquivo não existe");
            else lertab(e,file_name);
        }
        if (e->num == 0) mostrar_tabuleiro(e);
    }
    return 0;
}