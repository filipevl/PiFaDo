#include "../componentes/Baralho.c"

typedef struct sNO{
	Carta carta_fila;
    struct sNO *prox;
}NO;

typedef struct sFila{
	NO *inicio;
	NO *fim;
}Fila;

void iniciar_fila(Fila **fila){
	(*fila)->inicio = NULL;
	(*fila)->fim = NULL;
}

void alocar_carta(NO **no){
	*no = (NO*)malloc(sizeof(NO));
}

void alocar_fila(Fila **fila){
	*fila = (Fila*)malloc(sizeof(Fila));
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

int fila_vazia(Fila *fila){
	if(fila->fim == NULL && fila->inicio == NULL){
		return 1;
	}
	return 0;
}

void enfileirar(Fila **fila, int valor_carta, char naipe[10]){
	NO *novo;
	alocar_carta(&novo);
	
	if(novo != NULL){
		novo->carta_fila.carta = valor_carta;
		strcpy(novo->carta_fila.naipe, naipe);
		novo->prox = NULL;
		if(fila_vazia(*fila)){
			(*fila)->inicio = novo;
			(*fila)->fim = novo;
		}else{
			(*fila)->fim->prox = novo;
			(*fila)->fim = novo;
		}
	}else{
		printf("\nErro na alocacao do no.");
	}
}

void desenfileirar(Fila **fila){
	NO *aux;
	
	alocar_carta(&aux);
	
	if(aux != NULL){
		if(fila_vazia(*fila)){
			printf("\nFila vazia.");
		}else{
			if((*fila)->inicio != (*fila)->fim){
				aux = (*fila)->inicio->prox;
				desalocar_carta(&(*fila)->inicio);
				(*fila)->inicio = aux;
				return;
			}
			desalocar_fila(fila);
			alocar_fila(fila);
			iniciar_fila(fila);	
		}
	}else{
		printf("\nErro na alocacao do no.");
    }
}

