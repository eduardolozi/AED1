#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaPilha(Pilha *pilha) {
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
    pilha->tamanho = 0;
}

void insere(Pilha *pilha, char letra) {
    No *aux = (No*)malloc(sizeof(No));

    aux->item.letra = letra;
    if(pilha->primeiro == NULL) {
        pilha->primeiro = aux;
        pilha->ultimo = aux;
        aux->proximo = NULL;
    }
    else {
        aux->proximo = pilha->primeiro;
        pilha->primeiro = aux;
    }
    pilha->tamanho++;
}

void palindromo(Pilha pilha) {
    int tamanho = pilha.tamanho;
    int i;
    No *aux = (No*)malloc(sizeof(No));
    char vetor[tamanho];
    int metade = tamanho/2;
    int cont = 0;

    if(tamanho%2==0) {
        for(i=0;i<(tamanho/2);i++) {
            vetor[i] = pilha.primeiro->item.letra;
            pilha.primeiro = pilha.primeiro->proximo;
        }
        for(i=(tamanho/2);i<tamanho;i++) {
            vetor[i] = pilha.primeiro->item.letra;
            pilha.primeiro = pilha.primeiro->proximo;
        }

        int aux = tamanho-1;
        for(i=0;i<metade;i++) {
            if(vetor[i] == vetor[aux-i]) cont++;
        }
        if(cont==metade) {
            printf("A PILHA É UM PALÍNDROMO.\n");
            return;
        }
        else {
            printf("A PILHA NÃO É UM PALÍNDROMO.\n");
            return;
        }
    }
    else {
        for(i=0;i<(tamanho/2);i++) {
            vetor[i] = pilha.primeiro->item.letra;
            pilha.primeiro = pilha.primeiro->proximo;
        }
        vetor[metade] = pilha.primeiro->item.letra;
        pilha.primeiro = pilha.primeiro->proximo;
        for(i=((tamanho/2)+1);i<tamanho;i++) {
            vetor[i] = pilha.primeiro->item.letra;
            pilha.primeiro = pilha.primeiro->proximo;
        }

        int aux = tamanho-1;
        for(i=0;i<metade;i++) {
            if(vetor[i] == vetor[aux-i]) cont++;
        }
        if(cont==metade) {
            printf("A PILHA É UM PALÍNDROMO.\n");
            return;
        }
        else {
            printf("A PILHA NÃO É UM PALÍNDROMO.\n");
            return;
        }
    }
}

void imprime(Pilha pilha) {
    if(pilha.primeiro == NULL) {
        printf("A pilha está vazia.\n");
    }
    else {
        while(pilha.primeiro != NULL) {
            printf("%c\n", pilha.primeiro->item.letra);
            pilha.primeiro = pilha.primeiro->proximo;
        }
    }
}

void libera(Pilha *pilha) {
    No *aux = (No*)malloc(sizeof(No));

    aux = pilha->primeiro;
    while(aux != NULL) {
        pilha->primeiro = pilha->primeiro->proximo;
        free(aux);
        aux = pilha->primeiro;
    }
    if(aux == NULL) {
        printf("\nMemória desalocada com sucesso.\n");
    }
    else {
        printf("\nErro ao desalocar a memória.\n");
    }
}