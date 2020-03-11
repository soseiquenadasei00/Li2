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
