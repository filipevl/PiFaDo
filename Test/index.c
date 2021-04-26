//#include "../componentes/Baralho.c"
#include "../componentes/Jogo.c"


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
	//Fila *fila_baralho1;
	//Fila *fila_baralho2;
    //Baralho baralho1 = novoBaralho(); 
    
    
    //printf("\nbaralho 1:\n\n");
    //gerar_baralho_aleatorio(&baralho1, &fila_baralho1);
    //imprimi_nao_classico(fila_baralho1);
    //sleep(1);
    //printf("\nbaralho 2:\n\n");
    //gerar_baralho_aleatorio(&baralho1, &fila_baralho2);
    //imprimi_nao_classico(fila_baralho2);
    //imprimirBaralho(baralho1); // teste da função novo baralho
    jogo(); // chamada do jogo
    system("pause");
    return 0;
}
