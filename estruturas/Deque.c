#include "../componentes/Embaralhar.c"

typedef struct sNO_DEQUE
{
	Carta cartas;
	struct sNO_DEQUE *proximo;
	struct sNO_DEQUE *anterior;
} NO_DEQUE;

typedef struct sDEQUE
{
	struct sNO_DEQUE *inicio;
	struct sNO_DEQUE *fim;
} DEQUE;

void alocar_no(NO_DEQUE **no)
{
	*no = (NO_DEQUE *)malloc(sizeof(NO_DEQUE));
}

int iniciar_deque(DEQUE **deque)
{
	if ((*deque) != 0)
	{
		(*deque)->inicio = NULL;
		(*deque)->fim = NULL;
		return 1;
	}
	return 0;
}

int alocar_deque(DEQUE **deque)
{
	*deque = (DEQUE *)malloc(sizeof(DEQUE));
	if ((*deque) != 0)
	{
		iniciar_deque(deque);
		return 1;
	}
	return 0;
}

void iniciar_no(NO_DEQUE **no)
{
	*no = NULL;
}

void desalocar_no(NO_DEQUE **no)
{
	free(no);
	*no = NULL;
}

void desalocar_deque(DEQUE **deque)
{
	free(deque);
	*deque = NULL;
}

int deque_vazio(DEQUE *deque)
{

	if (deque->inicio == NULL && deque->fim == NULL)
	{
		return 1;
	}

	return 0;
}

void inserir_inicio(DEQUE **deque, int valor, char *naipe)
{
	NO_DEQUE *novo;

	alocar_no(&novo);

	if (novo != NULL)
	{
		novo->cartas.carta = valor;
		strcpy(novo->cartas.naipe, naipe);
		novo->anterior = NULL;
		novo->proximo = NULL;
		if (deque_vazio(*deque))
		{
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

void inserir_fim(DEQUE **deque, int valor, char *naipe)
{
	NO_DEQUE *novo;

	alocar_no(&novo);
	if (novo != NULL)
	{
		novo->cartas.carta = valor;
		strcpy(novo->cartas.naipe, naipe);
		novo->anterior = NULL;
		novo->proximo = NULL;
		if (deque_vazio(*deque))
		{
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

NO_DEQUE *remover_inicio(DEQUE **deque)
{
	NO_DEQUE *q, *qq;

	if (!deque_vazio(*deque))
	{
		q = (*deque)->inicio;
		if ((*deque)->inicio == (*deque)->fim)
		{
			qq = (*deque)->fim;
			iniciar_deque(deque);
			return qq;
		}
		(q->proximo)->anterior = NULL;
		(*deque)->inicio = q->proximo;
		return q;
	}

	printf("\nErro deque vazio.");
	return 0;
}

NO_DEQUE *remover_fim(DEQUE **deque)
{
	NO_DEQUE *q, *qq;

	if (!deque_vazio(*deque))
	{
		q = (*deque)->fim;
		if ((*deque)->inicio == (*deque)->fim)
		{
			qq = (*deque)->inicio;
			iniciar_deque(deque);
			return qq;
		}
		(q->anterior)->proximo = NULL;
		(*deque)->fim = q->anterior;
		return q;
	}

	printf("\nErro deque vazio.");
}

void imprimir(DEQUE *deque)
{
	NO_DEQUE *inicio, *fim;

	if (!deque_vazio(deque))
	{
		inicio = deque->inicio;
		fim = deque->fim;
		while (deque->inicio != NULL)
		{
			printf("\nValor: %d | naipe: %s", deque->inicio->cartas.carta, deque->inicio->cartas.naipe);
			deque->inicio = deque->inicio->proximo;
		}
		deque->inicio = inicio;
		deque->fim = fim;
		return;
	}

	printf("\nErro lista vazia.");
}

void apagar_todos_nos(DEQUE **deque)
{
	NO_DEQUE *q;

	if (!deque_vazio(*deque))
	{
		while ((*deque)->inicio != NULL)
		{
			q = (*deque)->inicio;
			(*deque)->inicio = (*deque)->inicio->proximo;
			desalocar_no(&q);
		}
		printf("\nTodas as cartas foram retiradas do jogo.");
		iniciar_deque(deque);
		return;
	}

	printf("\nErro lista vazia.");
}
