#include<stdio.h>
#include<stdlib.h>
#include "ListaDinamica.h"

int main() {

	TipoLista L;
	TipoItem item;
	TipoApontador P;

	CriaLista(&L);

	item.chave = 5;
	InsereLista(&L, item);

	item.chave = 1;
	InsereLista(&L, item);

	item.chave = 3;
	InsereLista(&L, item);

	item.chave = 0;
	InsereLista(&L, item);

	item.chave = 25;
	InsereLista(&L, item);

	item.chave = -3;
	InsereLista(&L, item);

	ImprimeLista(&L);
	
	RemoveLista(&L, 5);
	ImprimeLista(&L);
	RemoveLista(&L, -3);	
	ImprimeLista(&L);
	RemoveLista(&L, 3);
	ImprimeLista(&L);
	RemoveLista(&L, 450);
	ImprimeLista(&L);
	
	P = L.primeiro;
	while(P != NULL) {
		L.primeiro = P->prox;
		printf("Limpando\n");
		free(P);
		P = L.primeiro;
	}
	
}
