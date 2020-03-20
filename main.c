#include <stdio.h>
#include "camadaDeDados.h"
#include "interface.h"

int main()
{

    ESTADO *e = inicializar_estado();
    printf("Se quiser sair do jogo digite (Quit)\n\nEste é o tabuleiro inicial:\n\n");
    mostrar_tabuleiro(e,stdout);
    interpretador(e);

    return 0;
}
