#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    unsigned int matricula;
    float nota;
} Pessoa;

typedef struct No {
    Pessoa item;
    struct No *proximo;
} No;

typedef struct Lista {
    No * inicio;
    No * fim;
    int tam;
} Lista;

void init(Lista *lista);

void insereElementoFim(Lista *lista, int mat, float nota);

void quickSort(Lista *lista, int esq, int dir);

void imprimeLista(Lista lista);

void libera(Lista *lista);

