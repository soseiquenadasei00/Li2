#include <stdio.h>


int jogar(ESTADO *estado, COORDENADA c);

/*jogar esta função deverá receber o estado atual e uma coordenada e modificar
o estado ao jogar na casa correta se a jogada for válida. A função devolve
verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso
não seja possível.*/

// Função que deve ser completada e colocada na camada da lógica do programa
int jogar(ESTADO *e, COORDENADA c) {
printf("jogar %d %d\n", c.coluna, c.linha);
return 1;
}