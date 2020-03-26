#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#include "interface.h"
#define  TAMANHO 1024
/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro no qual será gerado
 * Função que gera um arquivo
 */
void savetab(ESTADO *e, char *tab_file){
    FILE *f= fopen(tab_file, "w");
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            fprintf(f,"%c",e->tab[i][j]);
    }
    fprintf(f,"\n");
    fclose(f);
}
/**
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro que será lido
 * Função que le o arquivo gerado
 */
void lertab(ESTADO *e, char *tab_file){
    FILE *f=fopen(tab_file,"r");

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
          printf ("%c ",e->tab[i][j]);
        }
        printf("  %d\n", c);
        c--;
    }
    printf("\nA B C D E F G H\n");
}
/**
\brief I\O do jogo, onde conforme a jogadas acontecem, é atualizado o estado dos dados
*/
int interpretador(ESTADO *e){
    char file_name[TAMANHO];
    char linha[TAMANHO];
    char col[2],lin[2];
    int num = 0;
    char parabens1[] = "Parabéns Jogador 1!! Você venceu!!" ;
    char parabens2[] = "Parabéns Jogador 2!! Você venceu!!";
    /**
    \brief Contadores de movimentos:
           cmov para trocar o jogador atual e movs para todos os movimentos
    */
    int cmov = 1;
    int movs = 1;

    e->num_jogadas = 0;
    /**
    \brief Ciclo que para cada jogada efeituada alterna o jogador, atualiza o número de jogadas, imprime o tabuleiro com a nova coordenada da jogada.
    */
    while (num == 0){
        /**
         *\brief Condições para encerrar o jogo quando um jogador for encurralado
         */
        if((possiveis_jogadas (e)) == 0) {
            if (e->jogador_atual == 1) printf("%s", parabens1);
            else printf("%s", parabens2);
            break;
        }
        /**
        \brief Condições para trocar o jogador atual
         */
        if(cmov % 2 == 0){
            e -> jogador_atual = 2;
        }
        else{
            e -> jogador_atual = 1;
        }

        /** Condição para aumentar o número de jogadas */
        if (cmov == 3){
            e->num_jogadas++;
            cmov = 1;
        }
        /**
        \brief Contato com o utilizador
        */
        fgets(linha,TAMANHO,stdin);
        sscanf(linha, "%[a-h]%[1-8]", col, lin);
        COORDENADA c = {*col -'a','8' - *lin};
        c.letra = *col -'a';
        c.linha = '8'- *lin;

        /**
        \brief Validação de jogadas
        */
        if (strlen(linha) == 3  && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
            if ((casa_viz(e->ultima_jogada, c) == 1) && (casa_livre(e,c) == 1))
            {
                jogar(e,c);
                if (e->jogador_atual == 1) {
                    printf("#%d Jogador.%d (%d) -> %s%s\n",movs, e->jogador_atual,e->num_jogadas, col, lin);
                }
                else {
                    printf("#%d Jogador.%d (%d) -> %s%s\n",movs, e->jogador_atual,e->num_jogadas, col, lin);
                }
                movs++;
                cmov++;
            } else printf("Jogada invalida,tente novamente!!\n\n");
        }

        /** Caso o jogador digite "Quit" o jogo acaba*/
        if(!(strncmp(linha,"Quit",4))) break;

        /**Caso o jogador digite "gr" irá gravar o tabuleiro e o estado */
        if(sscanf(linha, "gr %s",file_name) == 1) {
            savetab(e, file_name);
        }
        /**Caso o jogador digite "ler" irá ler o arquivo gerado anteriormente */
        if (sscanf(linha,"ler %s",file_name)==1){
            if(file_name==NULL) printf("Arquivo não existe");
            else lertab(e,file_name);
        }
        /**
         \brief Caso a peça branca chegue nas coordenadas da casa 1 ou 2, imprime a mensagem com o vencedor
         */
        if(e->tab[7][0] == BRANCA)
        {
            printf("%s", parabens1);
            break;
        }
        if(e->tab[0][7] == BRANCA)
        {
            printf("%s", parabens2);
            break;
        }
        mostrar_tabuleiro(e);
    }
    return 0;
}