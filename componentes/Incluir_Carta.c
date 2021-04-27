#include "../estruturas/Deque.c"

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

void inserir_carta_espaco(DEQUE **espaco, Fila **monte){
	NO_DEQUE *aux; // var para checar quantas cartas ja existem nos espaços
	int contador = 0; // contador de cartas
	
	if(!deque_vazio(*espaco)){ // se o deque nao estiver vazio
    	aux = (*espaco)->inicio;
    	while((*espaco)->inicio != NULL){ // checando quantas cartas ja tem no baralho
    	   	contador++;
    	   	(*espaco)->inicio = (*espaco)->inicio->proximo;
		}
		(*espaco)->inicio = aux;
    	if((*espaco)->inicio->cartas.carta >= (*monte)->fim->carta_fila.carta && contador < 3){ // se a primeira carta do espaco for menor ou igual a nova
    	    inserir_inicio(espaco, (*monte)->inicio->carta_fila.carta, (*monte)->inicio->carta_fila.naipe);
    	    desenfileirar(monte);
    	    imprimir(*espaco);
		}else if((*espaco)->inicio->cartas.carta <= (*monte)->fim->carta_fila.carta && contador < 3){
		   	inserir_fim(espaco, (*monte)->inicio->carta_fila.carta, (*monte)->inicio->carta_fila.naipe);
		   	desenfileirar(monte);
		   	imprimir(*espaco);
		}
		if(contador == 3){
			printf("\nO espaço possui 3 cartas ja.");
		}
												    
	}else{ // se o deque estiver vazio
	    inserir_inicio(espaco, (*monte)->inicio->carta_fila.carta, (*monte)->inicio->carta_fila.naipe);
		desenfileirar(monte); 
		imprimir(*espaco);	
	}	
}
