#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#include "interface.h"
#define  TAMANHO 1024


//Imprime o tabuleiro diante do novo estado estabelecido. Sendo sempre alterado pela função jogar
/*OBS: A numeracao do tabuleiro está invertida, ou seja, de 1 até 8 de cima para baixo e nao de baixo para cima
        (Pretendemos futuramente quando possível alterar isto)*/

void savetab(ESTADO *e, char *tab_file){
    FILE *f= fopen(tab_file, "w");
    mostrar_tabuleiro(e,f);
    fclose(f);
}
void lertab(ESTADO *e, char *tab_file){
    FILE *f=fopen(tab_file,"r");
    mostrar_tabuleiro(e,f);
    fclose(f);
}

void mostrar_tabuleiro(ESTADO *e, FILE *f) {
    int i, j;
    int c = 8;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
           if (f==stdout) printf ("%c ",e->tab[i][j]);
           else fprintf(f,"%c",e->tab[i][j]);
        }
        if (f==stdout) printf("  %d\n", c);
        else fprintf(f,"\n");
        c--;
    }
    if (f==stdout) printf("\nA B C D E F G H\n");
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
        \brief Parabeniza o Jogador caso ele consiga chegar na casa 1 ou 2
         */
        if (e -> tab[c.linha][c.letra] == UM) {
            printf("%s",parabens1);
            break;
        }
        if (e -> tab[c.linha][c.letra] == DOIS){
            printf("%s",parabens2);
            break;
        }


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

        if(sscanf(linha, "gr %s",file_name) == 1) {
            savetab(e, file_name);
        }
        if (sscanf(linha,"ler %s",file_name)==1){
            if(file_name==NULL) printf("Arquivo não existe");
            else lertab(e,file_name);
        }
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
        mostrar_tabuleiro(e,stdout);
    }
    return 0;
}
