#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula *TipoApontador;
typedef int TipoItem;

struct TipoItem{
    int chave;
};

struct TipoCelula {
    TipoItem item;
    TipoApontador prox;
};

typedef struct TipoFila{
    TipoApontador tras, frente;
} Fila;


int criaFila(Fila* fila);

int filaVazia(Fila* fila);

void enfileira(Fila* fila, int x);

void desenfileira(Fila* fila);

void imprime(Fila fila);

void libera(Fila* fila);


