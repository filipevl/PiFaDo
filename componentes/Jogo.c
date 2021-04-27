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
    	
    	printf("\nJogador %d\nDigite 1 para tirar a carta do monte principal \nDigite 2 para tirar do seu espaco\n\n", jogador);
    	scanf("%d", &jogada);
    	
    	if(jogada == 1){
    		//jogador tira a primeira carta do seu respectivo monte
    		if(jogador == 1){
    			mostra_valor(monte1, &valor_carta);
    			printf("\nJogador 1 a carta virada foi: %s de %s\n", valor_carta, monte1->inicio->carta_fila.naipe);
    			//logica...
    			do{
    				printf("\nDigite 1 para inserir nos espacos 1, 2, 3, 4 \nDigite 2 para inserir no espaco x1  \nDigite 3 para descartar no fim do baralho\n\n");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espaço e1,e2,e3,e4
    				do{
    					printf("\nDigite 1 inserir espaco 1 \nDigite 2 inserir espaco 2 \nDigite 3 inserir espaco 3 \nDigite 4 inserir espaco 4\n\n");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espaço 1
    				    
    				    inserir_carta_espaco(&espaco1_1, &monte1);	
					}
					
					if(jogada == 2){ // inserir espaço 2
    					inserir_carta_espaco(&espaco2_1, &monte1);
					}
					if(jogada == 3){ // inserir espaço 3
    					inserir_carta_espaco(&espaco3_1, &monte1);
					}
					if(jogada == 4){ // inserir espaço 4
    					inserir_carta_espaco(&espaco4_1, &monte1);
					}
				}
    			printf("\nTurno acabado\n");
			}
			
			if(jogador == 2){ // turno jogador 2
				mostra_valor(monte2, &valor_carta);
    			printf("\nJogador 2 a carta virada foi: %s de %s\n", valor_carta, monte2->inicio->carta_fila.naipe);
    			//logica....
    			do{
    				printf("\nDigite 1 para inserir nos espacos 1, 2, 3, 4 \nDigite 2 para inserir no espaco x1  \nDigite 3 para descartar no fim do baralho\n\n");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espaço e1,e2,e3,e4
    				do{
    					printf("\nDigite 1 inserir espaco 1 \nDigite 2 inserir espaco 2 \nDigite 3 inserir espaco 3 \nDigite 4 inserir espaco 4\n\n");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espaço 1
    				    inserir_carta_espaco(&espaco1_2, &monte2);
					}
					
					if(jogada == 2){ // inserir espaço 2
    					inserir_carta_espaco(&espaco2_2, &monte2);
					}
					
					if(jogada == 3){ // inserir espaço 3
    					inserir_carta_espaco(&espaco3_2, &monte2);
					}
					if(jogada == 4){ // inserir espaço 4
    					inserir_carta_espaco(&espaco4_2, &monte2);
					}
				}
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

