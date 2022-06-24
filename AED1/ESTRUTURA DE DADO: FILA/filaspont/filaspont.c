#include<stdio.h>
#include<stdlib.h>
#include"filaspont.h"

int criaFila(Fila* fila) {
    fila->frente=NULL;
    fila->tras=fila->frente;
    if(fila->frente == NULL && fila->tras == fila->frente) return 1;
    else return 0;
}

int filaVazia(Fila* fila){
    return(fila->frente == NULL);
}

void enfileira(Fila* fila, int x) {
    TipoApontador novo = (TipoApontador) malloc(sizeof(TipoApontador));
    novo->item = x;
    novo->prox = NULL;
    if(filaVazia(fila) == 1) {
        fila->frente = novo;
    }
    else {
        fila->tras->prox = novo;
    }
    fila->tras = novo;
    return;
}

void desenfileira(Fila* fila) {
    if(fila->frente == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    TipoApontador q;
    q = fila->frente;
    fila->frente = fila->frente->prox;
    free(q);
    if(fila->frente == NULL) {
        fila->tras = NULL;
    }
}

void imprime(Fila fila) {
    TipoApontador aux;
    aux = fila.frente;
    while(aux != NULL) {
        printf("%d\n", aux->item);
        aux = aux->prox;
    }
}

void libera(Fila* fila) {
    TipoApontador q;
    while(fila->frente != NULL) {
        q = fila->frente;
        fila->frente = fila->frente->prox;
        free(q);
    }
}

