#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "camadaDeDados.h"
#include "logica.h"
#include "lista.h"
/**
\brief Faz a mudança de estado e realiza a jogada
 * @param e Estado atual do jogo
 * @param c A coordenada
 */
void jogar(ESTADO *e, COORDENADA c) {
    //Busca colocar a peça branca na coordenada especifica buscando está informação no estado
    e->tab[c.linha][c.letra]='*';
    int i = e->ultima_jogada.linha;
    int j = e->ultima_jogada.letra;
    e->tab[i][j] = PRETA;
    e->tab[c.linha][c.letra] = BRANCA;
    e->ultima_jogada.linha = c.linha;
    e->ultima_jogada.letra = c.letra;
}
/**
 * \brief Prompt do jogo
 */
void prompt(ESTADO *e){
    printf("#%02d Jogador %d (%d) -> ", e->count_mov, e->jogador_atual, e->num_jogadas);
}
/**
 * Cria o tabuleiro no file
 */
void show_tab(FILE *f, ESTADO *e){
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++){
            fprintf(f,"%c",e->tab[i][j]);
        } fprintf(f,"\n");}
}
/**
  \brief Função auxiliar que compara o maior número de 2 inteiros
 */
int max (int x, int y)
{
    int z;
    z = (x >= y) ?  x : y;
    return z;
}
/**
  \brief Função auxiliar que compara o menor número de 2 inteiros
 */
int min (int x, int y)
{
    int z;
    z = (x <= y) ? x : y;
    return z;
}
/**
 * Insere na lista ligada as possiveis jogadas
 * @param a
 * @param e
 */
void insere_lista(LISTA *a, ESTADO *e) {
    int max, i;
    max = e->qntjogs;
    for (i = 0; i < max; i++) {
        insere_cabeca(a, &(e->possiveis_jog[i]));
    }
}
//Printa as informações que está dentro da lista ligada
void printl2(LISTA *a) {
    COORDENADA pcoord;
    if ((*a)==NULL) printf("TEM MAIS NADA");
    while((*a) != NULL) {
        pcoord=*(COORDENADA*) (*a)->valor;
        printf("%d,%d\n",pcoord.letra,pcoord.linha); //*(int*) a->valor);
        a = &((*a)->prox);
    }
    printf("\n");
}
/**
 * Função que primeiro transformar em string,concatena as strings e depois passamos de strings para inteiros
 * @param a inteiro que é a
 * @param b
 * @return
 */
int concat(int a, int b)
{
    char s1[20];
    char s2[20];
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    strcat(s1, s2);
    int c = atoi(s1);
    return c;
}
/**
 \brief Função que conta quantas possíveis jogadas existem no momento
 * @param e Estado que vai nos fornecer: o tabuleiro com o estado de cada casa e a última jogada feita
 */
int possiveis_jogadas(ESTADO *e, LISTA *d)
{
    //LISTA r;
    COORDENADA pcoord;
    int count = 0, i, j,minlin,minlet;
    minlin = min((e->ultima_jogada.linha + 1), 7);
    minlet = min((e->ultima_jogada.letra + 1), 7);
    i = max((e->ultima_jogada.linha - 1), 0);
    j = max((e->ultima_jogada.letra - 1), 0);
    //printf("%d %d| %d %d\n",i,minlin,j,minlet);
    while (i <= minlin)
    {
        while( j <= minlet)
        {
            if (e->tab[i][j] == VAZIA || e->tab[i][j] == UM || e->tab[i][j]== DOIS) {
                pcoord.linha = i;
                pcoord.letra = j;
                e->possiveis_jog[count] = pcoord;

                count++;
            }
            j++;
        }
        i++;
        j = max((e->ultima_jogada.letra - 1), 0);
    }
    e->qntjogs = count;
    insere_lista(d,e);
    //printl2(d);
    printf("\n");
    printf("%d\n",count);
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

    if ((x==1 && (y==1||y==0)) || (y==1 && (x==1||x==0)))
        return 1;
    else return 0;
}
/**
 \brief Função que confer se a casa específica está livre para jogar
 * @param e Estado que nos dará o tabuleiro com os estados das suas casas
 * @param c coordenada da casa que queremos conferir o estado
 */
int casa_livre (ESTADO *e, COORDENADA c)
{
    if (e->tab[c.linha][c.letra] != PRETA && e->tab[c.linha][c.letra] != BRANCA)
        return 1;
    else return 0;
}
void parabens(int jogador)
{
    printf("\nParabéns Jogador %d!! Você venceu!!\n", jogador);
}
/**
 * Função salvar_movs, armazena na lista de jogadas o ultimo movimento feito
 * @param e Estado atuaç
 * @param c coordenada imserida
 */
