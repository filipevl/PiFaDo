#include <time.h>
#include <conio.h>
#include "Baralho.c"


int existe_indice(int indices_inclusos[52], int valor, int total){
	int i;
	for(i=0; i<total; i++){
		if(indices_inclusos[i]==valor){
			return 1;
		}
	}
	return 0;
}

void gerar_numero_aleatorio(Baralho *baralho){
	int i, indices[TAM_BARALHO], num;
	
	srand(time(NULL));
	for(i=0; i<TAM_BARALHO; i++){
		
		num = rand() % TAM_BARALHO;
		while(existe_indice(indices, num ,i)){
			num = rand() % TAM_BARALHO;
		}
		indices[i] = num;
		
	}
	for(i=0; i<TAM_BARALHO; i++){
		printf("\nindice: %d", indices[i]);		
	}
}


