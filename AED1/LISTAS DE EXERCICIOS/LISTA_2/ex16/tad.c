#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaPilha(Pilha *pilha) {
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
}

void insere(Pilha *pilha, int num) {
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

void imprime(Pilha pilha) {
    if(pilha.primeiro == NULL) {
        printf("A pilha está vazia.\n");
    }
    else {
        while(pilha.primeiro != NULL) {
            printf("%d\n", pilha.primeiro->item.num);
            pilha.primeiro = pilha.primeiro->prox;
        }
    }
}

int retira(Pilha *pilha) {
    int numero;
    if(pilha->primeiro == NULL) {
        numero = 0;
    }
    else {
        No *aux = (No*)malloc(sizeof(No));
        aux = pilha->primeiro;
        pilha->primeiro = pilha->primeiro->prox;
        numero = aux->item.num;
        free(aux);
    }

    return numero;
}

void libera(Pilha *pilha){
    No *aux = (No*)malloc(sizeof(No));
    aux = pilha->primeiro;
    while(aux != NULL) {
        pilha->primeiro = pilha->primeiro->prox;
        free(aux);
        aux = pilha->primeiro;
    }
    if(aux == NULL) {
        printf("Memória desalocada com sucesso.\n");
    }
    else {
    printf("Erro ao desalocar a memória.\n");
    }
}
        printf("Erro ao desalocar a memória.\n");
    }
}
