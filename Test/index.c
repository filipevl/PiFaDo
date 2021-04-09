#include "../componentes/Baralho.c"
//#include "../componentes/Embaralhar.c"

void imprimirBaralho(Baralho baralho) // teste da função novo baralho
{
	int i;
    for (i = 0; i < TAM_BARALHO; i++)
    {
        printf("carta: %d naipe:%s\n", baralho.cartas[i].carta, baralho.cartas[i].naipe);
    }
}

void main()
{
    Baralho baralho1 = novoBaralho(); 
    //gerar_numero_aleatorio(&baralho1);
    imprimirBaralho(baralho1); // teste da função novo baralho
    system("pause");
}
