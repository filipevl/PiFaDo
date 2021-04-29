#include "../estruturas/Pilha.c"

void main()
{
    Carta c1, c2, c3, c4, r1, r2, r3, r4;
    Pilha *ptr;
    c1.carta = 1;
    c2.carta = 2;
    c3.carta = 3;
    c4.carta = 4;
    strcpy(c1.naipe, gerarNaipe(0));
    strcpy(c2.naipe, gerarNaipe(1));
    strcpy(c3.naipe, gerarNaipe(2));
    strcpy(c4.naipe, gerarNaipe(3));

    inicializarPilha(&ptr);

    if (inserirPilha(c1, &ptr) && inserirPilha(c2, &ptr) && inserirPilha(c3, &ptr) && inserirPilha(c4, &ptr))
    {
        printf("Passou no teste de inserção na pilha\n\n\n");
    }

    r1 = removerPilha(&ptr);
    r2 = removerPilha(&ptr);
    r3 = removerPilha(&ptr);
    r4 = removerPilha(&ptr);
    printf("Removeu: %d de %s\n",r1.carta,r1.naipe);
    printf("Removeu: %d de %s\n",r2.carta,r2.naipe);
    printf("Removeu: %d de %s\n",r3.carta,r3.naipe);
    printf("Removeu: %d de %s\n",r4.carta,r4.naipe);
    pilhaVazia(ptr) ? printf("Passou no teste de pilha vazia\n") : printf("Falhou no teste de pilha vazia");

    system("pause");
}