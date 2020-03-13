#include <stdio.h>
#include "CamadaDeDados.h"
#include "Logica.h"
#include "Interface.h"

int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);
}
return 0;