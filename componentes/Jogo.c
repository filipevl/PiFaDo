#include "Incluir_Carta.c"

void jogo(){
	//variavel que para o loop do jogo
	int loop_jogo = 1;
	// variavel que indica qual jogador esta realizando a acao
	int jogador = 1; 
	//variavel que representa os pontos dos jogadores
	int pontos_jogador1, pontos_jogador2;
	//criando estruturas que geram os baralhos
	Fila *monte1;
	Fila *monte2;
    Baralho baralho1 = novoBaralho();
    //criando estruturas que geram os espaços e1,e2,e3,e4
    DEQUE *espaco1_1, *espaco2_1, *espaco3_1, *espaco4_1; //jogador 1
    DEQUE *espaco1_2, *espaco2_2, *espaco3_2, *espaco4_2; //jogador 2
    
    //gerando 2 baralhos aleatorios
    gerar_baralho_aleatorio(&baralho1, &monte1);
    sleep(1);
    gerar_baralho_aleatorio(&baralho1, &monte2);
    //iniciando os espaços e1,e2,e3,e4 dos 2 jogadores
    alocar_deque(&espaco1_1);
    alocar_deque(&espaco2_1);
    alocar_deque(&espaco3_1);
    alocar_deque(&espaco4_1);
    alocar_deque(&espaco1_2);
    alocar_deque(&espaco2_2);
    alocar_deque(&espaco3_2);
    alocar_deque(&espaco4_2);
    iniciar_deque(&espaco1_1);
    iniciar_deque(&espaco2_1);
    iniciar_deque(&espaco3_1);
    iniciar_deque(&espaco4_1);
    iniciar_deque(&espaco1_2);
    iniciar_deque(&espaco2_2);
    iniciar_deque(&espaco3_2);
    iniciar_deque(&espaco4_2);
    
    while(loop_jogo){
    	char *valor_carta; // mostra o valor da carta
    	int jogada; // variavel que decide acao do jogador
    	
    	printf("\n       Jogador %d\nDigite 1 para tirar a carta do monte principal \nDigite 2 para tirar do seu espaco\n\n", jogador);
    	scanf("%d", &jogada);
    	
    	if(jogada == 1){ // jogador tira a primeira carta do seu respectivo monte
    		if(jogador == 1){
    			mostra_valor(monte1, &valor_carta);
    			printf("\nJogador 1 a carta virada foi: %s de %s\n", valor_carta, monte1->inicio->carta_fila.naipe);
    			//logica...
    			do{ // escolha de qual movimento o jogador vai fazer
    				printf("\nDigite 1 para inserir nos espacos 1, 2, 3, 4 \nDigite 2 para inserir no espaco x1  \nDigite 3 para descartar no fim do baralho\n\n");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espaço e1,e2,e3,e4
    				do{ // escolha de qual espaco ele vai inserir 1, 2, 3 ou 4
    					printf("\nDigite 1 inserir espaco 1 \nDigite 2 inserir espaco 2 \nDigite 3 inserir espaco 3 \nDigite 4 inserir espaco 4\n\n");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espaço 1
    				    if(inserir_carta_espaco(&espaco1_1, &monte1)){
    				    	pontos_jogador1++;
    				    	printf("\nParabens jogador 1 voce marcou 1 ponto!");
						}	
					}
					if(jogada == 2){ // inserir espaço 2
						if(inserir_carta_espaco(&espaco2_1, &monte1)){
    				    	pontos_jogador1++;
    				    	printf("\nParabens jogador 1 voce marcou 1 ponto!");
						}
					}
					if(jogada == 3){ // inserir espaço 3
    					if(inserir_carta_espaco(&espaco3_1, &monte1)){
    				    	pontos_jogador1++;
    				    	printf("\nParabens jogador 1 voce marcou 1 ponto!");
						}
					}
					if(jogada == 4){ // inserir espaço 4
    					if(inserir_carta_espaco(&espaco4_1, &monte1)){
    				    	pontos_jogador1++;
    				    	printf("\nParabens jogador 1 voce marcou 1 ponto!");
						}
					}
					
					if(pontos_jogador1 == 5){ // verificando se o jogador 1 vendeu o jogo
						loop_jogo = 0; // parada do loop do jogo
						printf("\n\nParabens jogador 1 voce vendeu o jogo\n\n");
					}
				}else if(jogada == 2){
					// inserir no espaco x1 ... logica
				}else if(jogada == 3){ // caso o jogador deseje descartar a carta tirada
					enfileirar(&monte1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
					desenfileirar(&monte1);	
				}
    			printf("\nTurno acabado\n"); // fim do turno jogador 1
			}
			
			if(jogador == 2){ // turno jogador 2
				mostra_valor(monte2, &valor_carta);
    			printf("\nJogador 2 a carta virada foi: %s de %s\n", valor_carta, monte2->inicio->carta_fila.naipe);
    			//logica....
    			do{ // logica de decisao de qual movimento o jogador vai fazer
    				printf("\nDigite 1 para inserir nos espacos 1, 2, 3, 4 \nDigite 2 para inserir no espaco x1  \nDigite 3 para descartar no fim do baralho\n\n");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espaço e1,e2,e3,e4
    				do{ // escolha de qual espaco ele vai inserir 1, 2, 3 ou 4
    					printf("\nDigite 1 inserir espaco 1 \nDigite 2 inserir espaco 2 \nDigite 3 inserir espaco 3 \nDigite 4 inserir espaco 4\n\n");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espaço 1
    				    if(inserir_carta_espaco(&espaco1_2, &monte2)){
    				    	pontos_jogador2++;
    				    	printf("\nParabens jogador 2 voce marcou 1 ponto!");
						}
					}
					if(jogada == 2){ // inserir espaço 2
    					if(inserir_carta_espaco(&espaco2_2, &monte2)){
    				    	pontos_jogador2++;
    				    	printf("\nParabens jogador 2 voce marcou 1 ponto!");
						}
					}
					if(jogada == 3){ // inserir espaço 3
    					if(inserir_carta_espaco(&espaco3_2, &monte2)){
    				    	pontos_jogador2++;
    				    	printf("\nParabens jogador 2 voce marcou 1 ponto!");
						}
					}
					if(jogada == 4){ // inserir espaço 4
    					if(inserir_carta_espaco(&espaco4_2, &monte2)){
    				    	pontos_jogador2++;
    				    	printf("\nParabens jogador 2 voce marcou 1 ponto!");
						}
					}
				}else if(jogada == 2){
					// inserir no espaco x1 ... logica
				}else if(jogada == 3){ // caso o jogador deseje descartar a carta tirada 
					enfileirar(&monte2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
					desenfileirar(&monte2);
				}
				
				if(pontos_jogador2 == 5){ // verificando se o jogador 1 vendeu o jogo
					loop_jogo = 0; // parada do loop do jogo
					printf("\n\nParabens jogador 2 voce vendeu o jogo\n\n");
				}
				
    			printf("\nTurno acabado\n"); // fim do turno do jogador 2
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
	if(pontos_jogador1 == 5){ // se o jogador 1 tiver 5 pontos ele ganha o jogo
		printf("\n\nParabens jogador 1 voce ganhou o jogo.");
	}else{ // se o jogador 2 tem 5 pontos ele ganha o jogo
		printf("\n\nParabens jogador 2 voce vendeu o jogo");
	}
}

