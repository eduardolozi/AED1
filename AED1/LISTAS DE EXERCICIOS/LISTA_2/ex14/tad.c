#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

void insereElemento(Fila *fila, char *nome, int id) {
    No *aux = (No*) malloc(sizeof(No));
    int i=0;

    aux->item.id = id;

    while(nome[i] != '\0') {
        aux->item.nome[i] = nome[i];
        i++;
    }
    aux->item.nome[i] = '\0';
    
    if(fila->tamanho == 0) {
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

void tamanhoFila(Fila fila) {
    printf("-------------------------");
    printf("\nTAMANHO DA FILA: %d\n", fila.tamanho);
    printf("-------------------------\n");
}

void removePrimeiro(Fila *fila) {
    No *aux = (No*)malloc(sizeof(No));
    aux = fila->primeiro;
    printf("----------------------------------------\n");
    if(fila->primeiro == NULL) {
        printf("ERRO: A fila está vazia.\n");
    }
    else if(fila->primeiro->prox == NULL) {
        printf("AVIAO %s(%d) DECOLOU.\n", fila->primeiro->item.nome, fila->primeiro->item.id);
        printf("----------------------------------------\n");
        free(aux);
        fila->primeiro = NULL;
        fila->ultimo = NULL;
        fila->tamanho = 0;
        return;
    }
    else {
        printf("AVIAO %s(%d) DECOLOU.\n", fila->primeiro->item.nome, fila->primeiro->item.id);
        free(aux);
        fila->primeiro = fila->primeiro->prox;
        printf("AGORA O PRIMEIRO AVIÃO DA FILA É O: %s(%d).\n", fila->primeiro->item.nome, fila->primeiro->item.id);
    }
    printf("----------------------------------------\n");
    fila->tamanho--;
}

void imprimePrimeiro(Fila fila) {
    printf("-------------------------\n");
    printf("%s(%d)\n", fila.primeiro->item.nome, fila.primeiro->item.id);
    printf("-------------------------\n");
}

void imprime(Fila fila) {
    printf("---------------- FILA DE DECOLAGEM ------------------\n");
    if(fila.tamanho == 0) {
        printf("A fila está vazia.\n");
        printf("-------------------------\n");
    }
    else {
        while(fila.primeiro != NULL) {
            printf("NOME: %s\nID: %d\n", fila.primeiro->item.nome, fila.primeiro->item.id);
            printf("-------------------------\n");
            fila.primeiro = fila.primeiro->prox;
        }
    }
}

void libera(Fila *fila) {
    No *aux = (No*)malloc(sizeof(No));

    aux = fila->primeiro;
    while(aux != NULL) {
        fila->primeiro = fila->primeiro->prox;
        free(aux);
        aux = fila->primeiro;
    }

    if(aux == NULL) {
        printf("\nMemória desalocada com sucesso.\n");
    }
    else {
        printf("\nErro ao desalocar memória.\n");
    }
}