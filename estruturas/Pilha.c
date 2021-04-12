#include "../componentes/Carta.c"

#define MAX_TAM 3

typedef struct sPilha {
    Carta info[MAX_TAM];
    int topo;
} Pilha;

void inicializar(Pilha* pilha) {
    pilha->topo=-1;
}

int pilhaVazia(Pilha* pilha) {
    if(pilha->topo==-1)
        return 1;

    return 0;
}

int pilhaCheia(Pilha* pilha) {
    if(pilha ->topo == (MAX_TAM-1))
        return 1;

    return 0;
}


int push(Pilha* pilha, Carta carta) {
    if(pilhaCheia(pilha))
        return 0;
	
	pilha->topo++;
    pilha->info[pilha->topo] = carta;
    
    return 1;
}

Carta *pop(Pilha* pilha) {


    if(pilhaVazia(pilha))
        return NULL;
        
	pilha->info[pilha->topo].carta=0;
	strcpy(pilha->info[pilha->topo].naipe,"");
	pilha->topo--;   
 	
    return NULL;
}


