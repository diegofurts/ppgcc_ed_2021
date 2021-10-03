#include<stdio.h>
#include "PilhaEstatica.h"

int main() {
	TipoPilha P;
	TipoItem item;

	CriaPilha(&P);
	//printf("Ponto A\n");

	item.chave = 5;
	InserePilha(&P, item);

	item.chave = 1;
	InserePilha(&P, item);

	item.chave = 3;
	InserePilha(&P, item);

	item.chave = 0;
	InserePilha(&P, item);

	item.chave = 25;
	InserePilha(&P, item);

	item.chave = -3;
	InserePilha(&P, item);

	ImprimePilha(&P);
	
	item = TopoPilha(&P);
	printf("Topo = %d\n", item.chave);
	
	RemovePilha(&P);
	RemovePilha(&P);
	RemovePilha(&P);
	ImprimePilha(&P);

}
