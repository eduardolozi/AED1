#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    int num;
} TipoItem;

typedef struct No{
    TipoItem item;
    struct No *prox;
} No;

typedef struct Pilha{
    No *primeiro;
    No *ultimo;
} Pilha;

void criaPilha(Pilha *pilha);

void insere(Pilha *pilha, int num);

void imprime(Pilha pilha);

int retira(Pilha *pilha);

void libera(Pilha *pilha);