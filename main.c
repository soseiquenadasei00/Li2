#include <stdio.h>
#include "camadaDeDados.h"
#include "interface.h"

int main()
{
    //LISTA d = criar_lista();
    ESTADO *e = inicializar_estado();
    printf("Se quiser sair do jogo digite (Quit)\n\nEste é o tabuleiro inicial:\n\n");
    mostrar_tabuleiro(e);
    interpretador(e);

    return 0;
}
