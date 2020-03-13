typedef struct {
    int linha;
    int coluna;}COORDENADA;

void jogada(char tabuleiro[8][8])
{
    COORDENADA c1;

    printf ("\nLinhas(0 -> 7 esq p/ dir)\n""Colunas(0 -> 7 cima p/ baixo)\n"
            "\nJogada(1ºlinha 2ºcoluna):");
    scanf("%d%d", &c1.linha, &c1.coluna);

    tabuleiro [c1.linha][c1.coluna] = '*';
}
