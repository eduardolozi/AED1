#include <stdio.h>
#include <stdlib.h>
#define NMAX 500

typedef struct TipoItem {
    int numero;
} TipoItem;

typedef struct No {
    TipoItem item[NMAX];
    int tamanho, inicio, fim;
} No;

typedef struct Lista {
    No list[2];
} Lista;

void init(Lista *lista1, Lista *lista2);

void insereElemento(Lista *lista, int num);

int buscaSeq(Lista lista, int num, Lista *listaPos);

int buscaBin(Lista lista, int num, Lista *listaPos);

void insertionSordLista1(Lista *lista);

void imprimeLista1(Lista lista);

void insertionSordLista2(Lista *lista);

void imprimeLista2(Lista lista);

