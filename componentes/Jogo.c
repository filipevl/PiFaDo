#include "Incluir_Carta.c"

int tirarCartaDoMontePrincipal(Fila *monte, DEQUE **espacos)
{
	short jogada;
	short opcao;
	char *carta = carta_naipe(monte);
	system("clear || cls");

	printf("\nCarta virada: %s \n\n", carta);

	do
	{
		printf("\nOpcoes\n1. Inserir nos espacos E1,E2,E3,E4\n2. Inserir no espaco X1\n3. Descartar no fim do baralho\nDigite uma opcao valida: ");
		scanf("%d", &jogada);
		getchar();
	} while (jogada < 1 && jogada > 3);

	switch (jogada)
	{
	case 1:
		do
		{
			system("clear || cls");
			printf("\nOpcoes\n1. Inserir no espaco E1\n2. Inserir no espaco E2\n3. Inserir no espaco E3\n4. Inserir no espaco E4\nDigite uma opcao valida: ");

			scanf("%d", &opcao);
			getchar();
		} while (opcao < 1 && opcao > 4);

		opcao--;
		if (inserir_carta_espaco(espacos[opcao], &monte))
			return 1;
		return 0;
		break;
	case 2:
		printf("\nCarta inserida no x1 com sucesso\n");
		break;
	case 3:
		enfileirar(&monte, monte->inicio->carta_fila.carta, monte->inicio->carta_fila.naipe);
		desenfileirar(&monte);
		printf("\nCarta descartada com sucesso\n");
	default:
		break;
	}
}

void jogo()
{
	int loop_jogo = 1;					  //variavel que para o loop do jogo
	int jogador = 1;					  // variavel que indica qual jogador esta realizando a acao
	int pontos_jogador1, pontos_jogador2; //variavel que representa os pontos dos jogadores

	//criando estruturas que geram os baralhos
	Fila *monte1;
	Fila *monte2;
	Baralho baralho = novoBaralho();

	//criando estruturas que geram os espa�os e1,e2,e3,e4
	DEQUE *espaco1[4], *espaco2[4];

	printf("Pressione / Enter / para embaralhar o monte do joador 1: ");
	getchar();
	gerar_baralho_aleatorio(&baralho, &monte1);
	//gerando 2 baralhos aleatorios
	printf("Pressione / Enter / para embaralhar o monte do joador 2: ");
	getchar();
	gerar_baralho_aleatorio(&baralho, &monte2);

	//iniciando os espa�os e1,e2,e3,e4 dos 2 jogadores
	for (short i = 0; i < 4; i++)
	{
		alocar_deque(&espaco1[i]);
		alocar_deque(&espaco2[i]);
		iniciar_deque(&espaco1[i]);
		iniciar_deque(&espaco2[i]);
	}

	while (loop_jogo)
	{
		int contador = 0;  // contador de cartas
		char *valor_carta; // mostra o valor da carta
		int jogada;		   // variavel que decide acao do jogador
		NO_DEQUE *aux;	   // var para checar quantas cartas ja existem nos espa�os

		do
		{
			system("clear");
			printf("\nJogador %d\n1 para tirar a carta do monte principal.\n2 para tirar do seu espaco.\nDigite uma opcao valida: ", jogador);

			scanf(" %d", &jogada);
		} while (jogada < 1 || jogada > 2);

		if (jogada == 1)
		{
			//jogador tira a primeira carta do seu respectivo monte
			if (jogador == 1)
			{
				if (tirarCartaDoMontePrincipal(monte1, espaco1))
				{
					pontos_jogador1++;
					printf("\nParabens jogador 1 voce marcou 1 ponto!");
				}
				if (pontos_jogador1 == 5) // verificando se o jogador 1 venceu o jogo
				{
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 1 voce venceu o jogo\n\n");
				}
				printf("\nTurno acabado\n");
			}

			if (jogador == 2)
			{
				if (tirarCartaDoMontePrincipal(monte2, espaco2))
				{
					pontos_jogador2++;
					printf("\nParabens jogador 1 voce marcou 1 ponto!");
				}
				if (pontos_jogador2 == 5) // verificando se o jogador 1 venceu o jogo
				{
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 1 voce venceu o jogo\n\n");
				}
			}

			jogador++;
			if (jogador == 3)
			{
				jogador = 1;
			}
		}
		else if (jogada == 2)
		{
			//jogador tira a primeira carta do seu espa�o pessoal

			//logica ...

			jogador++;
			if (jogador == 3)
			{
				jogador = 1;
			}
		}
	}
}
