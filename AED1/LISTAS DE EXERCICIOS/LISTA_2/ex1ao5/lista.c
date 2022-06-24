#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAXTAM 1000

void criaLista(Lista* lista) {
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
    if(lista->ultimo == lista->primeiro && lista->primeiro == 0) printf("Lista criada com sucesso!\n");
    else printf("Erro ao criar lista.\n");
}

void insereElemento(Lista* lista, int x){
    if(lista->ultimo>=MAXTAM) return;
    lista->item[lista->ultimo] = x;
    lista->ultimo++;
}

void printLista(Lista* lista) {
    int i;
    for(i=0;i<lista->ultimo;i++) {
        printf("%d ", lista->item[i]);
    }
    printf("\n");
}

Lista concatenaListas(Lista* l1, Lista* l2) {
    int i;
    Lista l3;
    l3.ultimo=0;
    l3.primeiro=l3.ultimo;
    for(i=0;i<l1->ultimo;i++) {
        l3.item[l3.ultimo] = l1->item[i];
        l3.ultimo++;
    }
    for(i=0;i<l2->ultimo;i++) {
        l3.item[l3.ultimo] = l2->item[i];
        l3.ultimo++;
    }

    return l3;

}

int retiraElementos(Lista* lista, int x) {
    int i, aux;
    if(x>lista->ultimo) return 0;
    else {
        if(x<=lista->ultimo) {
            if(x<lista->ultimo) lista->ultimo = (lista->ultimo) - (x);
            else {
                lista->ultimo=lista->primeiro-1;
                return 1;
            }
            for(i=0;i<lista->ultimo;i++) {
                lista->item[i] = lista->item[x];
                x++;
            }
            return 1;
        }
    }
}

int buscaMaior(Lista* lista) {
    int i=0;
    int cont = 0;
    lista->maior = lista->item[0];
    for(i=0;i<lista->ultimo;i++) {
        if(lista->item[i] > lista->maior) {
            lista->maior = lista->item[i];
            lista->posicaoMaior = i+1;
        }
    }
    for(i=0;i<lista->ultimo;i++) {
        if(lista->maior >= lista->item[i]) cont++;
    }
    if(cont == lista->ultimo) {
        return 1;
    }
    else return 0;
}


int totParesLista(Lista* lista) {
    int i, totpar = 0;
    if(lista->ultimo < lista->primeiro) return totpar;
    for(i=0;i<lista->ultimo;i++) {
        if(lista->item[i] % 2 == 0) totpar++;
    }
    return totpar;
}

float mediaLista(Lista* lista) {
    int i, soma = 0;
    float media;
    if(lista->ultimo < lista->primeiro) return 0.0;
    for(i=0;i<lista->ultimo;i++) {
        soma += lista->item[i];
    }
    return media = (float)soma/lista->ultimo;
}