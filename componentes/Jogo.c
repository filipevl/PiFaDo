#include "Incluir_Carta.c"
#include "../estruturas/Pilha.c"

int inserirNosEspacos(Carta carta, DEQUE **espacos, Fila **ptrFila){
	if (carta.carta == 99)
		return 0;

	int opcao;
	do{
		printf("\nOpcoes\n1. Inserir no espaco E1\n2. Inserir no espaco E2\n3. Inserir no espaco E3\n4. Inserir no espaco E4\nDigite uma opcao valida: ");

		scanf("%d", &opcao);
		getchar();
	} while (opcao < 1 || opcao > 4);

	opcao--;
	if (inserir_carta_espaco(&espacos[opcao], carta, ptrFila)){
		return 1;
	}	
	return 0;
}

int inserirNaPilha(Carta carta, Pilha **ptr){

	if (inserirPilha(carta, ptr))
		return 1;
	return 0;
}

int tirarCartaDoMontePrincipal(Fila **monte, DEQUE **espacos, Pilha **ptrPilha){

	int jogada;
	Carta carta_cima = desenfileirar(monte);
	char *carta = carta_naipe(carta_cima);

	printf("\nCarta virada: %s \n\n", carta);

	do{
	
		printf("\nOpcoes\n1. Inserir nos espacos E1,E2,E3,E4\n2. Inserir no espaco extra\n3. Descartar no fim do baralho\nDigite uma opcao valida: ");
		scanf("%d", &jogada);
		getchar();
	}while(jogada < 1 || jogada > 3);

	switch (jogada){
	
	case 1:
		if (inserirNosEspacos(carta_cima, espacos, monte))
			return 1;
		enfileirar(monte, carta_cima.carta, carta_cima.naipe);
		return 0;
		break;
	case 2:
		inserirNaPilha(carta_cima, ptrPilha);
		return 0;
		break;
	case 3:
		enfileirar(monte, carta_cima.carta, carta_cima.naipe);
		printf("\nCarta descartada com sucesso\n");
	default:
		break;
	}
}

void jogo()
{
	int i;
	int loop_jogo = 1;					  //variavel que para o loop do jogo
	int jogador = 1;					  // variavel que indica qual jogador esta realizando a acao
	int pontos_jogador1 = 0; 		      //variavel que representa os pontos dos jogadores
	int pontos_jogador2 = 0; 			  //variavel que representa os pontos dos jogadores
	//criando estruturas que geram os baralhos
	Fila *monte1 = 0;
	Fila *monte2 = 0;
	Baralho baralho1 = novoBaralho();
	Baralho baralho2 = novoBaralho();
	Pilha *ptrPilha[2];
	Carta topo;
	//criando estruturas que geram os espacos e1,e2,e3,e4
	DEQUE *espaco1[4], *espaco2[4];

	for (i = 0; i < 2; i++){
	
		inicializarPilha(&ptrPilha[i]);
	}


	// gerando baralhos com intervalo de 1 segundo para a funcao randomica gerar valores diferentes
	gerar_baralho_aleatorio(&baralho1, &monte1);

	printf("Pressione /Enter/ para embaralhar os baralhos");
	getchar();
	system("clear || cls");

	gerar_baralho_aleatorio(&baralho2, &monte2);

	//iniciando os espacos e1,e2,e3,e4 dos 2 jogadores
	for (i = 0; i < 4; i++){
	
		alocar_deque(&espaco1[i]);
		alocar_deque(&espaco2[i]);
		iniciar_deque(&espaco1[i]);
		iniciar_deque(&espaco2[i]);
	}

	while (loop_jogo){
	
		int contador = 0;  // contador de cartas
		char *valor_carta; // mostra o valor da carta
		int jogada;		   // variavel que decide acao do jogador

		do{
		
			printf("\nJogador %d\n1 para tirar a carta do monte principal.\n2 para tirar do seu espaco.\nDigite uma opcao valida: ", jogador);

			scanf(" %d", &jogada);
		} while (jogada < 1 || jogada > 2);

		if (jogada == 1){
		
			//jogador tira a primeira carta do seu respectivo monte
			if (jogador == 1){
			
				if (tirarCartaDoMontePrincipal(&monte1, espaco1, &ptrPilha[0])){
					// se ao fim da jogada ele formar pares sera acrescentado 1 ponto
					pontos_jogador1++;
					printf("\nParabens jogador 1 voce marcou 1 ponto! PONTOS: %d", pontos_jogador1);
				}
				if (pontos_jogador1 == 5){ // verificando se o jogador 1 venceu o jogo				   
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 1 voce venceu o jogo\n\n");
				}
				printf("\nTurno acabado\n");
			}

			if (jogador == 2){
			
				if (tirarCartaDoMontePrincipal(&monte2, espaco2, &ptrPilha[1])){
				
					pontos_jogador2++;
					printf("\nParabens jogador 1 voce marcou 1 ponto! PONTOS: %d", pontos_jogador2);
				}
				if (pontos_jogador2 == 5){
								   // verificando se o jogador 1 venceu o jogo
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 1 voce venceu o jogo\n\n");
				}
			}

			jogador++;
			if (jogador == 3){
			
				jogador = 1;
			}
		}
		else if (jogada == 2){
		
			if (jogador == 1){
			
				topo = removerPilha(&ptrPilha[0]);
				printf("%d de %s retirado do espaco escolhido\n", topo.carta, topo.naipe);
				inserirNosEspacos(topo, espaco1, &monte1);
			}
			if (jogador == 2){
			
				topo = removerPilha(&ptrPilha[1]);
				printf("%d de %s retirado do espaco escolhido\n", topo.carta, topo.naipe);
				inserirNosEspacos(topo, espaco2, &monte2);
			}
			jogador++;
			if (jogador == 3){
			
				jogador = 1;
			}
		}
	}
}
