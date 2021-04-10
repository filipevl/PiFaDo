#include <time.h>
#include <conio.h>
#include "../estruturas/Fila.c"

void gerar_fila_baralho(Fila **fila, Baralho *baralho, int ordem[TAM_BARALHO]){
	int i;
	
	alocar_fila(fila);
	iniciar_fila(fila);
	for(i=0; i<TAM_BARALHO;i++){
		enfileirar(fila, baralho->cartas[ordem[i]].carta, baralho->cartas[ordem[i]].naipe);
	}
}

int existe_indice(int indices_inclusos[TAM_BARALHO], int valor, int total){
	int i;
	for(i=0; i<total; i++){
		if(indices_inclusos[i]==valor){
			return 1;
		}
	}
	return 0;
}

void gerar_baralho_aleatorio(Baralho *baralho, Fila **fila){
	int i, num, indices[TAM_BARALHO];;
	
	srand(time(NULL));
	for(i=0; i<TAM_BARALHO; i++){
		
		num = rand() % TAM_BARALHO;
		while(existe_indice(indices, num ,i)){;
			num = rand() % TAM_BARALHO;
		}
		indices[i] = num;
		
	}
	gerar_fila_baralho(fila, baralho, indices);
}


