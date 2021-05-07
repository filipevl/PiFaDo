#include <stdlib.h>
#include <stdio.h>
#include "Carta.c"

#define TAM_BARALHO 52
typedef struct sBaralho{
    Carta cartas[TAM_BARALHO];
    int indice;
} Baralho;

Baralho novoBaralho(){
    short i, count, carta;
    Baralho baralho;
    for (i = 0, count = 0, carta=1; i < TAM_BARALHO; i++, count++, carta++){
        baralho.indice = i;
        strcpy(baralho.cartas[i].naipe, gerarNaipe(count));
        baralho.cartas[i].carta = carta;
        if ( count == 3 )
            count = -1;
        if ( carta == 13 )
            carta = 0;
    }

    return baralho;
}
