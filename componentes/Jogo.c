#include "Incluir_Carta.c"

int tirarCartaDoMontePrincipal(Fila **monte, DEQUE **espacos)
{
	short jogada;
	short opcao;
	Carta carta_cima = desenfileirar(monte);
	char *carta = carta_naipe(carta_cima);
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
		if (inserir_carta_espaco(&espacos[opcao], carta_cima))
			return 1;
		enfileirar(monte, carta_cima.carta, carta_cima.naipe);
		return 0;
		break;
	case 2:
		printf("\nCarta inserida no x1 com sucesso\n");
		break;
	case 3:
		desenfileirar(monte);
		enfileirar(monte, carta_cima.carta, carta_cima.naipe);
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
	Fila *monte1 = 0;
	Fila *monte2 = 0;
	Baralho baralho1 = novoBaralho();
	Baralho baralho2 = novoBaralho();


	//criando estruturas que geram os espacos e1,e2,e3,e4
	DEQUE *espaco1[4], *espaco2[4];

	// gerando baralhos com intervalo de 1 segundo para a funcao randomica gerar valores diferentes
	if(gerar_baralho_aleatorio(&baralho1, &monte1))
		printf("Passou\n");

	printf("Pressione /Enter/ para embaralhar os baralhos");
	getchar();
	
	if(gerar_baralho_aleatorio(&baralho2, &monte2))
		printf("Baralho aleatorio\n");

	//iniciando os espacos e1,e2,e3,e4 dos 2 jogadores
	for (int i = 0; i < 4; i++)
	{
		printf("Teste de laço");
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
		NO_DEQUE *aux;	   // var para checar quantas cartas ja existem nos espacos

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
				if (tirarCartaDoMontePrincipal(&monte1, espaco1))
				{
					pontos_jogador1++;
					printf("\nParabens jogador 1 voce marcou 1 ponto!");
				}
				if (pontos_jogador1 == 5)
				{				   // verificando se o jogador 1 venceu o jogo
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 1 voce venceu o jogo\n\n");
				}
				printf("\nTurno acabado\n");
			}

			if (jogador == 2)
			{
				if (tirarCartaDoMontePrincipal(&monte2, espaco2))
				{
					pontos_jogador2++;
					printf("\nParabens jogador 1 voce marcou 1 ponto!");
				}
				if (pontos_jogador2 == 5)
				{				   // verificando se o jogador 1 venceu o jogo
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
			//jogador tira a primeira carta do seu espaco pessoal

			//logica ...

			jogador++;
			if (jogador == 3)
			{
				jogador = 1;
			}
		}
	}
}
