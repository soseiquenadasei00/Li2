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
