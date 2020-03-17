#include <stdio.h>
#include "CamadaDeDados.h"
#include "Interface.h"

int main(){
    ESTADO *e = inicializar_estado();
    printf("Este é o tabuleiro inicial:\n\n");
    mostrar_tabuleiro(e);
    interpretador(e);

return 0;
}