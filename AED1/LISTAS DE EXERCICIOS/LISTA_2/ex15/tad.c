#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

void insere(Fila *fila, int num) {
    No *aux = (No*) malloc(sizeof(No));

    aux->item.num = num;
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

void ordenaCrescente(Fila *fila) {
    No *aux = (No*) malloc(sizeof(No));
    No *aux2 = (No*) malloc(sizeof(No));
    No *temp = (No*) malloc(sizeof(No));

    aux = fila->primeiro;
    while(aux != NULL) {
        aux2 = aux->prox;
        while(aux2 != NULL) {
            if(aux->item.num > aux2->item.num) {
                temp->item.num = aux2->item.num;
                aux2->item.num = aux->item.num;
                aux->item.num = temp->item.num;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
    
}

void insere2(Fila **fila, int num) {
    No *aux = (No*) malloc(sizeof(No));

    aux->item.num = num;
    if((*fila)->primeiro == NULL) {
        (*fila)->primeiro = aux;
        (*fila)->ultimo = aux;
        aux->prox = NULL;
    }
    else {
        (*fila)->ultimo->prox = aux;
        (*fila)->ultimo = aux;
        aux->prox = NULL;
    }
    (*fila)->tamanho++;
}

 void juntaFilas(Fila f1, Fila f2, Fila *f3) {
    int tam1 = f1.tamanho;
    int tam2 = f2.tamanho;
    int tam3 = tam1+tam2;
    int vetor1[tam1], vetor2[tam2];
    int i=0, j=0;

    while(f1.primeiro != NULL) {
        vetor1[i] = f1.primeiro->item.num;
        insere2(&f3, vetor1[i]);
        i++;
        f1.primeiro = f1.primeiro->prox;
    }   

    while(f2.primeiro != NULL) {
        vetor2[j] = f2.primeiro->item.num;
        insere2(&f3, vetor2[j]);
        j++;
        f2.primeiro = f2.primeiro->prox;
    }
} 

void imprime(Fila fila) {
    int cont = 1;
    if(fila.primeiro == NULL) {
        printf("A fila está vazia.\n");
    }
    else {
        while(fila.primeiro != NULL) {
            printf("%d: ", cont);
            printf("%d\n", fila.primeiro->item.num);
            cont++;
            fila.primeiro = fila.primeiro->prox;
        }
    }
}

void libera(Fila *fila) {
    No *aux = (No *) malloc(sizeof(No));

    aux = fila->primeiro;
    while(aux!=NULL) {
        fila->primeiro = fila->primeiro->prox;
        free(aux);
        aux = fila->primeiro;
    }

    if(aux == NULL) {
        printf("Memória desalocada com sucesso.\n");
    }
    else {
        printf("Erro ao desalocar memória.\n");
    }
}

