#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef int TipoChave;
typedef struct {
	TipoChave chave;
	//char nome[50];
} TipoItem;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoItem item;
	struct TipoNo *prox;
} TipoNo;

typedef struct {
	TipoApontador primeiro, ultimo;
} TipoLista;

void CriaLista(TipoLista *L);
int InsereLista(TipoLista *L, TipoItem I);
void RemoveLista(TipoLista *L, TipoChave C);
TipoApontador PesquisaLista(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);

#endif