void movs(ESTADO *e, COORDENADA c)
{
    if (e->jogador_atual == 1)
    {
        e->jogadas[e->num_jogadas-1].jogador1.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas-1].jogador1.letra = c.letra;
        e->jogadas[e->num_jogadas-1].jogador1.linha = c.linha;
    }
    if (e->jogador_atual == 2)
    {
        e->jogadas[e->num_jogadas-1].jogador2.letrinha = c.letrinha;
        e->jogadas[e->num_jogadas-1].jogador2.letra = c.letra;
        e->jogadas[e->num_jogadas-1].jogador2.linha =  c.linha;
    }
}
/**
 * Função desenvolvida para ser o prompt do jogo (Estados do jogo)
 * @param e estado atual
 * @param f ficheiro
 */
void aux_mov(ESTADO *e){
    int movi = 1, jogs = 1, numjog = 1, allmovs;
    allmovs = e->count_movs;
    while(movi < allmovs){
        if (jogs > 2){
            numjog++;
            jogs = 1;
        }
        if (movi % 2 == 0){
            printf( "%c%d\n",e->jogadas[(numjog-1)].jogador2.letrinha,8 - e->jogadas[(numjog-1)].jogador2.linha);
        }
        else {
            printf("%02d: %c%d ",numjog,e->jogadas[(numjog-1)].jogador1.letrinha,8 - e->jogadas[(numjog-1)].jogador1.linha);
        }
        movi++;
        jogs++;
    }
    putchar('\n');
}
/**
 * Função desenvolvida para ser o prompt do jogo (Estados do jogo), feita para ser gravada no ficheiro
 * @param e
 * @param f
 */
void aux_movf(ESTADO *e,FILE *f){
    int movi = 1, jogs = 1, numjog = 1,allmovs;
    allmovs = e->count_movs;
    while(movi < allmovs){
        if (jogs > 2){
            numjog++;
            jogs = 1;
        }
        if (movi % 2 == 0){
            fprintf(f,"%c%d\n",e->jogadas[(numjog-1)].jogador2.letrinha,8 - e->jogadas[(numjog-1)].jogador2.linha);
        }
        else {
            fprintf(f,"%02d: %c%d ",numjog,e->jogadas[(numjog-1)].jogador1.letrinha,8 - e->jogadas[(numjog-1)].jogador1.linha);
        }
        movi++;
        jogs++;
    }
    putchar('\n');
}
/**
 * Função para o comando pos,no qual retornar a jogada específica no índice declado
 * @param e estado
 * @param x índice
 */
void posf (ESTADO *e, int x) {
    int i;
    tabuleiro_inicial(e);
    iniciar_estado(e);
    for (i = 1; i <= x; i++) {
        troca_jog(e);
        jogar(e, e->jogadas[i - 1].jogador1);
        mudar_estado(e);
        troca_jog(e);
        jogar(e, e->jogadas[i - 1].jogador2);
        mudar_estado(e);
    }
}
/**
 * Função no qual alternar os jogadores ao decorrer das jogadas efetuadas
 * @param e Estado
 */
void troca_jog(ESTADO *e){
    e->jogador_atual = ((e->count_movs) % 2 == 0) ? 2 : 1;

    if ((e->count_jog) == 3) {
        e->num_jogadas++;
        e->count_jog = 1;
    }
}
/**
 * Função criada apenas para inicir o estado devidamente
 * @param e
 */
void iniciar_estado(ESTADO *e) {
    e->num = 0;
    e->count_jog = 1;
    e->count_mov = 1;
    e->count_movs = 1;
    e->num_jogadas = 1;
}
/**
 * Função que altera o estado com atualização das jogadas feita
 * @param e
 */
void mudar_estado(ESTADO *e){
    e->count_jog++;
    e->count_movs++;
}
/**
 * Função para gerar numeros aleatorios
 * @param lower
 * @param upper
 * @param count
 * @return
 */
int printRandoms (int lower, int upper, int count)
{
    int i,num=0;
    for (i=0; i < count; i++)
    {
         num = (rand ()) %(upper - lower + 1) + lower;
    }
    return num;
}
/**
 * Função criada para auxiliar na contagem da lista ligada (Apenas para saber o tamnho que a lista tem)
 * @param d lista ligada
 * @return retorna o tamnho da lista
 */
int tamanho_list(LISTA d){
    int i;
    for(i = 0; d != NULL; i++);
    return i;
}
/**
 * Função criada para jogar em uma posição de forma aleatoria (Bot)
 * @param e Estado atual do jogo
 * @param l lista ligada
 */
