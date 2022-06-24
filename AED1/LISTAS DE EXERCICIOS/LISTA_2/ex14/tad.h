#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    char nome[15];
    int id;
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

void insereElemento(Fila *fila, char *nome, int id);

void tamanhoFila(Fila fila);

void removePrimeiro(Fila *fila);

void imprimePrimeiro(Fila fila);

void imprime(Fila fila);

void libera(Fila *fila);