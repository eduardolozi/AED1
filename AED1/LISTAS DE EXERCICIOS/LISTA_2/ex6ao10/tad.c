#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void criaLista(Lista *lista) {
    lista->inicio = NULL;
    lista->final = lista->inicio;
    lista->tam=0;
}

void criaListaVetor(Lista *lista, int *vetor, int tamanho) {
    int i;
    for(i=0;i<tamanho;i++) {
        No *aux = (No *) malloc(sizeof(No));
        aux->item.chave = vetor[i];
        if(lista->inicio ==  NULL) {
            lista->inicio = aux;
            lista->final = aux;
            aux->prox =  NULL;
        }
        else {
            lista->final->prox = aux;
            lista->final = aux;
            aux->prox = NULL;
        }
    }
    lista->tam = tamanho;
}


void excluiRepetidos(Lista *lista) {
    No *aux = (No *) malloc(sizeof(No));
    int i=0, j, c, cont = 0, t, novo, temp;
    int tamanho = lista->tam;
    int vetor[tamanho];

    if(lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    aux = lista->inicio;
    while(aux) {
        vetor[i] = aux->item.chave;
        i++;
        lista->inicio = lista->inicio->prox;
        aux = lista->inicio;
    }

    for(j=0;j<i;j++){
        for(c=j+1;c<i;c++) {
            if(vetor[j] == vetor[c]) {
                cont++;
                for(t=c+1;t<i;t++) {
                    temp = vetor[t];
                    vetor[t] = vetor[t-1];
                    vetor[t-1] = temp;
                }
            }
        }
    }

    novo = i - (cont/2);

    for(i=0;i<novo;i++) {
        No *aux = (No *) malloc(sizeof(No));
        aux->item.chave = vetor[i];
        if(lista->inicio ==  NULL) {
            lista->inicio = aux;
            lista->final = aux;
            aux->prox =  NULL;
        }
        else {
            lista->final->prox = aux;
            lista->final = aux;
            aux->prox = NULL;
        }
    }
}

void insere(Lista **lista, int num){
    No *aux = (No*) malloc(sizeof(No));

    if((*lista)->inicio == NULL) {
        aux->item.chave = num;
        (*lista)->inicio = aux;
        (*lista)->final = aux;
    }
    else {
        aux->item.chave = num;
        (*lista)->final->prox = aux;
        (*lista)->final = aux;
        aux->prox = NULL;
    }
}

void concatena(Lista l1, Lista l2, Lista *l3) {
    while(l1.inicio) {
        insere(&l3, l1.inicio->item.chave);
        l1.inicio = l1.inicio->prox;
    }
    while(l2.inicio) {
        insere(&l3, l2.inicio->item.chave);
        l2.inicio = l2.inicio->prox;
    }
    l3->tam = l1.tam + l2.tam;
}

void intercala(Lista l1, Lista l2, Lista *l4) {
    int i = l1.tam;
    int j = l2.tam;
    int tot = j+i, maior, aux, menor;
    int vetor1[i], vetor2[j], vetor3[tot];
    int cont;

    for(cont=0;cont<i;cont++) {
        vetor1[cont] = l1.inicio->item.chave;
        l1.inicio = l1.inicio->prox;
    }
    for(cont=0;cont<j;cont++) {
        vetor2[cont] = l2.inicio->item.chave;
        l2.inicio = l2.inicio->prox;
    }

    if(j > i) maior = j;
    else maior = i;

    aux=0;
    for(cont=0;cont<maior;cont++) {
        if(i>=cont+1) {
            vetor3[aux] = vetor1[cont];
            aux++;
        }

        if(j>=cont+1) {
            vetor3[aux] = vetor2[cont];
            aux++;
        }
    }

    for(i=0;i<tot;i++) {
        insere(&l4, vetor3[i]);
    }

    l4->tam = l1.tam + l2.tam;
}


void imprime(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    
    while(lista.inicio != NULL) {
        printf("%d ", lista.inicio->item.chave);
        lista.inicio = lista.inicio->prox;
    }
    printf("\n");
}

int somaLista(Lista lista) {
    int soma = 0;
    while(lista.inicio) {
        soma = lista.inicio->item.chave + soma;
        lista.inicio = lista.inicio->prox;
    }

    return soma;
}

void liberaLista(Lista *lista) {
    if(lista->inicio ==  NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    
    No *aux = (No *) malloc(sizeof(No));
    aux = lista->inicio;
    while(aux != NULL) {
        lista->inicio = lista->inicio->prox;
        free(aux);
        aux = lista->inicio;
    }

    if(aux == NULL) {
        printf("Memória desalocada com sucesso.\n");
    }
    else {
        printf("Erro ao desalocar a memória.\n");
    }
}