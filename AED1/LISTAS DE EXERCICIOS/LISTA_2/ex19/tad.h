#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem{
    char letra;
}TipoItem;

typedef struct No{
    TipoItem item;
    struct No *proximo;
}No;

typedef struct Pilha{
    No *primeiro;
    No *ultimo;
    int tamanho;
}Pilha;

void criaPilha(Pilha *pilha);

void insere(Pilha *pilha, char letra);

void palindromo(Pilha pilha);

void imprime(Pilha pilha);

void libera(Pilha *pilha);
