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
    aux_mov1(e,f);
    fclose(f);
}

/**
 * \brief
 * Função que gera um arquivo com o tabuleiro e jogadas feita até o atual momento
 * @param e estado
 * @param tabuleiro
 */
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

void lertab(ESTADO *e,char *tabuleiro) {
    FILE *f= fopen(tabuleiro,"r");
    for (int i = 0; i < 8; fgetc(f),i++) {
        for (int j = 0; j < 8; j++) {
            char c = fgetc(f);  // fgetc =lê o primeiro caractere e automaticamente já se posiciona no próximo.
            checaCasa(e, (COORDENADA) {i,j}, c);
        }
    }
    fseek(f, 1, SEEK_CUR);// SEEK_CUR :Posição atual do fluxo
    for (int c; c != EOF; c = getc(f)) {     // EOF (end of file) c=caracter para ver se esta no final do ficheiro
        char j1[2], j2[2];
        int jogadas = fscanf(f, "%*e %s %s", j1, j2);
        if (jogadas==2){
            jogar(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
            jogar(e,(COORDENADA) {j2[0]-'a',8-(j2[1]-'1')});
        }
        else if (jogadas==1){
            jogar(e,(COORDENADA) {j1[0]-'a',8-(j1[1]-'1')});
        }
    }
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
                jogar(e,c);
                prompt(e,c);
            } else printf("Jogada invalida,tente novamente!!\n\n");
        }

        /* Caso o jogador digite "Quit" o jogo acaba*/
        if(!(strncmp(linha,"Quit",4))) break;

        /*Caso o jogador digite "gr" irá gravar o tabuleiro e o estado */
        if(sscanf(linha, "gr %s",file_name)==1) {
            savetab(e,file_name);
        }

        /*Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
        if (sscanf(linha,"ler %s",file_name)==(1)){
            lertab(e,file_name);
        }//Caso o jogador digite "movs" irá dar no ecrã as jogadas feita até o momento
        if (sscanf(linha,"movs %s")==(-1)){
               aux_mov(e);
        }
        //Caso o jogador digite "pos" irá gravar o tabuleiro e os movimentos
        if (sscanf(linha,"pos %s",file_name)==1){
            posf(e,file_name);
        }

        if(e->tab[7][0] == BRANCA)
        {
            parabens(1); e->num++;
        }
        if(e->tab[0][7] == BRANCA)
        {
            parabens(2); e->num++;
        }

        if (e->num == 0) mostrar_tabuleiro(e);

        e->count_mov++;
    }
    return 0;
}