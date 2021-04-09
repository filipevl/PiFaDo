#include "../componentes/Carta.c"

typedef struct sPilha
{
    Carta info;
    struct sPilha *cima;
} Pilha;
