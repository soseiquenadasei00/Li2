#include <stdio.h>
#include <string.h>
#include "camadaDeDados.h"
#include "logica.h"
#define  TAMANHO 1024


//Imprime o tabuleiro diante do novo estado estabelecido. Sendo sempre alterado pela função jogar
/*OBS: A numeracao do tabuleiro está invertida, ou seja, de 1 até 8 de cima para baixo e nao de baixo para cima
        (Pretendemos futuramente quando possível alterar isto)*/

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

// I\O do jogo, onde conforme a jogadas acontecem, é atualizado o estado dos dados
int interpretador(ESTADO *e){

    char linha[TAMANHO];
    char col[2],lin[2];
    int num = 0;

    e->num_jogadas = 1;


    //Ciclo que para cada jogada efeituada alterna o jogador, atualiza o número de jogadas, imprime o tabuleiro com a nova coordenada da jogada.
    //O ciclo acaba quando o utilizador escreve "quit" ou quando atinge ao número máx de jogadas (64).
    while (num == 0){

        if((e -> num_jogadas) % 2 == 0){
            e -> jogador_atual = 2;
        }

        if((e -> num_jogadas) % 2 != 0){
            e -> jogador_atual = 1;
        }

        fgets(linha,TAMANHO,stdin);

        if(linha == "quit") break; //  Nao conseguimos estabelecer este caso de paragem.

        sscanf(linha, "%[a-h]%[1-8]", col, lin);

        while(linha == NULL || strlen(linha) < 3 || strlen(linha) > 3 || sscanf(linha, "%[a-h]%[1-8]", col, lin) != 2){
            printf("Jogada Inválida, tente novamente: \n");
            fgets(linha,TAMANHO,stdin);
        }

        /*
        if (e -> num_jogadas == 64 ){
            num++;
        }
        */


        if (e -> jogador_atual == 1){
            printf("#%d Jogador(1) -> %s%s\n", e->num_jogadas,col,lin);
        }

        if (e -> jogador_atual == 2) {
            printf("#%d Jogador(2) -> %s%s\n", e->num_jogadas, col, lin);
        }

        e-> num_jogadas++;

        COORDENADA c = {*col -'a','8' - *lin};
        jogar(e,c);
        mostrar_tabuleiro(e);

    }

    return 0;
}