#include <stdio.h>

int main() {
    char tabuleiro[8][8];
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

    for (i=0; i<8; i++)
    {
        for (j=0; j<8;j++)
        {
            printf("%c", tabuleiro[i][j]);
        }
        putchar('\n');
        j=0;
    }

    return 0;
}
