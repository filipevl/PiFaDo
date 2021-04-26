#include "../componentes/Embaralhar.c"

typedef struct sNO_DEQUE{
	Carta cartas;
	struct sNO_DEQUE *proximo;
	struct sNO_DEQUE *anterior;
}NO_DEQUE;

typedef struct sDEQUE{
	struct sNO_DEQUE *inicio;
	struct sNO_DEQUE *fim;
}DEQUE;

void alocar_no(NO_DEQUE **no){
	*no = (NO_DEQUE*)malloc(sizeof(NO_DEQUE));
}

void iniciar_deque(DEQUE **deque){
	(*deque)->inicio = NULL;
	(*deque)->fim = NULL;
}

void alocar_deque(DEQUE **deque){
	*deque = (DEQUE*)malloc(sizeof(DEQUE));
	iniciar_deque(deque);
}

void iniciar_no(NO_DEQUE **no){
	*no = NULL;
}

void desalocar_no(NO_DEQUE **no){
	free(no);
	*no = NULL;
}

void desalocar_deque(DEQUE **deque){
	free(deque);
	*deque = NULL;
}

int deque_vazio(DEQUE *deque){
	
	if(deque->inicio == NULL && deque->fim == NULL){
		return 1;
	}
	
	return 0;
}

void inserir_inicio(DEQUE **deque, int valor, char *naipe){
	NO_DEQUE *novo;
	
	alocar_no(&novo);
	
	if(novo != NULL){
		novo->cartas.carta = valor;
		strcpy(novo->cartas.naipe, naipe);
		novo->anterior = NULL;
		novo->proximo = NULL;
		if(deque_vazio(*deque)){
			(*deque)->inicio = novo;
			(*deque)->fim = novo;
			return;
		}
		novo->proximo = (*deque)->inicio;
		(*deque)->inicio->anterior = novo;
		(*deque)->inicio = novo;
		return;
	}
	
	printf("\nErro na alocacao do no");
	exit(1);
}

void inserir_fim(DEQUE **deque, int valor, char *naipe){
	NO_DEQUE *novo;
	
	alocar_no(&novo);
	if(novo != NULL){
		novo->cartas.carta = valor;
		strcpy(novo->cartas.naipe, naipe);
		novo->anterior = NULL;
		novo->proximo = NULL;
		if(deque_vazio(*deque)){
			(*deque)->inicio = novo;
			(*deque)->fim = novo;
			return;
		}
		novo->anterior = (*deque)->fim;
		(*deque)->fim->proximo = novo;
		(*deque)->fim = novo;
		return;
	}
	
	printf("\nErro na alocacao do no");
	exit(1);
}

void remover_inicio(DEQUE **deque){
	NO_DEQUE *q;
	NO_DEQUE *qq;
	
	if(!deque_vazio(*deque)){
		q = (*deque)->inicio;
		if((*deque)->inicio == (*deque)->fim){
			qq = (*deque)->fim;
			iniciar_deque(deque);
			desalocar_no(&q);
			desalocar_no(&qq);
			return;
		}
		(q->proximo)->anterior = NULL;
		(*deque)->inicio = q->proximo;
		desalocar_no(&q);
		return;
	}
	
	printf("\nErro deque vazio.");
}

void remover_fim(DEQUE **deque){
	NO_DEQUE *q;
	NO_DEQUE *qq;
	
	if(!deque_vazio(*deque)){
		q = (*deque)->fim;
		if((*deque)->inicio == (*deque)->fim){
			qq = (*deque)->inicio;
			iniciar_deque(deque);
			desalocar_no(&q);
			desalocar_no(&qq);
			return;
		}
		(q->anterior)->proximo = NULL;
		(*deque)->fim = q->anterior;
		desalocar_no(&q);
		return;
	}
	
	printf("\nErro deque vazio.");
}

void imprimir(DEQUE *deque){
	NO_DEQUE *inicio, *fim;
	
	if(!deque_vazio(deque)){
		inicio = deque->inicio;
		fim = deque->fim;
		while(deque->inicio != NULL){
			printf("\nValor: %d | naipe: %s", deque->inicio->cartas.carta, deque->inicio->cartas.naipe);
			deque->inicio = deque->inicio->proximo;
		}
		deque->inicio = inicio;
		deque->fim = fim;
		return;
	}
	
	printf("\nErro lista vazia.");
}
