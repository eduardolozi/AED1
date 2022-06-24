#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
    fila->negativo = 0;
}

void criaPilha(Pilha *pilha){
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
}

void insereFila(Fila *fila, int num){
    No *aux = (No*)malloc(sizeof(No));

    aux->item.num = num;
    if(num < 0) {
        fila->negativo++;
    }
    if(fila->primeiro == NULL) {
        fila->primeiro = aux;
        fila->ultimo = aux;
        aux->prox = NULL;
    }
    else {
        fila->ultimo->prox = aux;
        fila->ultimo = aux;
        aux->prox = NULL;
    }
    fila->tamanho++;
}

void inserePilha(Pilha *pilha, int num){
    No *aux = (No*)malloc(sizeof(No));

    aux->item.num = num;
    if(pilha->primeiro == NULL) {
        pilha->primeiro = aux;
        pilha->ultimo = aux;
        aux->prox = NULL;
    }
    else {
        aux->prox = pilha->primeiro;
        pilha->primeiro = aux;
    }
}

void imprimeFila(Fila fila){
    if(fila.primeiro == NULL) printf("A fila está vazia.\n");
    else {
        while(fila.primeiro != NULL) {
            printf("%d ", fila.primeiro->item.num);
            fila.primeiro = fila.primeiro->prox;
        }
        printf("\n");
    }
}

void imprimePilha(Pilha pilha){
    if(pilha.primeiro == NULL) printf("A pilha está vazia.\n");
    else {
        while(pilha.primeiro != NULL) {
            printf("%d ", pilha.primeiro->item.num);
            pilha.primeiro = pilha.primeiro->prox;
        }
        printf("\n");
    }
}

int removeElementoFila(Fila *fila){
    No *aux = (No*)malloc(sizeof(No));
    int numero=0;
    if(fila->primeiro == NULL) printf("A fila está vazia.\n");
    else {
        numero = fila->primeiro->item.num;
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->prox;
        free(aux);
        fila->tamanho--;
        fila->negativo--;
    }
    return numero;
}

void liberaFila(Fila *fila){
    No *aux = (No*)malloc(sizeof(No));
    aux = fila->primeiro;
    while(aux != NULL) {
        fila->primeiro = fila->primeiro->prox;
        free(aux);
        aux = fila->primeiro;
    }
}

void liberaPilha(Pilha *pilha){
    No *aux = (No*)malloc(sizeof(No));
    aux = pilha->primeiro;
    while(aux != NULL) {
        pilha->primeiro = pilha->primeiro->prox;
        free(aux);
        aux = pilha->primeiro;
    }
}