#include "ListaEstatica.h"
#include <stdio.h>

static int RemovePosicao(TipoLista *L, TipoApontador P);

void CriaLista(TipoLista *L) {
	L->ultimo = -1;
	printf("Eh nois!\n");
}

int InsereLista(TipoLista *L, TipoItem I) {

	if (ListaCheia(L)) {
		printf("Deu ruim... tá lotado!\n");
		return LISTA_CHEIA;
	}

	L->ultimo++;
	L->itens[L->ultimo] = I;

}

int RemoveLista(TipoLista *L, TipoChave C) {
	RemovePosicao(L, PesquisaLista(L, C));
}

static int RemovePosicao(TipoLista *L, TipoApontador P) {
	TipoApontador a;
	if (P < 0 || P > L->ultimo) {
		printf("Posicao invalida\n");
		return POS_INVALIDA;
	}
	for (a = P; a < L->ultimo; a++)
		L->itens[a] = L->itens[a+1];
	L->ultimo--;
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {
	TipoApontador a;
	for (a=0; a <= L->ultimo; a++) {
		if (L->itens[a].chave == C)
			return a;
	}
	return NAO_ENCONTROU;
}

char ListaVazia(TipoLista *L) {
	return L->ultimo == -1;
}
char ListaCheia(TipoLista *L) {
	return L->ultimo == MAXTAM - 1;
}

void ImprimeLista(TipoLista *L)  {
        TipoApontador a;
	printf("Lista:");
        for (a=0; a <= L->ultimo; a++) {
                printf(" %d", L->itens[a].chave);
        }
	printf("\n\n");
}
