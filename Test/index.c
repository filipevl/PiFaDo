#include "../componentes/Baralho.c"

void imprimirBaralho(Baralho baralho) // teste da função novo baralho
{
    for (short i = 0; i < TAM_BARALHO; i++)
    {
        printf("carta: %d naipe:%s\n", baralho.cartas[i].carta, baralho.cartas[i].naipe);
    }
}

void main()
{
    Baralho baralho1 = novoBaralho(); 
    imprimirBaralho(baralho1); // teste da função novo baralho
    system("pause");
}