#include "../estruturas/Deque.c"

int eh_igual(int a, int b, int c)
{
	if (a == b && b == c)
		return 1;
	return 0;
}

int eh_sucessor(int a, int b, int c)
{
	if (a + 1 == b && b + 1 == c)
		return 1;
	return 0;
}

int eh_antecessor(int a, int b, int c)
{
	if (c - 1 == b && b - 1 == a)
		return 1;
	return 0;
}

int eh_sequencia(DEQUE *deque)
{
	int igual;
	int valores[3];
	if (deque_vazio(deque))
		return 0;
	else if (deque->inicio == 0 || (deque->inicio)->proximo == 0 || deque->fim == 0)
		return 0;
	else
	{
		valores[0] = deque->inicio->cartas.carta;
		valores[1] = ((deque->inicio)->proximo)->cartas.carta;
		valores[2] = deque->fim->cartas.carta;

		if (eh_igual(valores[0], valores[1], valores[2]))
			return 1;

		if (
			eh_antecessor(valores[0], valores[1], valores[2]) ||
			eh_antecessor(valores[1], valores[2], valores[0]) ||
			eh_antecessor(valores[2], valores[0], valores[1]))
			return 1;

		if (
			eh_sucessor(valores[0], valores[1], valores[2]) ||
			eh_sucessor(valores[1], valores[2], valores[0]) ||
			eh_sucessor(valores[2], valores[0], valores[1]))
			return 1;
	}
	return 0;
}

char *toString(int num)
{
	switch (num)
	{
	case 1:
		return "A ";
		break;
	case 2:
		return "2 ";
		break;
	case 3:
		return "3 ";
		break;
	case 4:
		return "4 ";
		break;
	case 5:
		return "5 ";
		break;
	case 6:
		return "6 ";
		break;
	case 7:
		return "7 ";
		break;
	case 8:
		return "8 ";
		break;
	case 9:
		return "9 ";
		break;
	case 10:
		return "10 ";
		break;
	case 11:
		return "J ";
		break;
	case 12:
		return "Q ";
		break;
	case 13:
		return "K ";
		break;
	default:
		return "";
		break;
	}
}

char *carta_naipe(Carta carta_desempilhada)
{
	char *carta = calloc(15,sizeof(char));
	strcpy(carta, toString(carta_desempilhada.carta));
	switch (carta_desempilhada.carta)
	{
	case 1:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 2:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 3:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 4:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 5:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 6:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 7:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 8:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 9:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 10:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 11:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 12:
		strcat(carta, carta_desempilhada.naipe);
		break;
	case 13:
		strcat(carta, carta_desempilhada.naipe);
		break;
	}
	return carta;
}

int numeroDeCartasNoDeque(DEQUE *espaco)
{
	int cont;
	NO_DEQUE *aux;
	aux = espaco->inicio;
	while (aux != NULL)
	{			// checando quantas cartas ja tem no baralho
		cont++; // contando quantos elementos ja existem no espaco
		aux = aux->proximo;
	}
	return cont;
}

int dequeValido(DEQUE *espaco)
{
	if (numeroDeCartasNoDeque(espaco) < 4)
		return 1;
	return 0;
}

int inserir_carta_espaco(DEQUE **espaco, Carta carta_nova)
{
	NO_DEQUE *aux, *aux2; // var para checar quantas cartas ja existem nos espa�os, e inserir uma terceira carta entre 2 cartas
	int contador = 0;	  // contador de cartas

	if (!deque_vazio(*espaco))
	{ // se o deque nao estiver vazio
		aux = (*espaco)->inicio;
		while ((*espaco)->inicio != NULL)
		{				// checando quantas cartas ja tem no baralho
			contador++; // contando quantos elementos ja existem no espaco
			(*espaco)->inicio = (*espaco)->inicio->proximo;
		}
		(*espaco)->inicio = aux;
		if ((*espaco)->inicio->cartas.carta <= carta_nova.carta)
		{ // se a primeira carta do espaco for menor ou igual a nova
			// se a carta for maior que todas que o espaco possui
			inserir_inicio(espaco, carta_nova.carta, carta_nova.naipe);
			imprimir(*espaco);
		}
		else if ((*espaco)->inicio->cartas.carta > carta_nova.carta && (*espaco)->fim->cartas.carta > carta_nova.carta)
		{
			// se a carta for menor que todos que o espaco possui
			inserir_fim(espaco, carta_nova.carta, carta_nova.naipe);
			imprimir(*espaco);
		}
		else if ((*espaco)->inicio->cartas.carta > carta_nova.carta && (*espaco)->fim->cartas.carta <= carta_nova.carta)
		{
			// se a carta for maior que a ultima e menor que a primeira
			aux = (*espaco)->fim;
			aux2 = (*espaco)->inicio;
			iniciar_deque(espaco);
			inserir_inicio(espaco, aux2->cartas.carta, aux2->cartas.naipe);
			inserir_fim(espaco, carta_nova.carta, carta_nova.naipe);
			inserir_fim(espaco, aux->cartas.carta, aux->cartas.naipe);
			imprimir(*espaco);
		}
	}
	else
	{ // se o deque estiver vazio
		inserir_inicio(espaco, carta_nova.carta, carta_nova.naipe);
		imprimir(*espaco);
	}

	contador++; // se o jogador possuir 3 cartas ao fim da jogada entao verificamos pontos
	if (contador == 3)
	{
		apagar_todos_nos(espaco);

		if (eh_sequencia(*espaco))
		{
			return 1;
		}
	}

	return 0;
}
