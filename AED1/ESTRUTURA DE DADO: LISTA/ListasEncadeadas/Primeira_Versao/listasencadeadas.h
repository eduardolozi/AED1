#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;   //ponteiro pra struct, ja que o proximo vai ser um ponteiro que aponta pra uma nova celula.
}No;

void insereElementoInicio(No **lista, int x);   //Ponteiro pra ponteiro pq ele vai atuar sobre o endereço de um ponteiro, ou seja No** lista, vai mudar o valor do *lista que existe na função main.

void insereElementoFinal(No **lista, int x);

void insereElementoMeio(No **lista, int x, int ant); //a variável ant se refere a um valor anterior

void insereOrdenado(No **lista, int x);

void removeElemento(No **lista, int x);

void busca(No **lista, int x);

void imprimir(No *lista); // nesse caso, so passamos o *lista, ou seja estamos passando apenas uma copia do No *lista da funçao main.