// Eduardo Lozano Azevedo 202103718

#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    char placa[6];
    TipoApontador prox;
} TipoCelula;

typedef struct TipoLista{
    TipoApontador primeiro, ultimo;
    int cont, max;
} Lista;

int criaLista(Lista* lista);

void insere(Lista* lista, char x[], int max);

int maximo(Lista* lista);

int capacidade(Lista* lista);

void imprime(Lista* lista);
