#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aux.h"
#include "lista.h"
#define  TAMANHO 1024
/** Está função salva o tabuleiro em um ficheiro
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
/** Esta função ler o ficheiro salvo
 * \brief
 * @param e é o estado
 * @param tab_file nome dado ao ficheiro que será lido
 * Função que le o arquivo gerado
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
 * Faz a mudança de estado e realiza a jogada
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
 * \brief
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
 * \brief
 * Função auxiliar que compara o maior número de 2 inteiros
 */
int max (int x, int y)
{
    int z;
    z = (x >= y) ?  x : y;
    return z;
}
/**
 * \brief
 * Função auxiliar que compara o menor número de 2 inteiros
 */
int min (int x, int y)
{
    int z;
    z = (x <= y) ? x : y;
    return z;
}
/**
 * \brief
 * Insere na lista ligada as possiveis jogadas
 * @param a Lista ligada
 * @param e estado atual
 */
void insere_lista(LISTA *a, ESTADO *e) {
    int max, i;
    max = e->qntjogs;
    for (i = 0; i < max; i++) {
        insere_cabeca(a, &(e->possiveis_jog[i]));
    }
}
/**
 * \brief
 * Função que conta quantas possíveis jogadas existem no momento
 * @param e Estado que vai nos fornecer: o tabuleiro com o estado de cada casa e a última jogada feita
 */
int possiveis_jogadas(ESTADO *e, LISTA *d)
{
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
    printf("\n");
    return count;
}
/**
 * \brief
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
 * \brief
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
            fprintf(f,"%02d:%c%d ",numjog,e->jogadas[(numjog-1)].jogador1.letrinha,8 - e->jogadas[(numjog-1)].jogador1.linha);
        }
        movi++;
        jogs++;
    }
    putchar('\n');
}
/**
 * \brief
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
 * \brief
 * Função criada apenas para inicir o estado devidamente
 * @param e Estado atual
 */
void iniciar_estado(ESTADO *e) {
    e->num = 0;
    e->count_jog = 1;
    e->count_movs = 1;
    e->num_jogadas = 1;
}
/**
 * \brief
 * Função que altera o estado com atualização das jogadas feita
 * @param e
 */
void mudar_estado(ESTADO *e){
    e->count_jog++;
    e->count_movs++;
}
/**
 * \brief
 * Função que calcula a melhor distancia entre a casa que o jogador deve ir e a posição atual
 * @param c Coordenada atual
 * @param e Estado atual
 * @return
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
/**
 * \brief
 * Simula em cada coordenada atribuida,verificada as suas possibilidades par, retornando a quantidade de possibilidade de jogada que cada coordenada pode retornar
 * @param e Estado atual
 * @param c Coordenada atual
 * @return
 */
int verifica_jog(ESTADO e, COORDENADA c) {
    int count = 0, i, j, minlin, minlet;
    minlin = min((c.linha + 1), 7);
    minlet = min((c.letra + 1), 7);
    i = max((c.linha - 1), 0);
    j = max((c.letra - 1), 0);
    e.tab[c.linha][c.letra] = BRANCA;
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
    return count;
}

/**
 * Função que modifica a coordenada, caso condição seja satisfeita
 * @param melhor , melhor coordenada até o momento
 * @param coordAtual , coordenada atual à ser analisada
 */
void altera_bestdist(COORDENADA *melhor,COORDENADA coordAtual){
    melhor->letra = coordAtual.letra;
    melhor->linha = coordAtual.linha;
    melhor->letrinha = 'a' + ((coordAtual.letra) - 1);
}
/**
 * Função feita para procurar qual é a melhor coordenada possivel e aplica-la na lista ligada
 * @param e Estado atual
 * @param l Lista ligada
 * @return
 */
COORDENADA melhor_coord02(ESTADO e, LISTA *l){
    COORDENADA melhor, coordAtual;
    melhor.linha = e.ultima_jogada.linha;
    melhor.letra = e.ultima_jogada.letra;
    melhor.letrinha = e.ultima_jogada.letrinha;
    int distatual,area1,area2,tamanhoL,bestdist = 15,stop = 0;
    tamanhoL = tamanho_lista(*l);
    while (*l!=NULL && stop == 0){
        if (tamanhoL > 1 && verifica_jog(e,*(COORDENADA *)(*l)->valor) == 0){
            remove_cabeca(l);}
        if (lista_vazia(*l) != 1) {
            coordAtual = *(COORDENADA *) (*l)->valor;
            distatual = calcula_dist(coordAtual, &e);
            if (distatual <= bestdist) {
                if (distatual == bestdist) {
                    area1 = (verifica_jog(e, melhor));
                    area2 = (verifica_jog(e, coordAtual));
                    if (area2 >= area1) {
                        bestdist = distatual;
                        altera_bestdist(&melhor,coordAtual);
                    }
                } else {
                    bestdist = distatual;
                    altera_bestdist(&melhor,coordAtual);
                }
            }
            (*l) = proximo(l);
        }
        else stop++;
    }
    return melhor;
}
/* BOT-01*/
/**
 * Função do bot 01, bot cujo estrategia Euclidiana
 * @param e
 * @param l
 */
void jog01(ESTADO *e, LISTA *l){
    COORDENADA c = melhor_coord02(*e,l);
    movs(e,c);
    jogar(e,c);
    mudar_estado(e);
}
/**
 * \brief
 * Função que inicializa o estado,ou seja, aloca uma memoria e gera o tabuleiro inicial
 */
ESTADO *inicializar_estado() {
    ESTADO *e =malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    //mapa inicial
    int i,j;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++)
            e->tab[i][j]=VAZIA;}
    e->tab[3][4]=BRANCA;
    e->tab[0][7]=DOIS;
    e->tab[7][0]=UM;
    e->ultima_jogada.letra = 4;
    e->ultima_jogada.linha = 3;
    return e;
}
/**
 * \brief
 * Função no qual começamos com um tabuleiro do 0
 * @param e estado zerado
 */
void tabuleiro_inicial(ESTADO *e){
    int i,j;
    e->num_jogadas = 0;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++)
            e->tab[i][j]=VAZIA;}
    e->tab[3][4]=BRANCA;
    e->tab[0][7]=DOIS;
    e->tab[7][0]=UM;
    e->ultima_jogada.letra = 4;
    e->ultima_jogada.linha = 3;
}
