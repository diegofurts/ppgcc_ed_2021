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

	p->ant = NULL;
	if (ListaVazia(L)) {
                L->primeiro = p;
                L->ultimo = p;
		p->prox = NULL;
        } else if (L->primeiro->item.chave > I.chave) { //primeira posicao
	
		p->prox = L->primeiro;
		L->primeiro->ant = p;
		L->primeiro = p;

	} else { // todos os demais

		TipoApontador aux;
		aux = L->primeiro;
		while(aux->prox != NULL && aux->prox->item.chave < I.chave) {
			aux = aux->prox;
		}

		p->prox = aux->prox;
		p->ant = aux;
		aux->prox = p;
		if (p->prox != NULL)
			p->prox->ant = p;

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
		L->primeiro->ant = NULL; 
		free(p);
		return SEM_ERRO;
	}

	/*// remove do meio
	TipoApontador aux = L->primeiro;
	while(aux->prox != NULL && aux->prox != p) {
		aux = aux->prox;
	}*/

	p->ant->prox = p->prox;

	// remove do fim
	if (p == L->ultimo) {
		L->ultimo = p->ant;
	} else {
		p->prox->ant = p->ant;
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

void ImprimeListaInvertida(TipoLista *L)  {
        TipoApontador P = L->ultimo;

	int i = 0;
	while(P != NULL) {
		if (P->ant != NULL)
			printf("%d: chave=%d, Anterior=%d\n", i, P->item.chave, P->ant->item.chave);
		else
			printf("%d: chave=%d, Anterior=NULO\n", i, P->item.chave);
		P = P->ant;
		i++;
	}
}
