#include "ListaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaLista(TipoLista *L) {
	(*L).ultimo = NULL;
	(*L).primeiro = NULL;
	printf("Eh nois!\n");
}

int InsereLista(TipoLista *L, TipoItem I) {

	TipoApontador p;

	p = (TipoApontador) malloc(sizeof(TipoNo));
	if (p == NULL) {
		printf("Deu ruim... tá com memória lotada!\n");
		return LISTA_CHEIA;
	}

	p->item = I;
	/*p->prox = NULL;
	if (ListaVazia(L)) {
		L->primeiro = p;
		L->ultimo = p;
	} else {
		L->ultimo->prox = p;
		L->ultimo = p;
	}
	*/

	if (ListaVazia(L)) {
                L->primeiro = p;
                L->ultimo = p;
		p->prox = NULL;
        } else if (L->primeiro->item.chave > I.chave) { //primeira posicao
	
	p->prox = L->primeiro;
	L->primeiro = p;

	} else { // todos os demais

		TipoApontador aux;
		aux = L->primeiro;
		while(aux->prox != NULL && aux->prox->item.chave < I.chave) {
			aux = aux->prox;
		}

		p->prox = aux->prox;
		aux->prox = p;

	}
	return SEM_ERRO;

}


static int RemoveListaPosicao(TipoLista *L, TipoApontador p) {
	
	if (p == NULL) {
		printf("Posicao invalida\n");
		return POS_INVALIDA;
	}

	// unico elemento
	if (p == L->primeiro && p == L->ultimo) {
		CriaLista(L);
		free(p);
		return SEM_ERRO;
	}

	// remove do inicio
	if (p == L->primeiro) {
		L->primeiro = L->primeiro->prox;
		free(p);
		return SEM_ERRO;
	}

	// remove do meio
	TipoApontador aux = L->primeiro;
	while(aux->prox != NULL && aux->prox != p) {
		aux = aux->prox;
	}

	aux->prox = p->prox;

	// remove do fim
	if (aux->prox == NULL) {
		L->ultimo = aux;
	}

	free(p);
	return SEM_ERRO;
}

void RemoveLista(TipoLista *L, TipoChave C) {
	TipoApontador p = PesquisaLista(L, C);
	int e = RemoveListaPosicao(L, p);
	if (e == POS_INVALIDA)
		printf("Deu ruim\n");
	else
		printf("Sucesso\n");
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {
	TipoApontador p;

	p = L->primeiro;
	while(p != NULL) {
		if (p->item.chave == C)
			return p;
		p = p->prox;
	}

	return p;
}

char ListaVazia(TipoLista *L) {
	return L->ultimo == NULL && L->primeiro == NULL;
}
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L)  {
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
