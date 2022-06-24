#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

void criaLista(Lista *lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

int listaVazia(Lista lista) {
    return (lista.primeiro == NULL && lista.ultimo == NULL);
}

void insereElementoInicio(Lista *lista, int x) {
    No *novo = (No*) malloc(sizeof(No));

    if(listaVazia(*lista) == 1) {
        novo->item.valor = x;
        novo->ant = NULL;
        novo->prox = NULL;
        lista->primeiro = novo;
        lista->ultimo = novo;
        lista->tamanho++;
    }
    else {
        novo->item.valor = x;
        novo->prox = lista->primeiro;
        novo->ant = NULL;
        lista->primeiro->ant = novo;
        lista->primeiro = novo;
        lista->tamanho++;
    }
}

void insereElementoFinal(Lista *lista, int x) {
    No *novo = (No*) malloc(sizeof(No));

    if(listaVazia(*lista) == 1) {
        novo->item.valor = x;
        novo->ant = NULL;
        novo->prox = NULL;
        lista->primeiro = novo;
        lista->ultimo = novo;
        lista->tamanho++;
    }
    else {
        novo->item.valor = x;
        novo->prox = NULL;
        novo->ant = lista->ultimo;
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
        lista->tamanho++;
    }
}

void retiraElementoInicio(Lista *lista) {
    No *aux = (No*) malloc(sizeof(No));

    if(listaVazia(*lista) == 1) {
        printf("A lista está vazia. Impossível retirar um elemento.\n");
        return;
    }
    else {
        if(lista->tamanho == 1) {
            lista->primeiro = NULL;
            lista->ultimo = NULL;
        }
        else {
            aux = lista->primeiro;
            lista->primeiro = lista->primeiro->prox;
            lista->primeiro->ant = NULL;
            free(aux);
            lista->tamanho--;
        }
        lista->tamanho--;
    }
}

void retiraElementoFinal(Lista *lista) {
    No *aux = (No*) malloc(sizeof(No));

    if(listaVazia(*lista) == 1) {
        printf("A lista está vazia. Impossível retirar um elemento.\n");
        return;
    }
    else {
        if(lista->tamanho == 1) {
            aux = lista->ultimo;
            lista->ultimo = NULL;
            lista->primeiro = NULL;
        }
        else {
            aux = lista->ultimo;
            lista->ultimo = lista->ultimo->ant;
            lista->ultimo->prox = NULL;
            free(aux);
        }
        lista->tamanho--;
    }
}

void imprimeInicio(Lista lista) {

    if(listaVazia(lista) == 1) {
        printf("A lista está vazia.\n");
        return;
    }
    else {
        printf("Lista de tamanho %d: ", lista.tamanho);
        while(lista.primeiro != NULL) {
            printf("%d  ", lista.primeiro->item.valor);
            lista.primeiro = lista.primeiro->prox;
        }
        printf("\n"); 
    } 
}

void imprimeFim(Lista lista) {

    if(listaVazia(lista) == 1) {
        printf("A lista está vazia.\n");
        return;
    }
    else {
        printf("Lista de tamanho %d: ", lista.tamanho);
        while(lista.ultimo != NULL) {
            printf("%d  ", lista.ultimo->item.valor);
            lista.ultimo = lista.ultimo->ant;
        }
        printf("\n"); 
    } 
}

void libera(Lista *lista) {
    No *aux = (No*) malloc(sizeof(No));

    if(listaVazia(*lista) == 1) {
        printf("A lista está vazia. Impossível de desalocar a memória.\n");
        return;
    }
    else {
        aux = lista->primeiro;
        while(aux != NULL) {
            aux = aux->prox;
            free(aux->ant);
        }
    }
}