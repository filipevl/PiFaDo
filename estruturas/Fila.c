#include "../componentes/Baralho.c"

typedef struct sNO{
	Carta carta_fila;
	struct sNO *prox;
} NO;

typedef struct sFila{
	NO *inicio;
	NO *fim;
} Fila;

void alocar_carta(NO **no){
	*no = (NO *)malloc(sizeof(NO));
}

void alocar_fila(Fila **fila){
	*fila = (Fila *)malloc(sizeof(Fila));
	return;
}

void desalocar_carta(NO **no){
	free(*no);
	*no = NULL;
}

void desalocar_fila(Fila **fila){
	free(*fila);
	*fila = NULL;
}

void iniciar_fila(Fila **fila){
	(*fila)->inicio = NULL;
	(*fila)->fim = NULL;
}

int fila_vazia(Fila *fila){
	if(fila->fim == NULL && fila->inicio == NULL){
		return 1;
	}
	return 0;
}

int enfileirar(Fila **fila, int valor_carta, char *naipe){
	NO *novo;
	alocar_carta(&novo);

	if (novo != 0)
	{
		novo->carta_fila.carta = valor_carta;
		strcpy(novo->carta_fila.naipe, naipe);
		novo->prox = 0;
		if (fila_vazia(*fila))
		{
			(*fila)->inicio = novo;
			(*fila)->fim = novo;
		}
		else
		{
			(*fila)->fim->prox = novo;
			(*fila)->fim = novo;
		}
		return 1;
	}
	else
	{
		printf("\nErro na alocacao do no.");
	}
	return 0;
}

Carta desenfileirar(Fila **fila){
	NO *aux;
	Carta carta_removida;

	alocar_carta(&aux);

	if (aux != 0){
		if (fila_vazia(*fila)){
			printf("\nFila vazia.\n");
			getchar();
		}
		else{
			carta_removida.carta = (*fila)->inicio->carta_fila.carta;
			strcpy(carta_removida.naipe, (*fila)->inicio->carta_fila.naipe);

			if ((*fila)->inicio != (*fila)->fim){
				aux = (*fila)->inicio->prox;
				free((*fila)->inicio);
				(*fila)->inicio = aux;
			}
			else{
				free((*fila)->inicio);
				(*fila)->inicio = 0;
				(*fila)->fim = (*fila)->inicio;
			}
		}
	}
	else{
		printf("\nErro na alocacao do no.");
		exit(1);
	}

	return carta_removida;
}
