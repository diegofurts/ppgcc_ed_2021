#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(TipoPilha *P) {
	(*P).primeiro = NULL;
	printf("Eh nois!\n");
}

int InserePilha(TipoPilha *P, TipoItem I) {

	TipoApontador p;

	p = (TipoApontador) malloc(sizeof(TipoNo));
	if (p == NULL) {
		printf("Deu ruim... tá com memória lotada!\n");
		return PILHA_CHEIA;
	}

	p->item = I;
	if (PilhaVazia(P)) {
		p->prox = NULL;
		P->primeiro = p;
	} else {
		p->prox = P->primeiro;
		P->primeiro = p;
	}
	
	return SEM_ERRO;

}


void RemovePilha(TipoPilha *P) {
	
	if (PilhaVazia(P)) {
		printf("Deu nao\n");
		return;
	}

	// unico elemento
	if (P->primeiro->prox == NULL) {
		free(P->primeiro);
		CriaPilha(P);
		return;
	}

	// remove do inicio
	TipoApontador p = P->primeiro;
	P->primeiro = P->primeiro->prox;
	free(p);

}

TipoItem TopoPilha(TipoPilha *P) {

	if (!PilhaVazia(P)) {
		return P->primeiro->item;
	}
	TipoItem I;
	I.chave = -1;
	return I;

}

char PilhaVazia(TipoPilha *P) {
	return P->primeiro == NULL;
}
char PilhaCheia(TipoPilha *P);

void ImprimePilha(TipoPilha *L)  {
        TipoApontador P = L->primeiro;

	int i = 0;
	while(P != NULL) {
		if (P->prox != NULL)
			printf("%d: chave=%d, Proximo=%d\n", i, P->item.chave, P->prox->item.chave);
		else
			printf("%d: chave=%d, Proximo=NULO\n", i, P->item.chave);
		P = P->prox;
		i++;
	}
}
