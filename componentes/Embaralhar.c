#include <time.h>
#include <conio.h>
#include "../estruturas/Fila.c"

int gerar_fila_baralho(Fila **fila, Baralho *baralho, int *ordem)
{
	int i;
	
	alocar_fila(fila);
	iniciar_fila(fila);

	for (i = 0; i < TAM_BARALHO; i++){
		if (!enfileirar(fila, baralho->cartas[ordem[i]].carta, baralho->cartas[ordem[i]].naipe)){
			return 0;
		}	
	}
	return 1;
}

int existe_indice(int *indices_inclusos, int valor, int total)
{
	int i;
	
	for (i = 0; i < total; i++)
	{
		if (indices_inclusos[i] == valor)
		{
			return 1;
		}
	}
	return 0;
}

int gerar_baralho_aleatorio(Baralho *baralho, Fila **fila){
	int i, num, indices[TAM_BARALHO];

	srand(time(NULL));
	for (i = 0; i < TAM_BARALHO; i++){

		num = rand() % TAM_BARALHO;
		while (existe_indice(indices, num, i)){
			num = rand() % TAM_BARALHO;
		}
		indices[i] = num;
	}
	if(gerar_fila_baralho(fila, baralho, indices)){
		return 1;
	}	
	return 0;
}
