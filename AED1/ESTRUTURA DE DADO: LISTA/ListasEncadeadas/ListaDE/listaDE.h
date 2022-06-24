#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    int valor;
}TipoItem;

typedef struct No{
    TipoItem item;
    struct No *prox;
    struct No *ant;
}No;

typedef struct Lista {
    struct No *primeiro;
    struct No *ultimo;
    int tamanho;
}Lista;

void criaLista(Lista *lista);

int listaVazia(Lista lista);

void insereElementoInicio(Lista *lista, int x);

void insereElementoFinal(Lista *lista, int x);

void retiraElementoInicio(Lista *lista);

void retiraElementoFinal(Lista *lista);

void buscaElemento(Lista lista);

void removePosicao(Lista *lista, int pos);

void imprimeInicio(Lista lista);

void imprimeFim(Lista lista);

void libera(Lista *lista);
