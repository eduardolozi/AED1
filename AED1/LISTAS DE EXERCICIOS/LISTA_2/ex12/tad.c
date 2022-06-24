#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaFila(Fila *fila) {
    fila->inicio = NULL;
    fila->final = NULL;
    fila->tamanho=0;
}

void enfileira(Fila *fila, int num, int prioridade) {
    No *aux = (No*) malloc(sizeof(No));

    aux->item.valor = num;
    aux->item.prioridade = prioridade;
    if(fila->inicio == NULL) {
        fila->inicio = aux;
        fila->final = aux;
        aux->prox = NULL;
    }
    else {
        fila->final->prox = aux;
        fila->final = aux;
        aux->prox = NULL;
    }
    fila->tamanho++;
}

void imprime(Fila fila) {
    No *aux = (No*) malloc(sizeof(No));

    printf("\nA fila será impressa no seguinte formato:\nElemento (Prioridade)\n.\n.\n.\n");
    printf("\nFila: \n");
    while(fila.inicio != NULL) {
        printf("%d (%d)\n", fila.inicio->item.valor, fila.inicio->item.prioridade);
        fila.inicio = fila.inicio->prox;
    }
}

void insere(Fila **fila, int num, int prioridade) {
    No *aux = (No*) malloc(sizeof(No));

    aux->item.valor = num;
    aux->item.prioridade = prioridade;
    if((*fila)->inicio == NULL) {
        (*fila)->inicio = aux;
        (*fila)->final = aux;
        aux->prox = NULL;
    }
    else {
        (*fila)->final->prox = aux;
        (*fila)->final = aux;
        aux->prox = NULL;
    }
    (*fila)->tamanho++;
}

void divideFilas(Fila f1, Fila *f2, Fila *f3, int base) {
    No *aux = (No*) malloc(sizeof(No));
    int cont=0, i;
    int aux1=0;
    int aux2=0;

    aux = f1.inicio;
    while(aux != NULL) {
        if(aux->item.prioridade >= base) cont++;
        aux = aux->prox;
    }

    TipoItem vetorMIP[cont]; //menor ou igual prioridade
    int tam = f1.tamanho - cont;
    TipoItem vetorMP[tam]; //maior prioridade

    while(f1.inicio != NULL) {
        if(f1.inicio->item.prioridade >= base) {
            vetorMIP[aux1].valor = f1.inicio->item.valor;
            vetorMIP[aux1].prioridade = f1.inicio->item.prioridade;
            aux1++;
        }
        else {
            vetorMP[aux2].valor = f1.inicio->item.valor;
            vetorMP[aux2].prioridade = f1.inicio->item.prioridade;
            aux2++;
        }
        f1.inicio = f1.inicio->prox;
    }

    for(i=0;i<aux1;i++) {
        insere(&f2, vetorMIP[i].valor, vetorMIP[i].prioridade);
    }
    
    for(i=0;i<aux2;i++) {
        insere(&f3, vetorMP[i].valor, vetorMP[i].prioridade);
    }

}


void libera(Fila *fila) {
    No *aux = (No*) malloc(sizeof(No));
    aux = fila->inicio;
    while(aux != NULL) {
        fila->inicio = fila->inicio->prox;
        free(aux);
        aux = fila->inicio;
    }

    if(aux == NULL) printf("A memória foi desalocada com sucesso.\n");
    else printf("Erro ao desalocar a memória.\n");
}