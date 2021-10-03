#include "PilhaEstatica.h"
#include <stdio.h>

void CriaPilha(TipoPilha *L) {
	L->ultimo = -1;
	printf("Eh nois!\n");
}

int InserePilha(TipoPilha *P, TipoItem I) {

	if (PilhaCheia(P)) {
		printf("Deu ruim... tá lotado!\n");
		return PILHA_CHEIA;
	}
	
	P->ultimo++;
	P->itens[P->ultimo] = I;

}

int RemovePilha(TipoPilha *P) {
	if (!PilhaVazia(P))
		P->ultimo--;
}

TipoItem TopoPilha(TipoPilha *P) {
	if (!PilhaVazia(P))
		return P->itens[P->ultimo];
	TipoItem I;
	I.chave = -1;
	return I;
}

char PilhaVazia(TipoPilha *P) {
	return P->ultimo == -1;
}
char PilhaCheia(TipoPilha *P) {
	return P->ultimo == MAXTAM - 1;
}

void ImprimePilha(TipoPilha *P)  {
        TipoApontador a;
	printf("Pilha:");
        for (a=P->ultimo; a >= 0; a--) {
                printf(" %d", P->itens[a].chave);
        }
	printf("\n\n");
}
