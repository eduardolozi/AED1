#include <stdio.h>
#include <stdlib.h>
#include "listasencadeadas.h"

void insereElementoInicio(No **lista, int x) {
    No *novo = malloc(sizeof(No));  //aloca memoria para o novo elemento.

    if(novo != NULL) {
        novo->valor = x;

        novo->proximo = *lista; // *lista tem o endereço de memoria do inicio da lista, portanto aqui novo->proximo     aponta para o endereço daquele elemento que era o primeiro da lista antes.

        *lista = novo; // atualizamos o endereço que o ponteiro lista ira apontar, ja que novo se tornou o primeiro elemento da lista.
    } 
    else {
        printf("Erro ao alocar memória.\n");
    }
}

void insereElementoFinal(No **lista, int x) {
    No *aux, *novo = malloc(sizeof(No));  //aloca memoria para o novo elemento.

    if(novo!=NULL) {
        novo->valor = x;
        novo->proximo = NULL; //ele aponta para NULL pois vai ser o último elemento da lista.

        if(*lista==NULL) { // isso quer dizer que se o valor de *lista for NULL, então a lista está vazia.
            *lista = novo;
        }
        else {
            //No *aux = malloc(sizeof(No)); // vamos criar para que ele percorra a lista sem modificá-la.
            aux = *lista; //aux vai receber o conteudo de lista
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo; // quando o aux->proximo ja é o NULL, entao ele vai passar a apontar para o novo elemento
        }
    }
    else printf("Erro ao alocar memória.\n");
}


void insereElementoMeio(No **lista, int x, int ant) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo != NULL) {
        novo->valor = x;
        if(*lista == NULL) { // caso a lista esteja vazia.
            novo->proximo = NULL;
            *lista = novo; 
        }
        else {
            //No *aux = malloc(sizeof(No));
            aux = *lista;

            while((aux->valor != ant) && (aux->proximo != NULL)) { // se um desses ocorrer, o loop quebra. 
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo; //temos que apontar para o prox do elemento anterior para nao perder ele.
            aux->proximo = novo; //agora o aux vai estar apontando para o novo elemento inserido. 
        }
    }
    else printf("Erro ao alocar memória.\n");
}

void insereOrdenado(No **lista, int x) {
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if(novo) {
        novo->valor = x;
        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor) {
                novo->proximo = *lista;
                *lista = novo;
        }
        else {
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else printf("Erro ao alocar memória.\n");
}

void removeElemento(No **lista, int x) {
    No *aux = NULL;
    No *remover = NULL;

    if(*lista == NULL) {
        printf("Erro: lista vazia.\n");
        return;
    }
    else {
        aux = *lista;
        if(x == (*lista)->valor) {
            remover = *lista;
            *lista = remover->proximo;
        }
        else {
            while(aux->proximo && x != aux->proximo->valor) {
                aux = aux->proximo;    
            }
            if(aux->proximo) {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
            else {
                printf("O número não se encontra na lista.\n");
            }
        }   
    }

    if(remover != NULL) { // tem que ser diferente de NULL pq quer dizer que foi encontrado um elemento na lista
        printf("O número %d foi removido.\n", remover->valor);
        free(remover);
    }

}

void busca(No **lista, int x) {
    No *aux = malloc(sizeof(No));

    if(*lista) {
        if(x == (*lista)->valor) {
            printf("O número %d foi encontrado.\n", x);
        }
        else {
            aux = *lista;
            while(aux->proximo && x != aux->proximo->valor) {
                aux = aux->proximo;
            }
            if(aux->proximo) {
                printf("O número %d foi encontrado.\n", x);
            }
            else {
                printf("O número %d não está presente na lista.\n", x);
            }
        }
    }
    else {
        printf("A lista está vazia.\n");
    }
}


void imprimir(No *lista) {
    printf("\nLista: ");

    while(lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }

    printf("\n");
}


