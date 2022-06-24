#include <stdio.h>
#include <stdlib.h>
#include "listasvet.h"

#define INICIO 1
#define MAXTAM 1000

struct lista {
    int item[1000];
    int primeiro, ultimo;
};

void criaLista(Lista* lista){
    lista->primeiro = INICIO;
    lista->ultimo = lista->primeiro;
}

int listaVazia(Lista* lista) {
    return(lista->primeiro == lista->ultimo);
}

void insereLista(Lista* lista, int x) {
    if(lista->ultimo > MAXTAM) return;
    lista->item[lista->ultimo-1] = x;
    lista->ultimo++;    
}

void retiraLista(Lista* lista, int posicao) {
    int aux, i;
    if(posicao>=lista->ultimo || posicao<0) return;
    else if(listaVazia(lista) == 1) return;
    
    lista->ultimo--;
    for(aux=posicao;aux<lista->ultimo;aux++) {
        lista->item[aux-1] = lista->item[aux];
    }
}

void imprimeLista(Lista* lista) {
    int i;
    if(lista->primeiro == lista->ultimo) return;
    for(i=lista->primeiro-1;i<lista->ultimo-1;i++) {
        printf("%d ", lista->item[i]);
    }
    printf("\n");
}