int calcula_dist(COORDENADA c, ESTADO* e){
    int dist;
    if (e->jogador_atual == 1){
        dist = (abs(c.linha - 7)) + c.letra;
    }
    else{
        dist = c.linha + (abs(c.letra - 7));
    }
    return dist;
}
int verifica_par(ESTADO e, COORDENADA c) {
    int count = 0, i, j, minlin, minlet;
    minlin = min((c.linha + 1), 7);
    minlet = min((c.letra + 1), 7);
    i = max((c.linha - 1), 0);
    j = max((c.letra - 1), 0);
    while (i <= minlin) {
        while (j <= minlet) {
            if (e.tab[i][j] == VAZIA || e.tab[i][j] == UM || e.tab[i][j] == DOIS) {
                count++;
            }
            j++;
        }
        i++;
        j = max((c.letra - 1), 0);
    }
    printf("%d\n",count);
    return count;
}
/*int possiveis_jogadas(ESTADO *e, LISTA *d)
{
    //LISTA r;
    COORDENADA pcoord;
    int count = 0, i, j,minlin,minlet;
    minlin = min((e->ultima_jogada.linha + 1), 7);
    minlet = min((e->ultima_jogada.letra + 1), 7);
    i = max((e->ultima_jogada.linha - 1), 0);
    j = max((e->ultima_jogada.letra - 1), 0);
    while (i <= minlin)
    {
        while( j <= minlet)
        {
            if (e->tab[i][j] == VAZIA || e->tab[i][j] == UM || e->tab[i][j]== DOIS) {
                pcoord.letra = i;
                pcoord.linha = j;
                e->possiveis_jog[count] = pcoord;

                count++;
            }
            j++;
        }
        i++;
        j = max((e->ultima_jogada.letra - 1), 0);
    }
    e->qntjogs = count;
    insere_lista(d,e);
    //printl2(d);
    printf("\n");
    return count;
}
*/

COORDENADA melhor_coord02(ESTADO e, LISTA l){
    COORDENADA melhor, coordAtual;
    melhor.linha = e.ultima_jogada.linha;
    melhor.letra = e.ultima_jogada.letra;
    melhor.letrinha = e.ultima_jogada.letrinha;
    int distatual,area1,area2,bestdist = 15;
    while (l != NULL){
        coordAtual = *(COORDENADA *)l->valor;
        distatual = calcula_dist(coordAtual,&e);
        if (distatual <= bestdist){
            if (distatual == bestdist){
                area1 = (verifica_par(e,melhor));
                area2 = (verifica_par(e,coordAtual));
                if (area2 >= area1){
                    bestdist = distatual;
                    melhor.letra = coordAtual.letra;
                    melhor.linha = coordAtual.linha;
                    melhor.letrinha = 'a' + ((coordAtual.letra)-1);
                }
            }
            else {
                bestdist = distatual;
                melhor.letra = coordAtual.letra;
                melhor.linha = coordAtual.linha;
                melhor.letrinha = 'a' + ((coordAtual.letra)-1);
            }
        }
        l = l->prox;
    }
    return melhor;
}

void area_par(ESTADO *e, LISTA *l){
    //printl2(l);
    LISTA guardaPar = NULL;
    COORDENADA c;
    int i = 0;
    printl2(l);
    while ((*l)!=NULL) {
        c = *(COORDENADA *)(*l)->valor;
        printf("COORD ATUAL: %d|%d\n",c.linha,c.letra);
        if ((verifica_par((*e),c)) % 2 == 0) {
            printf("ENTROU PAR: %d|%d\n",c.linha,c.letra);
            e->possiveis_jog[i] = c;
            i++;
            //insere_cabeca(&guardaPar,&c);
        }
        l = &((*l)->prox);
    }
    //putchar('\n');
    e->qntjogs = i;
    insere_lista(&guardaPar,e);
    //printl2(&guardaPar);
    if (guardaPar != NULL){
        freeList(l);
        while(guardaPar != NULL){
            insere_cabeca(l, guardaPar->valor);
            l = &((*l)->prox);
            guardaPar = guardaPar->prox;
        }
    }
    //printl2(l);
}
void jog02(ESTADO *e, LISTA *l){
    //printl2(*l);
    area_par(e,l);
    //printl2(*l);
    COORDENADA c = melhor_coord02((*e),(*l));
    movs(e,c);
    jogar(e,c);
    mudar_estado(e);
}


void jorge(ESTADO *e,LISTA l) {
    int max = e->qntjogs;
    char col[2];
    char lin[2];
    srand(time(0));
    int num = printRandoms(0, max, 1);
    int i;
    for (i = 1; i < num; i++) {
        l = l->prox;
    }
    int atual = *(int *)l->valor;
    char coord[5];
    sprintf(coord, "%d", atual);
    sscanf(coord, "%c%c", lin, col);
    int colint = abs('0' - *col);
    int linint = abs('0' - *lin)-1;
    COORDENADA c = {abs('0' - *col), abs('0' - *lin),(0)};
    c.letra = colint;
    c.linha = linint;
    c.letrinha = 'a' + (colint-1);
    movs(e,c);
    jogar(e,c);
    mudar_estado(e);
}


COORDENADA melhor_coord(ESTADO *e, LISTA l){
    COORDENADA melhor, atual;
    int bestdist = 15;
    int distatual;
    while (l != NULL){
        atual = *(COORDENADA *)l->valor;
        distatual = calcula_dist(atual,e);
        if (distatual < bestdist){
            bestdist = distatual;
            melhor.letra = atual.letra;
            melhor.linha = atual.linha;
            melhor.letrinha = 'a' + ((atual.letra)-1);
        }
        l = l->prox;
    }
    return melhor;
}

void jog01(ESTADO *e, LISTA l){
    COORDENADA c = melhor_coord(e,l);
    movs(e,c);
    jogar(e,c);
    mudar_estado(e);
}
