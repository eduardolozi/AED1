#include <stdio.h>
#include<stdlib.h>
#define MAXTAM 1000

typedef struct lista {
    int item[MAXTAM];
    int primeiro, ultimo;
    int maior, posicaoMaior;
}Lista;

typedef struct lista Lista;

void criaLista(Lista* lista);

void insereElemento(Lista* lista, int x);

void printLista(Lista* lista);

Lista concatenaListas(Lista* l1, Lista* l2);

int retiraElementos(Lista* lista, int x);

int buscaMaior(Lista* lista);

int totParesLista(Lista* lista);

float mediaLista(Lista* lista);