#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int chave;
}TipoItem;

typedef struct No{
    TipoItem item;
    struct No *prox;
}No;

typedef struct lista{
    No *inicio;
    No *final;
    int tam;
}Lista;

void criaLista(Lista *lista);

//void insere(Lista **lista, int num);

void insereLista(Lista *lista, int num);

void criaListaVetor(Lista *lista, int *vetor, int tamanho);

void excluiRepetidos(Lista *lista);

void insere(Lista **lista, int num);

void concatena(Lista l1, Lista l2, Lista *lista3);

void intercala(Lista l1, Lista l2, Lista *l4);

void imprime(Lista lista);

int somaLista(Lista lista);

void liberaLista(Lista *lista);