#include <stdio.h>
#include "CamadaDeDados.h"
#include "Logica.h"
#define  Tamanho 1024
#include <string.h>

//criar o tabuleiro com base nas peças
void pecas (CASA p ){
    if (p==BRANCA) printf ("*");
    if (p==PRETA) printf ("#");
    if (p==VAZIA) printf (".");
}
//Imprime o tabuleiro diante do novo estado estabelecido. Sendo sempre alterado pela função jogar
/*OBS: A numeracao do tabuleiro está invertida, ou seja, de 1 até 8 de cima para baixo e nao de baixo para cima
        (Pretendemos futuramente quando possível alterar isto)
*/
void mostrar_tabuleiro(ESTADO *e) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i==0 && j==7) printf("2");
           else if (i==7 && j==0) printf("1");
             else pecas(e->tab[i][j]);
        }putchar('\n');
    }
    putchar('\n');
}

// I\O do jogo, onde conforme a jogadas acontecem, é atualizado o estado dos dados
int interpretador(ESTADO *e){


    char linha[Tamanho];
    char col[2],lin[2];
    int num = 0;
    char jog1[15], jog2[15];

    strcpy(jog1, "Jogador 1");
    strcpy(jog2, "Jogador 2");


    e->num_jogadas = 1;

    printf("Se quiser sair do jogo digite (quit)\n\n");

    //Ciclo que para cada jogada efeituada alterna o jogador, atualiza o número de jogadas, imprime o tabuleiro com a nova coordenada da jogada.
        //O ciclo acaba quando o utilizador escreve "quit" ou quando atinge ao número máx de jogadas (64).
    while (num == 0){

        if((e -> num_jogadas) % 2 == 0){

            printf("%s;\nDigite sua jogada: ",jog2);
            e -> jogador_atual = 2;
        }

        if((e -> num_jogadas) % 2 != 0){

            printf("%s;\nDigite sua jogada: ",jog1);
            e -> jogador_atual = 1;
        }

        fgets(linha,Tamanho,stdin);

        if(linha == "quit") break; //  Nao conseguimos estabelecer este caso de paragem.

        sscanf(linha, "%[a-h]%[1-8]", col, lin);

        /* while(linha == NULL || strlen(linha) < 3 || strlen(linha) > 3 || sscanf(linha, "%[a-h]%[1-8]", col, lin) != 2){
            printf("Jogada Inválida, tente novamente: \n");
            fgets(linha,TAMANHO,stdin);

           FUTURA VALIDACAO DE JOGADAS
        }
        */

        if (e -> num_jogadas == 64){
            num++;
        }

        if (e -> jogador_atual = 1) printf("%s sua jogada foi: %s%s\n\nNúmero de jogadas: %d\n", jog1,col,lin, e->num_jogadas);

        else printf("%s sua jogada foi: %s%s\n\nNúmero de jogadas: %d\n", jog2,col,lin, e->num_jogadas);


        e -> num_jogadas++;

        COORDENADA c = {*col -'a',*lin -'1'};
        jogar(e,c);
        mostrar_tabuleiro(e);

    }

    return 0;
}
