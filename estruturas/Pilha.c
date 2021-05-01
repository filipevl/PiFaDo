#include <stdio.h>

typedef struct sPilha
{
    Carta carta;
    struct sPilha *baixo;
} Pilha;

Pilha *alocarPilha()
{
    return malloc(sizeof(Pilha));
}

void inicializarPilha(Pilha **ptr)
{
    *ptr = 0;
}

int pilhaVazia(Pilha *ptr)
{
    if (ptr == 0)
        return 1;
    return 0;
}

int inserirPilha(Carta carta, Pilha **ptr)
{
    Pilha *novo = alocarPilha();

    if (novo == 0)
    {
        return 0;
    }
    
    novo->carta = carta;

    if (pilhaVazia(*ptr))
    {
        (*ptr) = novo;
        novo->baixo = 0;
    }
    else
    {
        novo->baixo = (*ptr);
        (*ptr) = novo;
    }
    return 1;
}

Carta removerPilha(Pilha **ptr)
{
    Pilha *aux_pilha;
    Carta aux;
    aux.carta = 99; // a fim de testes para carta invalida;

    if (pilhaVazia(*ptr))
    {
        printf("Nenhuma carta no espaco\n");
        return aux;
    }

    aux = (*ptr)->carta;

    if ((*ptr)->baixo == 0)
    {
        free((*ptr));
        (*ptr) = 0;
    }
    else
    {
        aux_pilha = (*ptr);
        (*ptr) = (aux_pilha)->baixo;
        free(aux_pilha);
    }
    return aux;
}
