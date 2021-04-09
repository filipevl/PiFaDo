#include "../componentes/Carta.c"

typedef struct sPilha
{
    Carta info;
    struct sPilha *cima;
    int tam;
} Pilha;

void inicializar(Pilha* pilha) {
    pilha->cima = NULL;
    pilha->tam = 0;
}

int pilhaVazia(Pilha* pilha) {
    if(pilha->cima == NULL)
        return 1;

    return 0;
}

