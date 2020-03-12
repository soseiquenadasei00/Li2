#include <stdio.h>
#include "CamadaDeDados.h"
#include "Logica.h"
#define BUF_SIZE

void tab_inicial(char tabuleiro[8][8])
{
    int i = 0, j=0;

    while (i < 8)
    {
        while (j < 8)
        {
            tabuleiro[i][j]='.';
            j++;
        }
        tabuleiro[i][j]='\0';
        j = 0;
        i++;
    }
    tabuleiro[7][0] = '1';
    tabuleiro[0][7] = '2';
    tabuleiro[3][4] = '*';
}


void imprimir_tabuleiro (char tab[8][8])
{
    int i, j;

    for (i=0; i<8; i++)
    {
        for (j=0; j<8;j++)
        {
            printf("%c", tab[i][j]);
        }
        putchar('\n');
        j=0;
    }
}



void mostrar_tabuleiro(ESTADO *e) {
    int i=0;
    e->tab;

}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
}
if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
COORDENADA coord = {*col - 'a', *lin - '1'};
jogar(e, coord);
mostrar_tabuleiro(e);
}
return 1;