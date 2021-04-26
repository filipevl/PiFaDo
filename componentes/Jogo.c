#include "../estruturas/Deque.c"

char* mostra_valor(Fila *baralho)
{
	char *carta;
	switch (baralho->inicio->carta_fila.carta)
	{
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
	//criando estruturas que geram os baralhos
	Fila *monte1;
	Fila *monte2;
    Baralho baralho1 = novoBaralho();
    //criando estruturas que geram os espa�os e1,e2,e3,e4
    DEQUE *espaco1_1, *espaco2_1, *espaco3_1, *espaco4_1; //jogador 1
    DEQUE *espaco1_2, *espaco2_2, *espaco3_2, *espaco4_2; //jogador 2
    
    //gerando 2 baralhos aleatorios
    gerar_baralho_aleatorio(&baralho1, &monte1);
    sleep(1);
    gerar_baralho_aleatorio(&baralho1, &monte2);
    //iniciando os espa�os e1,e2,e3,e4 dos 2 jogadores
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
	    int contador = 0; // contador de cartas
    	char *valor_carta; // mostra o valor da carta
    	int jogada; // variavel que decide acao do jogador
    	NO_DEQUE *aux; // var para checar quantas cartas ja existem nos espa�os
    	
    	printf("\nJogador %d\nDigite 1 para tirar a carta do monte principal ou 2 para tirar do seu espaco: ", jogador);
    	scanf("%d", &jogada);
    	
    	if(jogada == 1){
    		//jogador tira a primeira carta do seu respectivo monte
    		if(jogador == 1){
    			mostra_valor(monte1, &valor_carta);
    			printf("\nJogador 1 a carta virada foi: %s de %s\n", valor_carta, monte1->inicio->carta_fila.naipe);
    			//logica...
    			do{
    				printf("\nDigite 1 para inserir nos espacos e1,e2,e3,e4, 2 para inserir no espaco x1 e 3 para descartar no fim do baralho: ");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espa�o e1,e2,e3,e4
    				do{
    					printf("\nDigite 1 inserir e1, 2 inserir e2, 3 inserir e3 e 4 inserir e4: ");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espa�o 1
    				    
    				    if(!deque_vazio(espaco1_1)){ // se o deque nao estiver vazio
    				        aux = espaco1_1->inicio;
    				        while(espaco1_1->inicio != NULL){
    				        	contador++;
    				        	espaco1_1->inicio = espaco1_1->inicio->proximo;
							}
							espaco1_1->inicio = aux;
    				    	if(espaco1_1->inicio->cartas.carta >= monte1->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco1_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
    						    desenfileirar(&monte1);
    						    imprimir(espaco1_1);
						    }else if(espaco1_1->inicio->cartas.carta <= monte1->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco1_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
						    	desenfileirar(&monte1);
						    	imprimir(espaco1_1);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
													    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco1_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
							desenfileirar(&monte1); 
							imprimir(espaco1_1);	
						}	
					}
					
					if(jogada == 2){ // inserir espa�o 2
    					if(!deque_vazio(espaco2_1)){ // se o deque nao estiver vazio
    				        aux = espaco2_1->inicio;
    				        while(espaco2_1->inicio != NULL){
    				        	contador++;
    				        	espaco2_1->inicio = espaco2_1->inicio->proximo;
							}
							espaco2_1->inicio = aux;
    				    	if(espaco2_1->inicio->cartas.carta >= monte1->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco2_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
    						    desenfileirar(&monte1);
    						    imprimir(espaco2_1);
						    }else if(espaco2_1->inicio->cartas.carta <= monte1->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco2_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
						    	desenfileirar(&monte1);
						    	imprimir(espaco2_1);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
													    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco2_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
							desenfileirar(&monte1); 
							imprimir(espaco2_1);	
						}
					}
					
					if(jogada == 3){ // inserir espa�o 3
    					if(!deque_vazio(espaco3_1)){ // se o deque nao estiver vazio
    				        aux = espaco3_1->inicio;
    				        while(espaco3_1->inicio != NULL){
    				        	contador++;
    				        	espaco3_1->inicio = espaco3_1->inicio->proximo;
							}
							espaco3_1->inicio = aux;
    				    	if(espaco3_1->inicio->cartas.carta >= monte1->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco3_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
    						    desenfileirar(&monte1);
    						    imprimir(espaco3_1);
						    }else if(espaco3_1->inicio->cartas.carta <= monte1->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco3_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
						    	desenfileirar(&monte1);
						    	imprimir(espaco3_1);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
													    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco3_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
							desenfileirar(&monte1); 
							imprimir(espaco3_1);	
						}
					}
					if(jogada == 4){ // inserir espa�o 4
    					if(!deque_vazio(espaco4_1)){ // se o deque nao estiver vazio
    				        aux = espaco4_1->inicio;
    				        while(espaco4_1->inicio != NULL){
    				        	contador++;
    				        	espaco4_1->inicio = espaco4_1->inicio->proximo;
							}
							espaco4_1->inicio = aux;
    				    	if(espaco4_1->inicio->cartas.carta >= monte1->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco4_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
    						    desenfileirar(&monte1);
    						    imprimir(espaco4_1);
						    }else if(espaco4_1->inicio->cartas.carta <= monte1->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco4_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
						    	desenfileirar(&monte1);
						    	imprimir(espaco4_1);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
													    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco4_1, monte1->inicio->carta_fila.carta, monte1->inicio->carta_fila.naipe);
							desenfileirar(&monte1); 
							imprimir(espaco4_1);	
						}
					}
				}
    			printf("\nTurno acabado\n");
			}
			
			if(jogador == 2){ // turno jogador 2
				mostra_valor(monte2, &valor_carta);
    			printf("\nJogador 2 a carta virada foi: %s de %s\n", valor_carta, monte2->inicio->carta_fila.naipe);
    			//logica....
    			do{
    				printf("\nDigite 1 para inserir nos espacos e1,e2,e3,e4, 2 para inserir no espaco x1 e 3 para descartar no fim do baralho: ");
    			    scanf("%d", &jogada);
				}while(jogada<1 && jogada>3);
				
    			if(jogada == 1){ // inserir em algum espa�o e1,e2,e3,e4
    				do{
    					printf("\nDigite 1 inserir e1, 2 inserir e2, 3 inserir e3 e 4 inserir e4: ");
    		    	    scanf("%d", &jogada);
					}while(jogada<1 && jogada>4);
    				
    				if(jogada == 1){ // inserir espa�o 1
    				    
    				    if(!deque_vazio(espaco1_2)){ // se o deque nao estiver vazio
    				        aux = espaco1_2->inicio;
    				        while(espaco1_2->inicio != NULL){
    				        	contador++;
    				        	espaco1_2->inicio = espaco1_2->inicio->proximo;
							}
							espaco1_2->inicio = aux;
    				    	if(espaco1_2->inicio->cartas.carta >= monte2->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco1_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
    						    desenfileirar(&monte2);
    						    imprimir(espaco1_2);
						    }else if(espaco1_2->inicio->cartas.carta <= monte2->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco1_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
						    	desenfileirar(&monte2);
						    	imprimir(espaco1_2);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
						    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco1_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
							desenfileirar(&monte2); 
							imprimir(espaco1_2);	
						}	
					}
					
					if(jogada == 2){ // inserir espa�o 2
    					if(!deque_vazio(espaco2_2)){ // se o deque nao estiver vazio
    				        aux = espaco2_2->inicio;
    				        while(espaco2_2->inicio != NULL){
    				        	contador++;
    				        	espaco2_2->inicio = espaco2_2->inicio->proximo;
							}
							espaco2_2->inicio = aux;
    				    	if(espaco2_2->inicio->cartas.carta >= monte2->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco2_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
    						    desenfileirar(&monte2);
    						    imprimir(espaco2_2);
						    }else if(espaco2_2->inicio->cartas.carta <= monte2->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco2_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
						    	desenfileirar(&monte2);
						    	imprimir(espaco2_2);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
						    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco2_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
							desenfileirar(&monte2); 
							imprimir(espaco2_2);	
						}
					}
					
					if(jogada == 3){ // inserir espa�o 3
    					if(!deque_vazio(espaco3_2)){ // se o deque nao estiver vazio
    				        aux = espaco3_2->inicio;
    				        while(espaco3_2->inicio != NULL){
    				        	contador++;
    				        	espaco3_2->inicio = espaco3_2->inicio->proximo;
							}
							espaco3_2->inicio = aux;
    				    	if(espaco3_2->inicio->cartas.carta >= monte2->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco3_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
    						    desenfileirar(&monte2);
    						    imprimir(espaco3_2);
						    }else if(espaco3_2->inicio->cartas.carta <= monte2->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco3_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
						    	desenfileirar(&monte2);
						    	imprimir(espaco3_2);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
						    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco3_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
							desenfileirar(&monte2); 
							imprimir(espaco3_2);	
						}
					}
					if(jogada == 4){ // inserir espa�o 4
    					if(!deque_vazio(espaco4_2)){ // se o deque nao estiver vazio
    				        aux = espaco4_2->inicio;
    				        while(espaco4_2->inicio != NULL){
    				        	contador++;
    				        	espaco4_2->inicio = espaco4_2->inicio->proximo;
							}
							espaco4_2->inicio = aux;
    				    	if(espaco4_2->inicio->cartas.carta >= monte2->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    						    inserir_inicio(&espaco4_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
    						    desenfileirar(&monte2);
    						    imprimir(espaco4_2);
						    }else if(espaco4_2->inicio->cartas.carta <= monte2->fim->carta_fila.carta && contador < 3){
						    	inserir_fim(&espaco4_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
						    	desenfileirar(&monte2);
						    	imprimir(espaco4_2);
							}
							if(contador == 3){
								printf("\nO espa�o possui 3 cartas ja.");
							}
						    
						}else{ // se o deque estiver vazio
						    inserir_inicio(&espaco4_2, monte2->inicio->carta_fila.carta, monte2->inicio->carta_fila.naipe);
							desenfileirar(&monte2); 	
							imprimir(espaco4_2);
						}
					}
				}
    			printf("\nTurno acabado\n");
			}
			
			
			jogador++;
			if(jogador == 3){
				jogador = 1;
			}
		}else if(jogada == 2){
			//jogador tira a primeira carta do seu espa�o pessoal
			
			//logica ...
			
			jogador++;
			if(jogador == 3){
				jogador = 1;
			}
		}
	}
	
	
}

