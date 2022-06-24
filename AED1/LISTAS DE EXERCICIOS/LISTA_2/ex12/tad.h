#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem {
    int valor, prioridade;
}TipoItem;

typedef struct No {
    struct No *prox;
    TipoItem item;
}No;

typedef struct Fila {
    No *inicio;
    No *final;
    int tamanho;
}Fila;

void criaFila(Fila *fila);

void enfileira(Fila *fila, int num, int prioridade);

void imprime(Fila fila);

void insere(Fila **fila, int num, int prioridade);

void divideFilas(Fila f1, Fila *f2, Fila *f3, int base);

void libera(Fila *fila);