#include <stdio.h>
#include <stdlib.h>

#define NMAX 500

typedef struct TipoItem {
    char *nome;
} TipoItem;

typedef struct No {
    TipoItem item[NMAX];
    int tamanho, primeiro, ultimo;
} No;

void init(No *pessoa);

void insereNome(No *pessoa, char *nome);

void insertionSort(No *pessoa);

void selectionSort(No *pessoa);

void imprimeLista(No pessoa);