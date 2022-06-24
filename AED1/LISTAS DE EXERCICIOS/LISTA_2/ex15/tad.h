#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    int num;
} TipoItem;

typedef struct No{
    TipoItem item;
    struct No *prox;
} No;

typedef struct Fila{
    No *primeiro;
    No *ultimo;
    int tamanho;
} Fila;

void criaFila(Fila *fila);

void insere(Fila *fila, int num);

void ordenaCrescente(Fila *fila);

void insere2(Fila **fila, int num);

void juntaFilas(Fila f1, Fila f2, Fila *f3);

void imprime(Fila fila);

void libera(Fila *fila);