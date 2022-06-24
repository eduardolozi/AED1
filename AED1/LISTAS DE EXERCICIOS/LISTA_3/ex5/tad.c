#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#define NMAX 500

void init(Lista *lista1, Lista *lista2) {
    lista1->list[0].tamanho = 0;
    lista2->list[1].tamanho = 0;

    if(lista1->list[0].tamanho == 0 && lista2->list[1].tamanho == 0) printf("Listas inicializadas com sucesso.\n");
    else printf("Erro ao inicializar listas.\n");
}

void insereElemento(Lista *lista, int num) {
    
    if(lista->list[0].tamanho >= NMAX) {
        printf("ERRO: Lista cheia.\n");
        return;
    }
    lista->list[0].item[lista->list[0].tamanho].numero = num;
    lista->list[0].tamanho++;
}

int buscaSeq(Lista lista, int num, Lista *listaPos) {
    int cont = 0;
    int i, j, sentinela;

    if(lista.list[0].tamanho == 0) {
        return -1;
    }
    sentinela = num;
    for(i=lista.list[0].tamanho-1;i>=0;i--) {
        if(lista.list[0].item[i].numero == sentinela) {
            cont++;
            listaPos->list[1].item[listaPos->list[1].tamanho].numero = i+1; //colocamos na Lista com as posições, a posiçao em que o numero foi encontrado
            listaPos->list[1].tamanho++;
        }
    }
    return cont;//retorna o numero de vezes que o numero foi encontrado

}

int buscaBin(Lista lista, int num, Lista *listaPos) {
    int esq, dir, meio, cont = 0;

    if(lista.list[0].tamanho == 0) {
        return -1;
    }
    else {
        esq = 0;
        dir = lista.list[0].tamanho - 1;
        do {
            meio = (esq + dir) / 2;
            if(num > lista.list[0].item[meio].numero) {
                esq = meio + 1;
            }
            else {
                dir = meio - 1;
            }
            if(num == lista.list[0].item[meio].numero) {
                cont++;
                listaPos->list[1].item[listaPos->list[1].tamanho].numero = meio+1;
                listaPos->list[1].tamanho++;
            }
        }while(esq <= dir);
    }
    return cont;
}

void insertionSordLista1(Lista *lista) {
    int i, j, aux, aux2;

    for(i=1;i<lista->list[0].tamanho;i++) {
        aux2 = i; //essa variavel vai pegar o valor de i para conseguir manusear o indice dentro do proximo loop

        for(j=i-1;j>=0;j--) { //percorremos o vetor em direçao da esquerda para ver se esxitem valores maiores que o valor da posicao i
            if(lista->list[0].item[aux2].numero < lista->list[0].item[j].numero) {  //se o valor à esquerda for maior, ocorre uma troca
                aux = lista->list[0].item[aux2].numero;
                lista->list[0].item[aux2].numero = lista->list[0].item[j].numero;
                lista->list[0].item[j].numero = aux;
            }
            else break; //se o valor a esquerda não for maior, entao quebra o loop
            aux2--; //aqui atualizamos o novo indice que o valor vai ocupar na lista, por ex: se estivesse na 3a e tivesse ido para a 2a
        }
        
    }
}

void imprimeLista1(Lista lista) {
    int i;
    if(lista.list[0].tamanho == 0) {
        printf("ERRO: Lista Vazia.\n");
        return;
    }
    printf("\n-----------LISTA 1-----------\n");  
    for(i=0;i<lista.list[0].tamanho;i++) {
        printf("%d ", lista.list[0].item[i].numero);
    }
    printf("\n");
}

void insertionSordLista2(Lista *lista) {
    int i, j, aux, aux2;

    for(i=1;i<lista->list[1].tamanho;i++) {
        aux2 = i; //essa variavel vai pegar o valor de i para conseguir manusear o indice dentro do proximo loop

        for(j=i-1;j>=0;j--) { //percorremos o vetor em direçao da esquerda para ver se esxitem valores maiores que o valor da posicao i
            if(lista->list[1].item[aux2].numero < lista->list[1].item[j].numero) {  //se o valor à esquerda for maior, ocorre uma troca
                aux = lista->list[1].item[aux2].numero;
                lista->list[1].item[aux2].numero = lista->list[1].item[j].numero;
                lista->list[1].item[j].numero = aux;
            }
            else break; //se o valor a esquerda não for maior, entao quebra o loop
            aux2--; //aqui atualizamos o novo indice que o valor vai ocupar na lista, por ex: se estivesse na 3a e tivesse ido para a 2a
        }
        
    }
}

void imprimeLista2(Lista lista) {
    int i;
    if(lista.list[1].tamanho == 0) {
        printf("ERRO: Lista Vazia.\n");
        return;
    }
    printf("\n-----------LISTA 2-----------\n");
    for(i=0;i<lista.list[1].tamanho;i++) {
        printf("%d ", lista.list[1].item[i].numero);
    }
    printf("\n");
}