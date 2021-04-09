#include <stdlib.h>
#include "Carta.c"

#define TAM_BARALHO 52
typedef struct sBaralho
{
    Carta cartas[TAM_BARALHO];
    int indice;
} Baralho;


Baralho novoBaralho()
{
    Baralho baralho;
    for (short i = 0; i < TAM_BARALHO; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                baralho.cartas[i].carta = j;
                strcpy(baralho.cartas[i].naipe,gerarNaipe(k));
            }
        }
    }

    return baralho;
}