#include<stdio.h>
#include "ListaEstatica.h"

int main() {
	TipoLista L;
	TipoItem item;
	TipoApontador P;

	CriaLista(&L);
	//printf("Ponto A\n");

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
	
	printf("Achou? Onde? %d\n", PesquisaLista(&L,3));
	printf("Achou? Onde? %d\n", PesquisaLista(&L,450));
	
	RemoveLista(&L, 5);
	ImprimeLista(&L);
	RemoveLista(&L, -3);	
	ImprimeLista(&L);
	RemoveLista(&L, 3);
	ImprimeLista(&L);
	RemoveLista(&L, 450);
	ImprimeLista(&L);
	
	printf("Achou? Onde? %d\n", PesquisaLista(&L,3));
	printf("Achou? Onde? %d\n", PesquisaLista(&L,450));

}
