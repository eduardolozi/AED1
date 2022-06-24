// Eduardo Lozano Azevedo 202103718

#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int criaLista(Lista* lista) {
    lista->primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->cont = 0;
    if(lista->primeiro != NULL) return 1;
    else return 0;
}

int maximo(Lista* lista) {
    if(lista->cont < lista->max) return 0;
    else return 1;
}

void insere(Lista* lista, char x[], int max) {
    int controle;
    if(lista->primeiro==lista->ultimo) {
        lista->ultimo->prox = (TipoApontador) malloc(sizeof(TipoCelula));
        lista->ultimo = lista->ultimo->prox;
        for(int i=0;i<6;i++) {
            lista->ultimo->placa[i] = x[i];
        }
        lista->ultimo->prox = NULL;
        lista->cont+=1;
        lista->max = max;
        return;
    }
    else {
        if(maximo(lista) == 0) {
            lista->ultimo->prox = (TipoApontador) malloc(sizeof(TipoCelula));
            lista->ultimo = lista->ultimo->prox;
            for(int i=0;i<6;i++) {
                lista->ultimo->placa[i] = x[i];
            }
            lista->ultimo->prox = NULL;
            lista->cont+=1;
            return;
        } else {
            printf("Capacidade máxima atingida.\n");
            return;
        }
    }
}

int capacidade(Lista* lista) {
    printf("A capacidade da balsa até o momento é de: %d\n", lista->cont);
    if(lista->cont == lista->max) {
        printf("CAPACIDADE TOTAL ATINGIDA. IMPOSSÍVEL COLOCAR MAIS VEÍCULOS NO MOMENTO.\n");
        return 1;
    }

}

void imprime(Lista* lista) {
    TipoApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL) {
        printf("%s\n", aux->placa);
        aux = aux->prox;
    }
}

void retira(Lista* lista, int posicao) {
    TipoApontador q;
    Lista* aux;
    int i=0;

    if(lista->primeiro == lista->ultimo) {
        printf("A lista já está vazia.\n"); // so consegui fazer ate aqui na função retira. // 
        return;
    }

}






