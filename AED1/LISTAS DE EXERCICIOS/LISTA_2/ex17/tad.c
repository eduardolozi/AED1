#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaPilha(Pilha *pilha) {
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
    pilha->somatorio = 0;
    pilha->tamanho = 0;
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
    pilha->somatorio = pilha->somatorio + (float)aux->item.num;
    pilha->tamanho++;
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
        return 0;
    }
    else {
        No *aux = (No*)malloc(sizeof(No));
        aux = pilha->primeiro;
        pilha->primeiro = pilha->primeiro->prox;
        numero = aux->item.num;
        free(aux);
    }
    pilha->somatorio = pilha->somatorio - (float)numero;
    pilha->tamanho--;
    return numero;
}

void maiorNum(Pilha pilha) {
    int maior;
    maior = pilha.primeiro->item.num;
    pilha.primeiro = pilha.primeiro->prox;
    while(pilha.primeiro != NULL) {
        if(pilha.primeiro->item.num > maior) maior = pilha.primeiro->item.num;
        pilha.primeiro = pilha.primeiro->prox;
    }

    printf("MAIOR ELEMENTO: %d\n", maior);
}

void menorNum(Pilha pilha) {
    int menor;
    menor = pilha.primeiro->item.num;
    pilha.primeiro = pilha.primeiro->prox;
    while(pilha.primeiro != NULL) {
        if(pilha.primeiro->item.num < menor) menor = pilha.primeiro->item.num;
        pilha.primeiro = pilha.primeiro->prox;
    }

    printf("MENOR ELEMENTO: %d\n", menor);
}

void mediaArit(Pilha pilha) {
    pilha.media = pilha.somatorio / pilha.tamanho;
    printf("MÉDIA ARITMÉTICA: %.2f\n", pilha.media);
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