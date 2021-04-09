
#include <string.h>

typedef struct sCarta
{
    int carta;
    char naipe[10];
} Carta;

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
