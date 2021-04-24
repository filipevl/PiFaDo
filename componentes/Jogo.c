#include "../componentes/Embaralhar.c"


// essa função vai pegar o valor da carta EXEMPLO: carta com valor 1 e trocar por A de ás para ser exibido na tela
char mostra_valor(Fila *baralho, char **valor){
	
	switch (baralho->inicio->carta_fila.carta){
		case 1:
			*valor = "A";
			break;
		case 2:
			*valor = "2";
			break;
		case 3:
			*valor = "3";
			break;
		case 4:
			*valor = "4";
			break;
		case 5:
			*valor = "5";
			break;
		case 6:
			*valor = "6";
			break;
		case 7:
			*valor = "7";
			break;
		case 8:
			*valor = "8";
			break;
		case 9:
			*valor = "9";
			break;
		case 10:
			*valor = "10";
			break;
		case 11:
			*valor = "J";
			break;
		case 12:
			*valor = "Q";
			break;
		case 13:
			*valor = "K";
			break;
	}
}

void jogo(){
	//variavel que para o loop do jogo
	int loop_jogo = 1;
	// variavel que indica qual jogador esta realizando a acao
	int jogador = 1; 
	//variavel que representa os pontos dos jogadores
	int pontos_jogador1, pontos_jogador2;
	//chamando estruturas que geram os baralhos
	Fila *monte1;
	Fila *monte2;
    Baralho baralho1 = novoBaralho();
    
    //gerando 2 baralhos aleatorios
    gerar_baralho_aleatorio(&baralho1, &monte1);
    sleep(1);
    gerar_baralho_aleatorio(&baralho1, &monte2);
    
    while(loop_jogo){
    	char *valor_carta; // mostra o valor da carta
    	int jogada; // variavel que decide acao do jogador
    	printf("\nJogador %d - Digite 1 para tirar a carta do monte principal ou 2 para tirar do seu espaco: ", jogador );
    	scanf("%d", &jogada);
    	
    	if(jogada == 1){
    		//jogador tira a primeira carta do seu respectivo monte
    		if(jogador == 1){
    			mostra_valor(monte1, &valor_carta);
    			printf("\nJogador 1 a carta virada foi: %s de %s\n", valor_carta, monte1->inicio->carta_fila.naipe);
    			//logica...
    			printf("\nTurno acabado\n");
			}
			if(jogador == 2){
				mostra_valor(monte2, &valor_carta);
    			printf("\nJogador 2 a carta virada foi: %s de %s\n", valor_carta, monte2->inicio->carta_fila.naipe);
    			//logica....
    			printf("\nTurno acabado\n");
			}
			jogador++;
			if(jogador == 3){
				jogador = 1;
			}
		}else if(jogada == 2){
			//jogador tira a primeira carta do seu espaço pessoal
			
			//logica ...
			
			jogador++;
			if(jogador == 3){
				jogador = 1;
			}
		}
	}
	
	
}

