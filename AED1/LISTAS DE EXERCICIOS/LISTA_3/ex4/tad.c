#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void init(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
    if(lista->inicio == lista->fim) printf("Lista criada com sucesso.\n");
    else printf("Erro ao criar lista.\n");
}

void insereElementoFim(Lista *lista, int mat, float nota) {
    No* aux = (No *)malloc(sizeof(No));

    aux->item.matricula = mat;
    aux->item.nota = nota;
    if(lista->tam == 0) {
        lista->inicio = aux;
        lista->fim = aux;
        aux->proximo = NULL;
    }
    else {
        lista->fim->proximo = aux;
        lista->fim = aux;
        aux->proximo = NULL;
    }
    lista->tam++;
}

void imprimeLista(Lista lista) {
    int i;
    if(lista.tam == 0) {
        printf("ERRO: Lista vazia.\n");
        return;
    }
    for(i=0;i<lista.tam;i++) {
        printf("MATRICULA: %u   NOTA: %.2f\n", lista.inicio->item.matricula, lista.inicio->item.nota);
        lista.inicio = lista.inicio->proximo;
    }
}

void libera(Lista *lista) {
    No *aux = (No *)malloc(sizeof(No));
    aux = lista->inicio;
    while(aux != NULL) {
        lista->inicio = lista->inicio->proximo;
        free(aux);
        aux = lista->inicio;
    }
    if(aux == NULL) printf("Memória desalocada com sucesso.\n");
    else printf("ERRO: Desalocação falhou.\n");
}