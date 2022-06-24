#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>
#define NMAX 500

void init(No *pessoa) {
    pessoa->primeiro = 0;
    pessoa->ultimo = 0;
    pessoa->tamanho = 0;
    if(pessoa->primeiro == 0 && pessoa->ultimo == 0 && pessoa->tamanho == 0) printf("Lista inicializada com sucesso.\n");
    else printf("Erro ao inicializar lista.\n");
}

void insereNome(No *pessoa, char *nome) {
    int tam = strlen(nome);
    int i=0;

    if(pessoa->tamanho >= NMAX) {
        printf("ERRO: Lista cheia.\n");
        return;
    }
    pessoa->item[pessoa->tamanho].nome = (char *)malloc(tam * sizeof(char));
    while(nome[i] != '\0') {
        pessoa->item[pessoa->tamanho].nome[i] = nome[i];
        i++;
    }
    pessoa->item[pessoa->tamanho].nome[i] = '\0';
    pessoa->tamanho++;
    pessoa->ultimo = pessoa->tamanho;
}

void selectionSort(No *pessoa) {
    int i, j, menor, auxJ, auxM;
    TipoItem temp;

    for(i=0;i<(pessoa->tamanho-1);i++) { //percorre ate o penultimo elemento
        menor = i;
        auxM = strlen(pessoa->item[menor].nome);
        for(j=i+1;j<(pessoa->tamanho);j++) { //percorre ate o ultimo elemento
            auxJ = strlen(pessoa->item[j].nome);
            if(auxJ < auxM) {
                menor = j;
                auxM = strlen(pessoa->item[menor].nome); //atualizamos o valor da variavel com a nova qtd de caracteres do novo menor nome
            }
        }

        if(i != menor) {
            temp = pessoa->item[i];
            pessoa->item[i] = pessoa->item[menor];
            pessoa->item[menor] = temp;
        }
    }
}

void insertionSort(No *pessoa) {
    int aux, i, j, qtdJ, qtdA;
    TipoItem temp;

    for(i=1;i<pessoa->tamanho;i++) {
        aux = i;
        for(j=i-1;j>=0;j--) {
            qtdA = strlen(pessoa->item[aux].nome);
            qtdJ = strlen(pessoa->item[j].nome);
            if(qtdJ > qtdA) {
                temp = pessoa->item[j];
                pessoa->item[j] = pessoa->item[aux];
                pessoa->item[aux] = temp;
            }
            else break;
            aux--;
        }
    }
}

void imprimeLista(No pessoa) {
    int i;
    if(pessoa.tamanho == 0) {
        printf("ERRO: Lista Vazia.\n");
        return;
    }
    printf("\n--------------LISTA DE NOMES--------------\n");
    for(i=0;i<pessoa.tamanho;i++) {
        printf("%s\n", pessoa.item[i].nome);
    }
}