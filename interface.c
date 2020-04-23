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
    fprintf(f,"\n");
    aux_movf(e,f);
    fclose(f);
}

/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro que será lido
 * Função que le o arquivo gerado
 */

void lertab(ESTADO *e,char *tabuleiro) {
    FILE *f= fopen(tabuleiro,"r");
    if (f == NULL){
        printf("ERROR\n");
    }
    iniciar_estado(e);
    char j1[2], j2[2],j[2],js[8];
    int jogadas;
    for (int i = 0; i < 8;i++) {
        fscanf(f,"%*c%*c%*c%*c%*c%*c%*c%*c\n");}

    //jogadas = fscanf(f, "%s %s %s\n",j, j1, j2);
    //printf("%s, %d\n",j1,jogadas);
    while ((fscanf(f, "%*s %s %s\n",j1, j2))!= EOF) {
        printf("LIDO:%s %s\n",j1, j2);
        //jogadas = fscanf(f, "%*s %s %s\n", j1, j2);
        /*if (jogadas==2){
            troca_jog(e);
            movs(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            jogar(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            mudar_estado(e);

            troca_jog(e);
            movs(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            jogar(e,(COORDENADA) {j2[0]-'a',8-(j2[1]-'1')});
            mudar_estado(e);
        }
        else if (jogadas==1){
            troca_jog(e);
            movs(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            jogar(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            mudar_estado(e);
        }
    }
     */
    }
    fclose(f);
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
    int x;

    iniciar_estado(e);
    while (e->num == 0){

        troca_jog(e);
        if((possiveis_jogadas (e)) == 0) {
            parabens(e->jogador_atual);
            break;}

        prompt(e);
        fgets(linha,TAMANHO,stdin);
        sscanf(linha, "%[a-h]%[1-8]", col,lin);
        COORDENADA c = {*col -'a','8' - *lin};
        c.letra = *col -'a';
        c.linha = '8'- *lin;
        c.letrinha = col[0];
        /*Validação de jogadas*/
        if (strlen(linha) == 3  && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
            if ((casa_viz(e->ultima_jogada, c) == 1) && (casa_livre(e,c) == 1))
            {
                movs(e,c);
                jogar(e,c);
                mudar_estado(e);
            } else printf("Jogada invalida,tente novamente!!\n\n");
        }
        /* Caso o jogador digite "Quit" o jogo acaba*/
        if(!(strncmp(linha,"Quit",4))) break;
        /*Caso o jogador digite "gr" irá gravar o tabuleiro e o estado */
        if(sscanf(linha, "gr %s",file_name)==1) {
            savetab(e,file_name);}
        /*Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
        if (sscanf(linha,"ler %s",file_name)==(1)){
            lertab(e,file_name);
        }//Caso o jogador digite "movs" irá dar no ecrã as jogadas feita até o momento
        if (sscanf(linha,"movs %s")==(-1)){
            aux_mov(e);
        }
        //Caso o jogador digite "pos" irá gravar o tabuleiro e os movimentos
        if (sscanf(linha,"pos %d", &x)==1){
            posf(e,x);
        }
        //Caso o jogador digite "jog" irá ativar o bot e haverá uma jogada
        /*if (sscanf(linha,"jog")==0){
            jogs(e,c);
        }*/
        if(e->tab[7][0] == BRANCA)
        {
            parabens(1); e->num++;
        }
        if(e->tab[0][7] == BRANCA)
        {
            parabens(2); e->num++;
        }

        if (e->num == 0) mostrar_tabuleiro(e);
    }
    return 0;
}