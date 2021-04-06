#include <stdlib.h>
#include <string.h>

typedef struct sBaralho
{
    int carta;
    char naipe[10];
} Baralho;

char *gerarNaipe(int k)
{
    switch (k)
    {
    case 0:
        return "espada";
        break;
    case 1:
        return "paus";
        break;
    case 2:
        return "copas";
        break;
    case 3:
        return "ouro";
        break;
    default:
        return "";
        break;
    }
}

Baralho *novoBaralho()
{
    Baralho *baralho = calloc(55, sizeof(Baralho));
    for (short i = 0; i < 55; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                baralho[i].carta = j;
                strcpy(baralho[i].naipe,gerarNaipe(k));
            }
        }
    }

    return baralho;
}
