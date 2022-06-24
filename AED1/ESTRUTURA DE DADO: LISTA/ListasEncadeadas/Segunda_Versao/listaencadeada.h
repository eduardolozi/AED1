#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio; // é um nó que faz referencia ao primeiro elemento da lista, ele não contem um valor. 
    int tam;
}Lista;

void criaLista(Lista *lista);

void insereElementoInicio(Lista *lista, int x);

void insereElementoFinal(Lista *lista, int x);

void insereElementoMeio(Lista *lista, int x, int ant);

void insereOrdenado(Lista *lista, int x);

void removeElemento(Lista* lista, int x);

void removePosicao(Lista* lista, int pos);

void buscaElemento(Lista *lista, int num);

void imprime(Lista lista);

void libera(Lista *lista);