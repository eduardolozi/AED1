#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    int num;
}TipoItem;

typedef struct No{
    TipoItem item;
    struct No *prox;
}No;

typedef struct Fila{
    No *primeiro;
    No *ultimo;
    int tamanho;
    int negativo;
}Fila;

typedef struct Pilha{
    No *primeiro;
    No *ultimo;
}Pilha;

void criaFila(Fila *fila);

void criaPilha(Pilha *pilha);

void insereFila(Fila *fila, int num);

void inserePilha(Pilha *pilha, int num);

void imprimeFila(Fila fila);

void imprimePilha(Pilha pilha);

int removeElementoFila(Fila *fila);

void liberaFila(Fila *fila);

void liberaPilha(Pilha *pilha);
